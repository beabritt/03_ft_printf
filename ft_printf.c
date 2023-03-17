/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:27:14 by becamino          #+#    #+#             */
/*   Updated: 2023/03/14 19:56:23 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libftprint.h"

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

static	ft_chars(char const *s, )
{
	size_t	i;
	
	if (s[i] == 'c')
		ft_write
}


int	ft_printf(char const *s, ...)
{
    va_list	pars;
	size_t	i;
	size_t	n;

	n = ft_counter(s);
    va_start(pars, n);
	i = 0;
	while(s[i] != '\0')
	{
		else if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c' || s[i] == 's')
				ft_chars(s, );
		}
		i++;
	
	}

}

int	main(void)
{
    char    *s;


    s = ft_printf("%c", 'a');
    printf("%s \n", s);
	return (0);
}