/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:11:07 by becamino          #+#    #+#             */
/*   Updated: 2023/03/14 17:33:55 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "libftprint.h"

static int	my_counter(long n)
{
	int	cont;

	cont = 0;
	while (n > 9)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

static int	ft_div(long n)
{
	long	x;

	x = n;
	if (x > 9)
	{
		n = (n % 10) + '0';
		return (n);
	}
	else
		return (n + '0');
}

void	ft_writenbr(int n, int fd)
{
	char	c;
	char	s [20];
	size_t	cont;
	size_t	slen;
	long	num;

	num = n;
	if (num < 0)
	{	
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 0)
	{
		cont = my_counter(num) + 1;
		slen = cont;
		while (cont > 0)
		{
			c = (ft_div(num));
			num = num / 10;
			s[cont - 1] = c;
			cont--;
		}
		write(1, s, slen);
	}
}

/*int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/
