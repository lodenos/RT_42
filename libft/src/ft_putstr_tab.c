/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:09:13 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/25 21:07:51 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putstr_tab(char **str, char *sep)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        ft_putstr(str[i]);
        ft_putstr(sep);
        ++i;
    }
}
