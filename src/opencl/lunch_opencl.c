/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_opencl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:30:24 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 14:57:22 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void	create_kernel(cl_program prog, t_krnl *krnl)
{
	cl_int	err;

	krnl->run_raytracing = clCreateKernel(prog, "run_raytracing", &err);
	err_cl(err);
}

static inline void	console_log_compilation(cl_program prog,
		cl_device_id device_id, cl_program_build_info type)
{
	size_t	size;
	char	*str;

	err_cl(clGetProgramBuildInfo(prog, device_id, type, 0, NULL, &size));
	if (!(str = ft_memalloc(sizeof(char) * size + 1)))
		ft_putstr_err("ERROR: malloc error", 1);
	err_cl(clGetProgramBuildInfo(prog, device_id, type, size, str, NULL));
	ft_putstr_err(str, 1);
}

void				lunch_opencl(t_opcl *cl)
{
	cl_int	err;

	get_src_opencl(cl);
	err_cl(clGetPlatformIDs(1, &cl->platf_id, &cl->num_platf));
	err_cl(clGetDeviceIDs(cl->platf_id, CL_DEVICE_TYPE_GPU, 1, &cl->device_id,
	&cl->num_device));
	cl->contx = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &err);
	err_cl(err);
	cl->cmd_que = clCreateCommandQueue(cl->contx, cl->device_id, 0, &err);
	err_cl(err);
	cl->prog = clCreateProgramWithSource(cl->contx, cl->nbr_src,
	(const char **)((size_t)(cl->src)), cl->size_src, &err);
	err_cl(err);
	if (clBuildProgram(cl->prog, 1, &cl->device_id, cl->flags, NULL, NULL) != 0)
		console_log_compilation(cl->prog, cl->device_id, CL_PROGRAM_BUILD_LOG);
	create_kernel(cl->prog, &cl->krnl);
}
