// Expected files   : flood_fill.c
// Allowed functions: -
// --------------------------------------------------------------------------------
//
// Write a function that takes a char ** as a 2-dimensional array of char,
// a t_point as the dimensions of this array and a t_point as the starting point.
//
// Starting from the given 'begin' t_point, this function fills an entire zone 
// by replacing characters inside with the character 'F'.
// A zone is an group of the same character delimitated horizontally and vertically
// by other characters or the array boundry.
//
// The flood_fill function won't fill diagonally.
//
// The flood_fill function will be prototyped like this:
//  void  flood_fill(char **tab, t_point size, t_point begin);
//
// The t_point structure is prototyped like this: (put it in flood_fill.c)
//
//   typedef struct  s_point
//   {
//     int           x;
//     int           y;
//   }               t_point;

typedef struct s_point {
	int	x;
	int	y;
} t_point;

void	flood_fill_recursive(char **map, t_point map_size, t_point current_pos, char target_char)
{
	if (current_pos.y < 0 || current_pos.y >= map_size.y
		|| current_pos.x < 0 || current_pos.x >= map_size.x
		|| map[current_pos.y][current_pos.x] != target_char)
		return;

	map[current_pos.y][current_pos.x] = 'F';

	flood_fill_recursive(map, map_size, (t_point){current_pos.x - 1, current_pos.y}, target_char); // Left
	flood_fill_recursive(map, map_size, (t_point){current_pos.x + 1, current_pos.y}, target_char); // Right
	flood_fill_recursive(map, map_size, (t_point){current_pos.x, current_pos.y - 1}, target_char); // Up
	flood_fill_recursive(map, map_size, (t_point){current_pos.x, current_pos.y + 1}, target_char); // Down
}

void	flood_fill(char **map, t_point map_size, t_point start_pos)
{
	char target_char = map[start_pos.y][start_pos.x];
	flood_fill_recursive(map, map_size, start_pos, target_char);
}

/*
#include <stdio.h>
#include <stdlib.h>

char **clone_map(char *map_template[], t_point map_size)
{
	char **new_map = malloc(sizeof(char*) * map_size.y);
	for (int row = 0; row < map_size.y; ++row)
	{
		new_map[row] = malloc(map_size.x + 1);
		for (int col = 0; col < map_size.x; ++col)
			new_map[row][col] = map_template[row][col];
		new_map[row][map_size.x] = '\0';
	}
	return new_map;
}

void print_map(char **map, t_point map_size)
{
	for (int row = 0; row < map_size.y; ++row)
		printf("%s\n", map[row]);
	printf("\n");
}

int main(void)
{
	t_point map_size = {8, 5};
	char *map_template[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char **map = clone_map(map_template, map_size);
	print_map(map, map_size);

	t_point start_pos = {7, 4};
	flood_fill(map, map_size, start_pos);
	print_map(map, map_size);

	for (int row = 0; row < map_size.y; row++)
		free(map[row]);
	free(map);
	return (0);
}
*/