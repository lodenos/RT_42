/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_ortv1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:03:45 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 22:53:58 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  get_obj_scene(t_env *e, char *str)
{
    static int  n_obj = -1;
    static int  n_spt = -1;
    char        **tmp;

    tmp = ft_strsplit(str, ' ');
    if (!ft_strcmp(tmp[0], "camera"))
        get_camera(e, tmp);
    else if (!ft_strcmp(tmp[0], "spot"))
        get_spot(&e->scn.spt[++n_spt], tmp);
    else if (!ft_strcmp(tmp[0], "sphere"))
        get_sphere(&e->scn.obj[++n_obj], tmp);
    else if (!ft_strcmp(tmp[0], "cone"))
        get_cone(&e->scn.obj[++n_obj], tmp);
    else if (!ft_strcmp(tmp[0], "plan"))
        get_plan(&e->scn.obj[++n_obj], tmp);
    else if (!ft_strcmp(tmp[0], "cylinder"))
        get_cylinder(&e->scn.obj[++n_obj], tmp);
    else if (!ft_strcmp(tmp[0], "torus"))
        get_torus(&e->scn.obj[++n_obj], tmp);
    free_tab((void **)tmp);
}

static inline void  get_nbr_obj(t_env *e, char **str)
{
    register int    i;
    char            **tmp;

    i = -1;
    e->scn.n_obj = 0;
    e->scn.n_spt = 0;
    while (str[++i])
    {
        tmp = ft_strsplit(str[i], ' ');
        if ((int)ft_strlen_tab < 2)
            ft_putstr_err("ERROR Parameter", 1);
        if (!ft_strcmp(tmp[0], "cone") || !ft_strcmp(tmp[0], "cylinder") ||
                !ft_strcmp(tmp[0], "plan") || !ft_strcmp(tmp[0], "sphere") ||
                !ft_strcmp(tmp[0], "torus"))
            ++e->scn.n_obj;
        else if (!ft_strcmp(tmp[0], "spot"))
            ++e->scn.n_spt;
        else if (!ft_strcmp(tmp[0], "camera"))
            ;
        else
            ft_putstr_err("ERROR Object unknown", 1);
        free_tab((void **)tmp);
    }
}

void                get_file_ortv1(t_env *e, char *file)
{
    int     i;
    int     fd;
    char    *tmp;
    char    **swp;

    i = -1;
    if ((fd = open(file, O_RDONLY)) == -1)
        ft_putstr_err("The file can not be opened, or no", 1);
    if ((tmp = get_file_raw(fd)) == NULL)
        ft_putstr_err("ERROR File", 1);
    swp = ft_strsplit(tmp, '\n');
    get_nbr_obj(e, swp);
    if (!(e->scn.obj = (t_obj *)ft_memalloc(sizeof(t_obj) * (e->scn.n_obj + 1))))
        ft_putstr_err("RT: Malloc error", 1);
    if (!(e->scn.spt = (t_spt *)ft_memalloc(sizeof(t_spt) * (e->scn.n_spt + 1))))
        ft_putstr_err("RT: Malloc error", 1);
    while (swp[++i])
        get_obj_scene(e, swp[i]);
    e->scn.obj[e->scn.n_obj].end = 0;
    e->scn.spt[e->scn.n_spt].end = 0;
    free(tmp);
    free_tab((void **)swp);
}
