/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:09 by becamino          #+#    #+#             */
/*   Updated: 2023/03/14 17:34:17 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include "libftprint.h"

size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

void    ft_writestr(char *s)
{
    size_t  slen;

    slen = ft_strlen(s);
    
    write(1, s, slen);
}
