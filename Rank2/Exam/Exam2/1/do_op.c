/* *************************************************************** */
/*                                                                 */
/*                             DO_OP                               */
/*                                                                 */
/*   Performs a basic arithmetic operation on two integers.        */
/*   The operator can be addition, subtraction, multiplication,    */
/*   division, or modulo. In case of division or modulo by zero,   */
/*   an error message is displayed.                                */
/*                                                                 */
/*   Usage:                                                        */
/*       ./do_op 5 "+" 3                                           */
/*                                                                 */
/*   Example Output:                                               */
/*       8                                                         */
/*                                                                 */
/* *************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly three arguments are provided.
    if (argc == 4) {
        int n1 = atoi(argv[1]);
        int n2 = atoi(argv[3]);
        char op = argv[2][0];
        int res;

        // Determine the operation to perform based on the operator.
        if (op == '+')
            res = n1 + n2;
        else if (op == '-')
            res = n1 - n2;
        else if (op == '*')
            res = n1 * n2;
        else if (op == '/') {
            // Check for division by zero.
            if (n2 == 0) {
                write(1, "Error\n", 6);
                return (0);
            }
            res = n1 / n2;
        }
        else if (op == '%') {
            // Check for modulo by zero.
            if (n2 == 0) {
                write(1, "Error\n", 6);
                return (0);
            }
            res = n1 % n2;
        }
        else {
            // If the operator is not recognized, print a newline.
            write(1, "\n", 1);
            return (0);
        }
        // Print the result followed by a newline.
        printf("%d\n", res);
        return (0);
    }
    else {
        // If the number of arguments is incorrect, print a newline.
        write(1, "\n", 1);
        return (0);
    }
}