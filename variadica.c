/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadica.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:34:18 by becamino          #+#    #+#             */
/*   Updated: 2023/03/14 16:50:23 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	suma(int n, ...)
{
	int		i;
	int		s;
	int		valor;
	va_list	pars;

	va_start (pars, n);
	i = 0;
	s = 0;
	while (i < n)
	{	
		valor = va_arg(pars, int);
		s += valor;
		i++;
	}	
	va_end (pars);
	return (s);
}

int	main(void)
{
	int	x;

	x = suma(5, 1, 2, 3, 2, 1);
	printf ("%i \n", x);
	return (0);
}
