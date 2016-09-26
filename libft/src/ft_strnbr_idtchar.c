/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr_idtchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:32:48 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/25 17:41:51 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strnbr_idtchar(char *str, char c)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    if (str == NULL)
        return (j);
    while (str[i])
    {
        if (str[i] == c)
            ++j;
        ++i;
    }
    return (j);
}
