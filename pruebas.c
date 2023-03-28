
#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include "ft_printf.h"

int	ft_writechar(char c);
int	ft_writestr(char *s);
int	ft_writenbr(int n);
int	ft_writeunbr(int n);

static int	ft_vchecknum (char const *s, int i, va_list pars)
{
	if (s[i] == 'i' || s[i] == 'd')
		return(ft_writenbr(va_arg(pars, int)));
	else if (s[i] == 'u')
		return(ft_writeunbr(va_arg(pars, int)));
	return (0);
}

static int	ft_vcheckchar(char const *s, int i, va_list pars)
{
	if (s[i] == 'c')
		return (ft_writechar(va_arg(pars, int)));
	else if (s[i] == 's')
		return (ft_writestr(va_arg(pars, char *)));
	else if (s[i] == '%')
		return (ft_writechar('%'));
	else
		return (ft_vchecknum(s, i, pars));
	return (0);
}

int	ft_printf(char const *s, ...)
{
    va_list	pars;
	size_t	i;
	int	cont;

    va_start(pars, s);
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			cont += ft_vcheckchar(s, i, pars);
		}
		else
		{
			write (1, &s[i], 1);
			cont++;
		}
		i++;
	}
	va_end(pars);
	return (cont);
}

int	main(void)
{

	printf("\n%i", ft_printf("%i %u", 5, -10));
	return (0);
}
