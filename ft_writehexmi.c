/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writehexmi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:54:38 by becamino          #+#    #+#             */
/*   Updated: 2023/03/28 18:40:21 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_printf.h"

int	ft_llen(unsigned int num)
{
	unsigned long int	z;
	size_t				cont;

	z = 1;
	cont = 0;
	while (z > 0)
	{
		z = num / 16;
		num = num / 16;
		cont++;
	}
	return (cont);
}

int	ft_lletter(unsigned int rest)
{
	if (rest == 10)
		return (97);
	if (rest == 11)
		return (98);
	if (rest == 12)
		return (99);
	if (rest == 13)
		return (100);
	if (rest == 14)
		return (101);
	else
		return (102);
}

int	ft_writehexmi(unsigned int num)
{
	unsigned long int	rest;
	char				s [32];
	int					cont;
	int					x;

	cont = ft_llen(num);
	x = cont;
	if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		rest = num % 16;
		if (rest > 9)
		{	
			rest = ft_lletter(rest);
			s[cont - 1] = rest;
		}
		else
			s[cont - 1] = rest + '0';
		num = num / 16;
		cont --;
	}
	write (1, s, x);
	return (x);
}

/*int	main(void)
{
	printf("\n%i", ft_writehexmi(8159));
	return (0);
}*/
