/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:50:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 14:38:41 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/*  Format suport .obj .mlt .ortv1  */

void    get_scene(t_env *e, char *file)
{
    char    **tmp;

    if (file == NULL)
        ft_putstr_err("A file must be as argument", 1);
    if (ft_strnbr_idtchar(file, '.') != 1)
        ft_putstr_err("unknown format", 1);
    tmp = ft_strsplit(file, '.');
    if (ft_strlen_tab(tmp) != 2)
        ft_putstr_err("unknown format", 1);
    if (!ft_strcmp(tmp[1], "obj"))
        get_file_obj(e, file);
    else if (!ft_strcmp(tmp[1], "mlt"))
        get_file_mlt(e, file);
    else if (!ft_strcmp(tmp[1], "ortv1"))
        get_file_ortv1(e, file);
    else
        ft_putstr_err("unknown format", 1);
}
