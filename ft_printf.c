/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:27:14 by becamino          #+#    #+#             */
/*   Updated: 2023/03/20 14:24:37 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include "libftprint.h"

void	ft_writechar(char c);
void    ft_writestr(char *s);

static int	ft_vcheckchar(char const *s, int i, int cont, va_list pars)
{
	size_t	x;
	
	x = 0;
	if (s[i] == 'c')
	{
		ft_writechar(va_arg(pars, int));
		cont++;
	}
	if (s[i] == 's')
	{
		ft_writestr(va_arg(pars, char *));
		cont++;
	}
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

	printf("\n%i", ft_printf("hola \n%c%s", 'c', "bea"));
	return (0);
}