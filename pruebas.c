#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>


void	ft_writechar(char c);
void    ft_writestr(char *s);

static int	ft_vchecknum (char const *s, int i, int cont, va_list pars)
{
	size_t	x;
	
	x = 0;
	if (s[i] == 'i')
	{
		
	}
	
}

static int	ft_vcheckchar(char const *s, int i, int cont, va_list pars)
{
	size_t	x;
	
	x = 0;
	if (s[i] == 'c')
		ft_writechar(va_arg(pars, int));
	else if (s[i] == 's')
		ft_writestr(va_arg(pars, char *));
	else if (s[i] == 'p')
		ft_writep(va_arg(pars, void *));
	else if (s[i] == '%')
		ft_writechar('%');
	else
		ft_vchecknum(s, i, cont, pars);
	cont++;
	return (cont);
}

int	ft_printf(char const *s, ...)
{
    va_list	pars;
	size_t	i;
	int	cont;

    va_start(pars, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			cont = ft_vcheckchar(s, i, cont, pars);
		}
		else
		{
			write (1, &s[i], 1);
			cont++;
		}
		i++;
	}
	va_end(pars);
	return(cont);
}

int	main(void)
{

	printf("\n%i", ft_printf("hola \n%c%s%%", 'c', "bea"));
	return (0);
}