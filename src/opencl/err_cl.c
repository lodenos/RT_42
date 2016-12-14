/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:34:49 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/12 13:39:06 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void	err_cl_ex_d(cl_int err)
{
	if (err == -52)
		ft_putstr_err("opencl -52 : CL_INVALID_KERNEL_ARGS", 1);
	else if (err == -53)
		ft_putstr_err("opencl -53 : CL_INVALID_WORK_DIMENSION", 1);
	else if (err == -54)
		ft_putstr_err("opencl -54 : CL_INVALID_WORK_GROUP_SIZE", 1);
	else if (err == -55)
		ft_putstr_err("opencl -55 : CL_INVALID_WORK_ITEM_SIZE", 1);
	else if (err == -56)
		ft_putstr_err("opencl -56 : CL_INVALID_GLOBAL_OFFSET", 1);
	else if (err == -57)
		ft_putstr_err("opencl -57 : CL_INVALID_EVENT_WAIT_LIST", 1);
	else if (err == -58)
		ft_putstr_err("opencl -58 : CL_INVALID_EVENT", 1);
	else if (err == -59)
		ft_putstr_err("opencl -59 : CL_INVALID_OPERATION", 1);
	else if (err == -60)
		ft_putstr_err("opencl -60 : CL_INVALID_GL_OBJECT", 1);
	else if (err == -61)
		ft_putstr_err("opencl -61 : CL_INVALID_BUFFER_SIZE", 1);
	else if (err == -62)
		ft_putstr_err("opencl -62 : CL_INVALID_MIP_LEVEL", 1);
	else
		err_cl_sub(err);
}

static inline void	err_cl_ex_c(cl_int err)
{
	if (err == -41)
		ft_putstr_err("opencl -41 : CL_INVALID_SAMPLER", 1);
	else if (err == -42)
		ft_putstr_err("opencl -42 : CL_INVALID_BINARY", 1);
	else if (err == -43)
		ft_putstr_err("opencl -43 : CL_INVALID_BUILD_OPTIONS", 1);
	else if (err == -44)
		ft_putstr_err("opencl -44 : CL_INVALID_PROGRAM", 1);
	else if (err == -45)
		ft_putstr_err("opencl -45 : CL_INVALID_PROGRAM_EXECUTABLE", 1);
	else if (err == -46)
		ft_putstr_err("opencl -46 : CL_INVALID_KERNEL_NAME", 1);
	else if (err == -47)
		ft_putstr_err("opencl -47 : CL_INVALID_KERNEL_DEFINITION", 1);
	else if (err == -48)
		ft_putstr_err("opencl -48 : CL_INVALID_KERNEL", 1);
	else if (err == -49)
		ft_putstr_err("opencl -49 : CL_INVALID_ARG_INDEX", 1);
	else if (err == -50)
		ft_putstr_err("opencl -50 : CL_INVALID_ARG_VALUE", 1);
	else if (err == -51)
		ft_putstr_err("opencl -51 : CL_INVALID_ARG_SIZE", 1);
	err_cl_ex_d(err);
}

static inline void	err_cl_ex_b(cl_int err)
{
	if (err == -30)
		ft_putstr_err("opencl -30 : CL_INVALID_VALUE", 1);
	else if (err == -31)
		ft_putstr_err("opencl -31 : CL_INVALID_DEVICE_TYPE", 1);
	else if (err == -32)
		ft_putstr_err("opencl -32 : CL_INVALID_PLATFORM", 1);
	else if (err == -33)
		ft_putstr_err("opencl -33 : CL_INVALID_DEVICE", 1);
	else if (err == -34)
		ft_putstr_err("opencl -34 : CL_INVALID_CONTEXT", 1);
	else if (err == -35)
		ft_putstr_err("opencl -35 : CL_INVALID_QUEUE_PROPERTIES", 1);
	else if (err == -36)
		ft_putstr_err("opencl -36 : CL_INVALID_COMMAND_QUEUE", 1);
	else if (err == -37)
		ft_putstr_err("opencl -37 : CL_INVALID_HOST_PTR", 1);
	else if (err == -38)
		ft_putstr_err("opencl -38 : CL_INVALID_MEM_OBJECT", 1);
	else if (err == -39)
		ft_putstr_err("opencl -39 : CL_INVALID_IMAGE_FORMAT_DESCRIPTOR", 1);
	else if (err == -40)
		ft_putstr_err("opencl -40 : CL_INVALID_IMAGE_SIZE", 1);
	err_cl_ex_c(err);
}

static inline void	err_cl_ex_a(cl_int err)
{
	if (err == -11)
		ft_putstr_err("opencl -11 : CL_BUILD_PROGRAM_FAILURE", 1);
	else if (err == -12)
		ft_putstr_err("opencl -12 : CL_MAP_FAILURE", 1);
	else if (err == -13)
		ft_putstr_err("opencl -13 : CL_MISALIGNED_SUB_BUFFER_OFFSET", 1);
	else if (err == -14)
		ft_putstr_err("opencl -14 : CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT\
		_LIST", 1);
	else if (err == -15)
		ft_putstr_err("opencl -15 : CL_COMPILE_PROGRAM_FAILURE", 1);
	else if (err == -16)
		ft_putstr_err("opencl -16 : CL_LINKER_NOT_AVAILABLE", 1);
	else if (err == -17)
		ft_putstr_err("opencl -17 : CL_LINK_PROGRAM_FAILURE", 1);
	else if (err == -18)
		ft_putstr_err("opencl -18 : CL_DEVICE_PARTITION_FAILED", 1);
	else if (err == -19)
		ft_putstr_err("opencl -19 : CL_KERNEL_ARG_INFO_NOT_AVAILABLE", 1);
	err_cl_ex_b(err);
}

void				err_cl(cl_int err)
{
	if (err == 0)
		return ;
	else if (err == -1)
		ft_putstr_err("opencl -1 : CL_DEVICE_NOT_FOUND", 1);
	else if (err == -2)
		ft_putstr_err("opencl -2 : CL_DEVICE_NOT_AVAILABLE", 1);
	else if (err == -3)
		ft_putstr_err("opencl -3 : CL_COMPILER_NOT_AVAILABLE", 1);
	else if (err == -4)
		ft_putstr_err("opencl -4 : CL_MEM_OBJECT_ALLOCATION_FAILURE", 1);
	else if (err == -5)
		ft_putstr_err("opencl -5 : CL_OUT_OF_RESOURCES", 1);
	else if (err == -6)
		ft_putstr_err("opencl -6 : CL_OUT_OF_HOST_MEMORY", 1);
	else if (err == -7)
		ft_putstr_err("opencl -7 : CL_PROFILING_INFO_NOT_AVAILABLE", 1);
	else if (err == -8)
		ft_putstr_err("opencl -8 : CL_MEM_COPY_OVERLAP", 1);
	else if (err == -9)
		ft_putstr_err("opencl -9 : CL_IMAGE_FORMAT_MISMATCH", 1);
	else if (err == -10)
		ft_putstr_err("opencl -10 : CL_IMAGE_FORMAT_NOT_SUPPORTED", 1);
	err_cl_ex_a(err);
}
