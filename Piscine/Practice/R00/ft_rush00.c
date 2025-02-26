#include <unistd.h>

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	mapping(int x, int y, int pos_x, int pos_y) {
	while (pos_x <= x) {
		if ((pos_x == 1 && pos_y == 1) || (pos_x == x && pos_y == 1) || (pos_x == 1 && pos_y == y) || (pos_x == x && pos_y == y)) {
			ft_putchar(' ');
		}
		else if (pos_x == 1 || pos_x == x) {
			ft_putchar('R');
		}
		else if (pos_y == 1 || pos_y == y) {
			ft_putchar('C');
		}
		else {
			ft_putchar(' ');
		}
		pos_x++;
	}
}

void	rush(int x, int y)
{
	int	pos_x;
	int	pos_y;
	
	pos_x = 1;
	pos_y = 1;
	
	if (x <= 0 || y <= 0) {
		ft_putchar('\0');
	}
	else {
		while (pos_y <= y) {
			mapping(x, y, pos_x, pos_y);
			pos_x = 1;
			ft_putchar('\n');
			pos_y++;
		}
	}
}

int	main(void) {
	rush(6, 6);
	return (0);
}