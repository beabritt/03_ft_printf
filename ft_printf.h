/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:00:28 by becamino          #+#    #+#             */
/*   Updated: 2023/03/14 17:23:11 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
#define FT_PRINTF_H

int	ft_printf(char const *s, ...);
int	ft_writechar(char c);
int ft_writestr(char *s);
int	ft_writenbr(int n);
int	ft_writeunbr(int n);


#include<stdlib.h>
#include<stdio.h>


#endif