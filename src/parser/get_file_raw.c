/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_raw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:54:12 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 20:20:09 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

char    *get_file_raw(int fd)
{
    char    *file;
    char    *tmp;
    char    *swp;

    if (fd == -1)
        return (NULL);
    if (!(file = (char *)ft_memalloc(sizeof(char))))
        return (file);
    if (!(tmp = (char *)ft_memalloc(sizeof(char) * 101)))
    {
        free(file);
        return (tmp);
    }
    while (read(fd, tmp, 100))
    {
        swp = ft_strjoin(file, tmp);
        free(file);
        file = ft_strdup(swp);
        free(swp);
        ft_bzero(tmp, 101);
    }
    free(tmp);
    return (file);
}
