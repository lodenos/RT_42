/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 21:45:03 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/30 13:23:31 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  init_ort_config(t_env *e)
{
    e->gpu = 0;
    e->thread = 1;
}

void                get_ort_config(t_env *e, char **str, size_t *i)
{
    init_ort_config(e);
    if (e->config)
        ft_putstr_err("ERROR: .config is already initialized", 1);
    if (!str[*i])
        ft_putstr_err("ERROR: .ort .config == NULL", 1);
    if (!str[++*i] && ft_strcmp(str[*i], "{") == 0)
        ft_putstr_err("ERROR: .config {", 1);
    while (ft_strcmp(str[++*i], "}") != 0)
    {
        if (!str[*i])
            ft_putstr_err("ERROR: .config incomplete", 1);
        if (ft_strcmp(str[*i], "GPU") == 0 || ft_strcmp(str[*i], "cpu") == 0)
        {
            if (ft_strcmp(str[++*i], "on") == 0 || ft_strcmp(str[*i], "ON") == 0)
                e->gpu = 1;
            else if (ft_strcmp(str[++*i], "off") == 0 || ft_strcmp(str[*i], "off") == 0)
                e->gpu = 0;
            else
                ft_putstr_err("ERROR: .config flags GPU", 1);
        }
        if (ft_strcmp(str[*i], "thread") == 0)
        {
            if (!str[++*i])
                ft_putstr_err("ERROR: .config flags thread", 1);

        }
    }
}
