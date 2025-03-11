
#include <stdlib.h>
#include <stdio.h>

int is_power_of_2(unsigned int n);

int	main(void)
{
printf("%d\n", is_power_of_2(1024));
printf("%d\n", is_power_of_2(1023));
printf("%d\n", is_power_of_2(0));
printf("%d\n", is_power_of_2(1));
}