#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>

static size_t	ft_counter(char const *s)
{
	size_t	i;
	size_t	cont;
	
	i = 0;
	cont = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '%')
			cont++;
		i++;
	}
	return (cont);
}

int	ft_printf(char const *s, ...)
{
	size_t	i;
	size_t	n;
	size_t	cont;
	va_list	pars;

	n = ft_counter(s);
    va_start(pars, s);
	cont = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			write (1, "\n", 1);
			cont++;
		}
		else
		{
			write (1, &s[i], 1);
			cont++;
		}
		i++;
	}
	return(cont);
}

int	main(void)
{
	printf("\n%i", printf("hola \n"));
	return (0);
}
