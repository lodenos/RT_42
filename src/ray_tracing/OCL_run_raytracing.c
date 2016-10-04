/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OCL_run_raytracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:05:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 20:51:34 by glodenos         ###   ########.fr       */
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
            pixel_put(rend, (t_rgba){img[k] >> 24, img[k] >> 16, img[k] >> 8,
                    img[k]}, x, y);
            ++y;
        }
        ++x;
    }
}

void    OCL_run_raytracing(t_env *e, SDL_Renderer *rend)
{
    cl_int  err;
    cl_mem  buff_img;
    size_t  wk;

    wk = e->img.w * e->img.h;

//----------

    buff_img = clCreateBuffer(e->cl.contx, CL_MEM_READ_WRITE,
            sizeof(int) * wk, NULL, &err);
    err_cl(err);

//----------

    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 1,
                sizeof(buff_img), &buff_img));

//----------

    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, buff_img, CL_TRUE, 0,
            sizeof(int) * wk, e->img.img, 0, NULL, NULL));

//-----------

    err_cl(clEnqueueNDRangeKernel(e->cl.cmd_que, e->cl.krnl.run_raytracing, 1,
            NULL, &wk, NULL, 0, NULL, NULL));

//-----------

    err_cl(clEnqueueReadBuffer(e->cl.cmd_que, buff_img, CL_TRUE, 0,
            sizeof(int) * wk, e->img.img, 0, NULL, NULL));
    push_to_window(rend, e->img.img, e->img.w, e->img.h);
}
