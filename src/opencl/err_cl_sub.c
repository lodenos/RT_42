/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cl_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:18:10 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 15:44:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  err_cl_sub_ex(cl_int err)
{
    if (err == -1003)
        ft_putstr_err("opencl -1003 : CL_INVALID_D3D10_RESOURCE_KHR", 1);
    else if (err == -1004)
        ft_putstr_err("opencl -1004 : CL_D3D10_RESOURCE_ALREADY_ACQUIRED_\
                KHR", 1);
    else if (err == -1005)
        ft_putstr_err("opencl -1005 : CL_D3D10_RESOURCE_NOT_ACQUIRED_KHR", 1);
    else if (err == -9999)
        ft_putstr_err("opencl -9999 : NVidia : Illegal read or write to a \
                buffer", 1);
    else
    {
        ft_putstr("opencl ");
        ft_putnbr(err);
        ft_putstr_err(" : error unknown", 1);
    }
}

void    err_cl_sub(cl_int err)
{
    if (err == -63)
        ft_putstr_err("opencl -63 : CL_INVALID_GLOBAL_WORK_SIZE", 1);
    else if (err == -64)
        ft_putstr_err("opencl -64 : CL_INVALID_PROPERTY", 1);
    else if (err == -65)
        ft_putstr_err("opencl -65 : CL_INVALID_IMAGE_DESCRIPTOR", 1);
    else if (err == -66)
        ft_putstr_err("opencl -66 : CL_INVALID_COMPILER_OPTIONS", 1);
    else if (err == -67)
        ft_putstr_err("opencl -67 : CL_INVALID_LINKER_OPTIONS", 1);
    else if (err == -68)
        ft_putstr_err("opencl -68 : CL_INVALID_DEVICE_PARTITION_COUNT", 1);
    else if (err == -69)
        ft_putstr_err("opencl -69 : CL_INVALID_PIPE_SIZE", 1);
    else if (err == -70)
        ft_putstr_err("opencl -70 : CL_INVALID_DEVICE_QUEUE", 1);
    else if (err == -1000)
        ft_putstr_err("opencl -1000 : CL_INVALID_GL_SHAREGROUP_REFERENCE_\
                KHR", 1);
    else if (err == -1001)
        ft_putstr_err("opencl -1001 : No valid ICDs found", 1);
    else if (err == -1002)
        ft_putstr_err("opencl -1002 : CL_INVALID_D3D10_DEVICE_KHR", 1);
    else
        err_cl_sub_ex(err);
}
