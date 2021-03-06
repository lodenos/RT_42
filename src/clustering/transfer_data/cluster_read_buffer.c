/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_read_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 05:13:52 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/16 05:33:03 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

#define EXIT_CLUSTER_READ_BUFFER    {free(tmp); return (NULL);}

void    *cluster_read_buffer(t_mem mem)
{
    char    *tmp;

    if (!(tmp = ft_memalloc(sizeof(char) * mem.size)))
        return (tmp);
    if (read(mem.fds, tmp, mem.size) == -1)
        EXIT_CLUSTER_READ_BUFFER
    return ((void *)tmp);
}
