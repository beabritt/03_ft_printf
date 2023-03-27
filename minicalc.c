#include<unistd.h>
#include<stdio.h>

int main (void)
{
   	int    x;
    int    y;
    int    z;

    x = 0;
	y = 0;
	printf("Introduce el dividendo\n");
    scanf("%d", &x);
    printf("Introduce el divisor\n");
    scanf("%d", &y);
    if (x == 0 || y == 0)
    {
        printf("El cálculo no es posible");
        return (0);
    }
    z = x / y;
    printf("El cociente es: %d", z);
    z = x % y;
    printf("\nEl resto es: %d", z);
    return (0);

}