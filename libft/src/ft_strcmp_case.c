/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 02:33:49 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/05 03:29:03 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strcmp_case(char const *s1, char const *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 >= 'a' && *s1 <= 'z')
        {
            if (*s2 >= 'A' && *s2 <= 'Z')
            {
                if (*s1 != (*s2 + 32))
                    return ((unsigned char)*s1 - (unsigned char)*s2);
            }
            else
                if (*s1 != *s2)
                    return ((unsigned char)*s1 - (unsigned char)*s2);
        }
        else if (*s1 >= 'A' && *s1 <= 'Z')
        {
            if (*s2 >= 'a' && *s2 <= 'z')
            {
                if (*s1 != (*s2 - 32))
                    return ((unsigned char)*s1 - (unsigned char)*s2);
            }
            else
                if (*s1 != *s2)
                    return ((unsigned char)*s1 - (unsigned char)*s2);
        }
        else
            if (*s1 != *s2)
                return ((unsigned char)*s1 - (unsigned char)*s2);
        ++s1;
        ++s2;
    }
    return (0);
}
