/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_create_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 05:13:49 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:49 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

t_mem	cluster_create_buffer(int fds, size_t size)
{
	t_mem	mem;

	mem.fds = fds;
	mem.size = size;
	return (mem);
}
