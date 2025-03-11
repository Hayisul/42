/* ************************************************************************** */
/*                                                                            */
/*                                FLOOD_FILL                                  */
/*                                                                            */
/*   Performs a recursive flood fill on a 2D map, starting from the given     */
/*   position, replacing the targeted character with 'F'. A connected zone    */
/*   consists of horizontally and vertically adjacent identical characters.   */
/*                                                                            */
/*   Usage Example:                                                           */
/*                                                                            */
/*     Initial map:                                                           */
/*       11111111                                                             */
/*       10001001                                                             */
/*       10010001                                                             */
/*       10110001                                                             */
/*       11100001                                                             */
/*                                                                            */
/*     Starting from (7,4):                                                   */
/*       FFFFFFFF                                                             */
/*       F000F00F                                                             */
/*       F00F000F                                                             */
/*       F0FF000F                                                             */
/*       FFF0000F                                                             */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_point {
	int	x;
	int	y;
} t_point;

void	ft_putchar(char c) {
	write(1, &c, 1);
}

// Recursively fills connected matching positions with 'F'
void	flood_fill_recursive(char **map, t_point size, t_point cur, char target) {
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] != target)
		return;

	map[cur.y][cur.x] = 'F';

	flood_fill_recursive(map, size, (t_point){cur.x - 1, cur.y}, target);
	flood_fill_recursive(map, size, (t_point){cur.x + 1, cur.y}, target);
	flood_fill_recursive(map, size, (t_point){cur.x, cur.y - 1}, target);
	flood_fill_recursive(map, size, (t_point){cur.x, cur.y + 1}, target);
}

// Initiates the flood fill operation
void	flood_fill(char **map, t_point size, t_point start) {
	char	target = map[start.y][start.x];
	flood_fill_recursive(map, size, start, target);
}

// Creates a mutable copy of the original map template
char **clone_map(char *template[], t_point size) {
	char **new_map = malloc(sizeof(char *) * size.y);
	for (int row = 0; row < size.y; ++row) {
		new_map[row] = malloc(size.x + 1);
		for (int col = 0; col < size.x; ++col)
			new_map[row][col] = template[row][col];
		new_map[row][size.x] = '\0';
	}
	return new_map;
}

// Prints the map to the standard output
void print_map(char **map, t_point size) {
	for (int row = 0; row < size.y; ++row)
		printf("%s\n", map[row]);
	printf("\n");
}

// Demonstrates usage of the flood fill algorithm
int main(void) {
	t_point size = {8, 5};
	char *template[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char **map = clone_map(template, size);
	print_map(map, size);

	t_point start = {7, 4};
	flood_fill(map, size, start);
	print_map(map, size);

	for (int row = 0; row < size.y; row++)
		free(map[row]);
	free(map);

	return (0);
}
