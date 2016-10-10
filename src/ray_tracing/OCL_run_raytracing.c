/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OCL_run_raytracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:05:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/08 02:27:15 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  push_to_window(SDL_Renderer *rend, int *img, size_t w,
        size_t h)
{
    size_t  k;
    size_t  x;
    size_t  y;

    x = 0;
    while (x < w)
    {
        y = 0;
        while (y < h)
        {
            k = x + y * w;
            pixel_put(rend, (t_rgba){(unsigned char)(img[k] >> 24),
                    (unsigned char)(img[k] >> 16), (unsigned char)(img[k] >> 8),
                    (unsigned char)(img[k])}, x, y);
            ++y;
        }
        ++x;
    }
}

void    OCL_run_raytracing(t_env *e, SDL_Renderer *rend)
{
    cl_int  err;
    cl_mem  buff_img;
    cl_mem  buff_obj;
    cl_mem  buff_scn;
    cl_mem  buff_spt;
    size_t  *wk;

    wk = malloc(sizeof(size_t) * 2);
    wk[0] = e->img.w;
    wk[1] = e->img.h;

    printf("W = %lu ;  H = %lu\n", e->scn.cam.w, e->scn.cam.h);



//------    Create Buffer

    buff_img = clCreateBuffer(e->cl.contx, CL_MEM_READ_WRITE,
            sizeof(int) * e->img.w * e->img.h, NULL, &err);
    err_cl(err);

    buff_obj = clCreateBuffer(e->cl.contx, CL_MEM_READ_WRITE,
            sizeof(t_obj) * e->scn.n_obj, NULL, &err);
    err_cl(err);

    buff_scn = clCreateBuffer(e->cl.contx, CL_MEM_READ_WRITE,
            sizeof(t_scn), NULL, &err);
    err_cl(err);

    buff_spt = clCreateBuffer(e->cl.contx, CL_MEM_READ_WRITE,
            sizeof(t_spt) * e->scn.n_spt, NULL, &err);
    err_cl(err);

//------    Set Kernel Argument

    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 0,
                sizeof(buff_img), &buff_img));

    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 1,
                sizeof(buff_obj), &buff_obj));

    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 2,
                sizeof(buff_scn), &buff_scn));

    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 3,
                sizeof(buff_spt), &buff_spt));


//------    Write Buffer

    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, buff_img, CL_TRUE, 0,
            sizeof(int) * e->img.w * e->img.h, e->img.img, 0, NULL, NULL));

    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, buff_obj, CL_TRUE, 0,
            sizeof(t_obj) * e->scn.n_obj, e->scn.obj, 0, NULL, NULL));

    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, buff_scn, CL_TRUE, 0,
            sizeof(t_scn), &e->scn, 0, NULL, NULL));

    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, buff_spt, CL_TRUE, 0,
            sizeof(t_spt) * e->scn.n_spt, e->scn.spt, 0, NULL, NULL));

//------    Lunch Kernel

    err_cl(clEnqueueNDRangeKernel(e->cl.cmd_que, e->cl.krnl.run_raytracing, 2,
            NULL, wk, NULL, 0, NULL, NULL));

//------    Read Buffer

    err_cl(clEnqueueReadBuffer(e->cl.cmd_que, buff_img, CL_TRUE, 0,
            sizeof(int) * e->img.w * e->img.h, e->img.img, 0, NULL, NULL));

//------    Push Image to window


    printf("red = %d ; green = %d ; blue = %d\n", e->scn.spt[0].rgba.red,
            e->scn.spt[0].rgba.green, e->scn.spt[0].rgba.blue);

    push_to_window(rend, e->img.img, e->img.w, e->img.h);
}
