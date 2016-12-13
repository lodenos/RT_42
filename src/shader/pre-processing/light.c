/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/07 15:47:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

// TODO Exeprimental -- Teste, NO Exactly
// TODO Oui je sais ca fais plus de 25 lignes 'glodenos'->all

void    light(t_env *e, size_t id, t_obj obj_tmp, t_ray *ray)
{
    size_t  i       = 0;
    size_t  index;
    t_ray   ray_spot;
    float   z       = 0.0f;
    float   tmp;
    int     np      = 0;
    float   det;
    float   red     = 0;
    float   green   = 0;
    float   blue    = 0;

    while (e->spt[i].end)
    {
        index = 0;
        ray->color = obj_tmp.color;
        ray_spot.pos = e->spt[i].pos;
        ray_spot.dir = normalize(sub(obj_tmp.collision, ray_spot.pos));



        det = check_object(e->obj, ray_spot, &index, 5);


        if ((det == -1) || (id == index))
        {
            diffused_light(ray, e->spt[i], obj_tmp);
            tmp = specular_light(e->spt[i], obj_tmp);
            if (tmp >= z)
            {
                z = tmp;
                np = i;
            }
        }
        else
            ray->color = 0x0;
        red += (float)(unsigned char)(ray->color >> 24);
        green += (float)(unsigned char)(ray->color >> 16);
        blue += (float)(unsigned char)(ray->color >> 8);
        ++i;
    }
    ray->color = (unsigned int)(unsigned char)(red / e->scn.n_spt) << 24 |
            (unsigned int)(unsigned char)(green / e->scn.n_spt) << 16 |
            (unsigned int)(unsigned char)(blue / e->scn.n_spt) << 8 | 0xFF;
    if (z > 0.0f)
        ray->color = limit((float)(unsigned char)(ray->color >> 24) +
                (float)(unsigned char)(e->spt->color >> 24) * z) << 24 |
                limit((float)(unsigned char)(ray->color >> 16) +
                (float)(unsigned char)(e->spt->color >> 16) * z) << 16 |
                limit((float)(unsigned char)(ray->color >> 8) +
                (float)(unsigned char)(e->spt->color >> 8) * z) << 8 | 0xFF;
}
