#include <unistd.h>
#include <stdio.h>

int ft_mul(int *ptr, int number) {
    return ((*ptr) * number);
}

int main(void) {
    int value;
    int number;
    int result;
    
    value = -6;
    number = -3;
    result = ft_mul(&value, number);
    printf("%d times %d = %d\n", value, number, result);
    return (0);
}