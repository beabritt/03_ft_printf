/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:27:14 by becamino          #+#    #+#             */
/*   Updated: 2023/03/20 14:58:28 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include "libftprintf.h"

void	ft_writechar(char c);
void    ft_writestr(char *s);
void	ft_writenbr(int n);

static int	ft_vchecknum (char const *s, int i, int cont, va_list pars)
{
	size_t	x;
	
	x = 0;
	if (s[i] == 'i')
		ft_writenbr(va_arg(pars, int));
	cont++;
	return (cont);
}

static int	ft_vcheckchar(char const *s, int i, int cont, va_list pars)
{
	size_t	x;
	
	x = 0;
	if (s[i] == 'c')
		ft_writechar(va_arg(pars, int));
	else if (s[i] == 's')
		ft_writestr(va_arg(pars, char *));
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
	return (cont);
}

int	main(void)
{

	printf("\n%i", ft_printf("hola \n%c%s%%%i", 'c', "bea", 3));
	return (0);
}