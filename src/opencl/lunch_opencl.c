/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_opencl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:30:24 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/27 16:23:44 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  create_kernel(cl_program prog, t_krnl *krnl)
{
    cl_int  err;

    krnl->run_raytracing = clCreateKernel(prog, "run_raytracing", &err); 
    err_cl(err);
}

void                lunch_opencl(t_opcl *cl)
{
    get_src_opencl(cl);
    err_cl(clGetPlatformIDs(1, &cl->platf_id, &cl->num_platf));
    err_cl(clGetDeviceIDs(cl->platf_id, CL_DEVICE_TYPE_GPU, 1, &cl->device_id,
                &cl->num_device));
    cl->contx = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &cl->err);
    err_cl(cl->err);
    cl->cmd_que = clCreateCommandQueue(cl->contx, cl->device_id, 0, &cl->err);
    err_cl(cl->err);
    cl->prog = clCreateProgramWithSource(cl->contx, 1, (const char **)cl->src,
            cl->size_src, &cl->err);
    err_cl(cl->err);
    err_cl(clBuildProgram(cl->prog, 1, &cl->device_id, cl->flags, NULL, NULL));
    create_kernel(cl->prog, &cl->krnl);
}
