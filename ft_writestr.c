/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:09 by becamino          #+#    #+#             */
/*   Updated: 2023/03/20 14:46:08 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include "ft_printf.h"

static size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

int	ft_writestr(char *s)
{
    size_t  slen;

    slen = ft_strlen(s);
    
    write(1, s, slen);
    return (slen);
}
