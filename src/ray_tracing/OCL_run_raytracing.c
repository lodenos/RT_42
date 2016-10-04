/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OCL_run_raytracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:05:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/03 01:25:08 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  push_to_window(SDL_Renderer *rend, int *img, size_t w,
        size_t h)
{
    size_t  k;
    size_t  x;
    size_t  y;
    t_rgba  color;

    x = 0;
    while (x < w)
    {
        y = 0;
        while (y < h)
        {
            k = x + y * w;
            color = (t_rgba){img[k] >> 24, img[k] >> 16, img[k] >> 8, img[k]};
            pixel_put(rend, color, x, y);
            ++y;
        }
        ++x;
    }
}

void    OCL_run_raytracing(t_env *e, SDL_Renderer *rend)
{
    cl_mem  buff_cl;
    cl_int  err;
    int     *img;
    size_t  wk;

    wk = e->img.w * e->img.h;
    if (!(img = (int *)ft_memalloc(sizeof(int) * 2073600)))
        ft_putstr_err("ERROR: malloc error", 1);
    buff_cl = clCreateBuffer(e->cl.contx, CL_MEM_READ_WRITE,
            sizeof(int) * 2073600, NULL, &err);
    err_cl(err);
    err_cl(clSetKernelArg(e->cl.krnl.run_raytracing, 0, sizeof(buff_cl), &buff_cl));
    err_cl(clEnqueueWriteBuffer(e->cl.cmd_que, buff_cl, CL_TRUE, 0,
            sizeof(int) * 2073600, img, 0, NULL, NULL));
    err_cl(clEnqueueNDRangeKernel(e->cl.cmd_que, e->cl.krnl.run_raytracing, 1,
            NULL, &wk, NULL, 0, NULL, NULL));
    err_cl(clEnqueueReadBuffer(e->cl.cmd_que, buff_cl, CL_TRUE, 0,
            sizeof(int) * 2073600, img, 0, NULL, NULL));
    push_to_window(rend, img, e->img.w, e->img.h);

/*    int i = -1;
    while (++i < wk)
    {
        if (img[i] != -1)
        {
            ft_putnbr(img[i]);
            ft_putchar('\n');
        }
    }*/
}
