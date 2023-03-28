/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writehexma.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:36:25 by becamino          #+#    #+#             */
/*   Updated: 2023/03/28 18:40:32 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_printf.h"

int	ft_len(unsigned int num)
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

int	ft_letter(unsigned int rest)
{
	if (rest == 10)
		return (65);
	if (rest == 11)
		return (66);
	if (rest == 12)
		return (67);
	if (rest == 13)
		return (68);
	if (rest == 14)
		return (69);
	else
		return (70);
}

int	ft_writehexma(unsigned int num)
{
	unsigned long int	rest;
	char				s [32];
	int					cont;
	int					x;

	cont = ft_len(num);
	x = cont;
	if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		rest = num % 16;
		if (rest > 9)
		{	
			rest = ft_letter(rest);
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
	printf("\n%i", ft_writehexma(0));
	return (0);
}*/
