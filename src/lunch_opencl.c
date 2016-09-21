/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 23:15:13 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 14:24:10 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static size_t   *ft_size_src(char **src)
{
    int         i;
    size_t      *size_src;

    i = -1;
    size_src = NULL;
    if (!(size_src = (size_t *)ft_memalloc(sizeof(size_t) *
                    (ft_strlen_tab(src) + 1))))
        return (size_src);
    while (src[++i])
        size_src[i] = ft_strlen(src[i]);
    return (size_src);
}

void    lunch_opencl(t_opcl *cl)
{
    if (cl->file == NULL)
        ft_putstr_err("Missing source codes OpenCL", 1);
    cl->src = get_src_opencl(cl->file);
    cl->size_src = ft_size_src(cl->src);
    err_cl(clGetPlatformIDs(1, &cl->platf_id, &cl->num_platf));
    err_cl(clGetDeviceIDs(cl->platf_id, CL_DEVICE_TYPE_GPU, 1, &cl->device_id,
                &cl->num_device));
    cl->contx = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &cl->err);
    err_cl(cl->err);
    cl->cmd_que = clCreateCommandQueue(cl->contx, cl->device_id, 0, &cl->err);
    err_cl(cl->err);
    cl->prog = clCreateProgramWithSource(cl->contx, 1, (const char**)cl->src,
            cl->size_src, &cl->err);
    err_cl(cl->err);
    ft_putstr("lol2\n");
    err_cl(clBuildProgram(cl->prog, 1, &cl->device_id, cl->flags, NULL, NULL));
    ft_putstr("lol3\n");
}
