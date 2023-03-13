#include <stdio.h>
#include <stdarg.h>

int	suma(int n, ...)
{
	int	i;
	int	s;
	int	valor;

	va_list	pars;
	va_start	(pars, n);
	i = 0;
	s = 0;
	while(i < n)
	{	valor = va_arg(pars, int);
		s += valor;
		i++;
	}	
	va_end	(pars);
	return (s);
	
}

int	main(void)
{
	int	x;

	x = suma(5, 1, 2, 3, 2, 1);
	printf ("%i \n", x);
	return (0);
}
