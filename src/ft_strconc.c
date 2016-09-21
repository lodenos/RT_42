/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:47:05 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:15:49 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

char    *ft_strconc(char *str, char start, char end)
{
    int     i;
    int     s;
    char    *res;

    s = 0;
    i = 0;
    if (!str || !start || !end || start == end)
        return (NULL);
    while (str[s] && str[s] != start)
        s++;
    if (!str[s])
        return (NULL);
    while (str[s + i] && str[s + i] != end)
        i++;
    if (!str[s + i])
        return (NULL);
    res = ft_strsub(str, (unsigned int)(s + 1), (size_t)(i - 1));
    return (res);
}
