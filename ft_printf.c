/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:27:14 by becamino          #+#    #+#             */
/*   Updated: 2023/03/17 13:41:56 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libftprint.h"

static int	ft_checkchar(char const *s, int i, int cont, va_list args)
{
	size_t	x;

	x = 0;
	if (s[i] == 'c')
	{
		ft_writechar();
		printf("checkchar");
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
			if (s[i] == 'c' || s[i] == 's')
			{
				cont = ft_checkchar(s, i, cont, pars);
				printf("pasa");
			}
			else
				write (1, '%', 1);
		}
		else if (s[i] == '\n')
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

	printf("\n%i", ft_printf("hola \n %c", 'c'));
	return (0);
}