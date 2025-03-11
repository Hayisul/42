#!/bin/bash

MAKEFILE=${1:-../Makefile}
if [ ! -f "$MAKEFILE" ]; then
    exit 1
fi
concatenate_vars() {
    awk '
    /^([A-Za-z_][A-Za-z0-9_]*)\s*=/ {
        var_name = $1
        var_value = ""
        sub(/^[A-Za-z_][A-Za-z0-9_]*\s*=\s*/, "", $0)
        var_value = var_value $0
        while (var_value ~ /\\$/) {
            var_value = substr(var_value, 1, length(var_value)-1)
            getline
            var_value = var_value " " $0
        }
        gsub(/^[ \t]+|[ \t]+$/, "", var_value)
        print var_name "=" var_value
    }
    ' "$MAKEFILE"
}
VARIABLES=$(concatenate_vars)
SRC_VAR=$(echo "$VARIABLES" | grep -E "=[^#]*\.c" | head -n1 | cut -d '=' -f1)
if [ -z "$SRC_VAR" ]; then
    exit 1
fi
OBJ_VAR=$(echo "$VARIABLES" | grep -E "^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*\$?\(($SRC_VAR):?[^)]*\)" | \
          sed -E "s/^([A-Za-z_][A-Za-z0-9_]*)\s*=.*/\1/" | head -n1)
if [ -z "$OBJ_VAR" ]; then
    OBJ_VAR=$(echo "$VARIABLES" | grep -E "=[^#]*\.o" | head -n1 | cut -d '=' -f1)
fi
if [ -z "$OBJ_VAR" ]; then
    exit 1
fi
if grep -q "^so:" "$MAKEFILE"; then
    exit 0
fi
OS_TYPE=$(uname)
if [[ "$OS_TYPE" == "Linux" ]]; then
    EXTRA_FLAGS="-nostartfiles"
else
    EXTRA_FLAGS=""
fi
SO_RULE=$(printf "\nso:\n\t\$(CC) -fPIC \$(CFLAGS) ${EXTRA_FLAGS} \$(${SRC_VAR})\n\t\$(CC) -shared -o libft.so \$(${OBJ_VAR})\n")
echo -e "$SO_RULE" >> "$MAKEFILE"
