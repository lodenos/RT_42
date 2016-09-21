/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_src_opencl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:20:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/20 17:23:09 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

char    **get_src_opencl(char **file)
{
    int     i;
    int     fd;
    size_t  buf;
    char    **src;
    char    tmp;

    i = -1;
    src = NULL;
    if (!(src = (char**)ft_memalloc(sizeof(char*) *
                    ((size_t)ft_strlen_tab(file) + 1))))
        return (src);
    while (file[++i])
    {
        buf = 0;
        if ((fd = open(file[i], O_RDONLY)) == -1)
            continue ;
        while (read(fd, &tmp, 1))
            buf++;
        lseek(fd, SEEK_SET, 0);
        if (!(src[i] = (char*)ft_memalloc(sizeof(char) * (buf + 1))))
            return (src);
        read(fd, src, buf);
    }
    return (src);
}
