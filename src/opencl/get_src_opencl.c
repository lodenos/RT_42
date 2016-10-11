/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_src_opencl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:18:50 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/11 17:28:06 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_src_opencl(t_opcl *cl)
{
    register int    i;
    register int    fd;

    i = -1;
    while (cl->file[++i])
    {
        if ((fd = open(cl->file[i], O_RDONLY)) == -1)
            ft_putstr_err("ERROR: CL source not found", 1);
        cl->src[i] = get_file_raw(fd);
        cl->size_src[i] = ft_strlen(cl->src[i]);
        close(fd);
    }
}
