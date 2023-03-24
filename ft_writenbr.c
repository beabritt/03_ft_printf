/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:11:07 by becamino          #+#    #+#             */
/*   Updated: 2023/03/20 14:55:50 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "ft_printf.h"

static int	my_counter(long n)
{
	int	cont;

	cont = 0;
	if (n < 0)
	{
		cont++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

int	ft_writenbr(int n)
{
	char	c;
	char	s [32];
	size_t	cont;
	size_t	slen;
	long	num;

	num = n;
	if (n < 0)
	{	
		s[0] = '-';
		num = -num;
	}
	cont = my_counter(n);
	slen = cont;
	s[cont] = '\0';
	while (num > 0)
	{
		cont--;
		c = num % 10 + '0';
		num = num / 10;
		s[cont] = c;
	}
	write(1, s, slen);
	return (slen);
}

/*int	main(void)
{
	printf("\n%i", ft_writenbr(-666));
	return (0);
}*/
