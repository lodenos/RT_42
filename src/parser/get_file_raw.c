/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_raw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:54:12 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 15:15:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline char *get_file_raw(int fd)
{
    char    *file;
    char    *tmp;

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
        file = ft_strjoin(file, tmp);
        ft_bzero(tmp, 101);
    }
    free(tmp);
    return (file);
}
