/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OCL_run_raytracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:05:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/18 16:34:40 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  create_buffer_opencl(t_env *e)
{
    static int  i = 1;

    cl_int  err;
    if (i)
    {
        i = 0;
        e->cl.krnl.wk = malloc(sizeof(size_t) * 2);
        e->cl.krnl.wk[0] = e->img.w;
        e->cl.krnl.wk[1] = e->img.h;
        e->cl.krnl.buff_img = clCreateBuffer(e->cl.contx, CL_MEM_READ_WRITE,
            sizeof(unsigned int) * e->img.w * e->img.h, NULL, &err);
        err_cl(err);
        e->cl.krnl.buff_obj = clCreateBuffer(e->cl.contx, CL_MEM_READ_ONLY,
                sizeof(t_obj) * e->scn.n_obj, NULL, &err);
        err_cl(err);
        e->cl.krnl.buff_scn = clCreateBuffer(e->cl.contx, CL_MEM_READ_ONLY,
                sizeof(t_scn), NULL, &err);
        err_cl(err);
        e->cl.krnl.buff_spt = clCreateBuffer(e->cl.contx, CL_MEM_READ_ONLY,
                sizeof(t_spt) * e->scn.n_spt, NULL, &err);
        err_cl(err);
    }
}

static inline void  set_kernel_arg_opencl(t_env *e)
{
    cl_int  err;

    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 0,
                sizeof(e->cl.krnl.buff_img), &e->cl.krnl.buff_img));
    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 1,
                sizeof(e->cl.krnl.buff_obj), &e->cl.krnl.buff_obj));
    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 2,
                sizeof(e->cl.krnl.buff_scn), &e->cl.krnl.buff_scn));
    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 3,
                sizeof(e->cl.krnl.buff_spt), &e->cl.krnl.buff_spt));
}

static inline void  write_buffer_opencl(t_env *e)
{
    cl_int  err;

    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, e->cl.krnl.buff_img, CL_TRUE, 0,
            sizeof(int) * e->img.w * e->img.h, e->img.img, 0, NULL, NULL));
    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, e->cl.krnl.buff_obj, CL_TRUE, 0,
            sizeof(t_obj) * e->scn.n_obj, e->obj, 0, NULL, NULL));
    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, e->cl.krnl.buff_scn, CL_TRUE, 0,
            sizeof(t_scn), &e->scn, 0, NULL, NULL));
    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, e->cl.krnl.buff_spt, CL_TRUE, 0,
            sizeof(t_spt) * e->scn.n_spt, e->spt, 0, NULL, NULL));
}

void    OCL_run_raytracing(t_env *e, SDL_Renderer *rend)
{
    cl_int  err;

    create_buffer_opencl(e);
    set_kernel_arg_opencl(e);
    write_buffer_opencl(e);
    err_cl(clEnqueueNDRangeKernel(e->cl.cmd_que, e->cl.krnl.run_raytracing, 2,
            NULL, e->cl.krnl.wk, NULL, 0, NULL, NULL));
    err_cl(clEnqueueReadBuffer(e->cl.cmd_que, e->cl.krnl.buff_img, CL_TRUE, 0,
            sizeof(unsigned int) * e->img.w * e->img.h, e->img.img, 0, NULL, NULL));

}
