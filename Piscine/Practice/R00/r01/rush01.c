#include <unistd.h>
#include <stdlib.h>

int *col_up, *col_down, *row_left, *row_right;
int **grid;

void print_error() {
    write(1, "Error\n", 6);
}

void print_grid() {
    char c;
    int i = 0, j;

    while (i < 4) {
        j = 0;
        while (j < 4) {
            c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j < 3) write(1, " ", 1);
            j++;
        }
        write(1, "$\n", 2);
        i++;
    }
}

int is_valid(int r, int c, int h) {
    int i = 0;
    while (i < 4) {
        if (grid[r][i] == h || grid[i][c] == h) return 0;
        i++;
    }
    return 1;
}

int check_visibility(int line[4], int expected) {
    int max = 0, count = 0, i = 0;
    while (i < 4) {
        if (line[i] > max) {
            max = line[i];
            count++;
        }
        i++;
    }
    return (count == expected);
}

int check_grid() {
    int row[4], col[4], i, j;

    i = 0;
    while (i < 4) {
        j = 0;
        while (j < 4) {
            row[j] = grid[i][j];
            col[j] = grid[j][i];
            j++;
        }
        if (!check_visibility(row, row_left[i])) return 0;
        if (!check_visibility(row + 3, row_right[i])) return 0;
        if (!check_visibility(col, col_up[i])) return 0;
        if (!check_visibility(col + 3, col_down[i])) return 0;
        i++;
    }
    return 1;
}

int solve(int r, int c) {
    if (r == 4) return check_grid();
    if (c == 4) return solve(r + 1, 0);
    
    int h = 1;
    while (h <= 4) {
        if (is_valid(r, c, h)) {
            grid[r][c] = h;
            if (solve(r, c + 1)) return 1;
            grid[r][c] = 0;
        }
        h++;
    }
    return 0;
}

int char_to_int(char c) {
    return c - '0';
}

void parse_input(char *input) {
    int i = 0, j = 0;
    while (i < 4) col_up[i++] = char_to_int(input[j]), j += 2;
    while (i < 8) col_down[i++ - 4] = char_to_int(input[j]), j += 2;
    while (i < 12) row_left[i++ - 8] = char_to_int(input[j]), j += 2;
    while (i < 16) row_right[i++ - 12] = char_to_int(input[j]), j += 2;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_error();
        return 0;
    }

    col_up = (int *)malloc(4 * sizeof(int));
    col_down = (int *)malloc(4 * sizeof(int));
    row_left = (int *)malloc(4 * sizeof(int));
    row_right = (int *)malloc(4 * sizeof(int));
    grid = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++) {
        grid[i] = (int *)malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++) {
            grid[i][j] = 0;
        }
    }

    parse_input(argv[1]);
    if (solve(0, 0))
        print_grid();
    else
        print_error();

    free(col_up);
    free(col_down);
    free(row_left);
    free(row_right);
    for (int i = 0; i < 4; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}