/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writednbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:40:37 by becamino          #+#    #+#             */
/*   Updated: 2023/03/20 16:57:30 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "libftprintf.h"


static int	ft_div(long num)
{
    while (num > 9)
		num = (num / 10);
    return (num + '0');
}

void	ft_writednbr(int n)
{
	char	c;
	long	num;
	int	x;

	num = n;
	if (num < 0)
	{	
		write(1, "-", 1);
		num = -num;
	}
    if (num >= 0)
	{
		while (num > 99)
		{
			c = (ft_div(num));
			num = num / 10;
            write (1, &c, 1);
		}
		if (num < 99)
		{
			x = num / 10;
			write (1, &x, 1);
			x = num % 10;
			write (1, &x, 1);
		}
	}
}

/*int	main(void)
{
	ft_writednbr(550);
	return (0);
}*/
