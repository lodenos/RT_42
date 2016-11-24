/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/07 00:08:10 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void get_normal_object(t_obj *obj, register t_ray ray,
        register float det)
{
    if (obj->type == CONE)
        obj->normal = reverse(normalize(sub(obj->pos_a,
                sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate)), (1.0f + tanf(obj->angle / 2.0f)
                * tanf(obj->angle / 2.0f)))))));
    else if (obj->type == CYLINDER)
        obj->normal = reverse(normalize(sub(obj->pos_a, sub(obj->collision,
                vector_mult_x(obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate))))));
    else if (obj->type == PLAN)
        obj->normal = obj->rotate;
    else if (obj->type == SPHERE)
        obj->normal = normalize(sub(obj->collision, obj->pos_a));
    else if (obj->type == TORUS)
        return ;
}

cl_float3 rayonRefracte(cl_float3 normal, cl_float3 incident, float n1, float n2)
{
    const float n = (n1 / n2);

    printf("%.2f\n", n);
    cl_float3 inv;
    inv = reverse(incident);
    float cosI = dot(normal, inv);
    float cosT = sqrt(1 - n * n *(1 - (cosI * cosI)));
    cl_float3 T;

    if(cosI > 0)
        T = add(vector_mult_x(normal, (cosI * n - cosT)), vector_mult_x(incident, n));
    else
        T = add(vector_mult_x(normal, (cosI * n + cosT)),vector_mult_x(incident, n));

    return (T);
}


void        run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
{
    register float  det;
    size_t          id;
    t_obj           obj_tmp;
    unsigned int    color;

    ray->color = 0x0;
    det = check_object(obj, *ray, &id, NO_MASK);
    if ((int)det == -1)
        return ;
    obj_tmp = obj[id];
    obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
    get_normal_object(&obj_tmp, *ray, det);

//------------------------------------------------------------------------------

    if (obj_tmp.reflexion > 0)
    {
        ray->pos = obj_tmp.collision;
        ray->dir = sub(ray->dir, vector_mult_x(vector_mult_x(obj_tmp.normal,
                dot(obj_tmp.normal, ray->dir)), 2));
        det = check_object(obj, *ray, &id, 5);
        if (det == -1)
            return ;
        color = ray->color;
        obj_tmp = obj[id];
        obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
        get_normal_object(&obj_tmp, *ray, det);
        bump_mapping(&obj_tmp);
        light(e, id, obj_tmp, ray);
    }
//------------------------------------------------------------------------------
    else if (obj_tmp.refraction > 0)
    {
      ray->pos = obj_tmp.collision;
      ray->dir = rayonRefracte(obj_tmp.normal, ray->dir, 1, 0.999);
      det = check_object(obj, *ray, &id, 5);
      if (det == -1)
          return ;
      color = ray->color * 0.5;
      obj_tmp = obj[id];
      obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
      //**********************************************************************//
      if (id)
      {
        ray->pos = obj_tmp.collision;
        //ray->dir = rayonRefracte(obj_tmp.normal, ray->dir, 0.99999, 0.99999);
        ray->dir = rayonRefracte(obj_tmp.normal, ray->dir, 0.999, 1);
        if (det == -1)
            return ;
        color = ray->color * 0.5;
        obj_tmp = obj[id];
        obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
      }

      get_normal_object(&obj_tmp, *ray, det);
      bump_mapping(&obj_tmp);
      light(e, id, obj_tmp, ray);

/*      ray->color = (unsigned int)limit((unsigned char)(obj_tmp.color >> 24) +
            (unsigned char)(ray->color >> 24) / 2) << 24 |
            (unsigned int)limit((unsigned char)(obj_tmp.color >> 16) +
            (unsigned char)(ray->color >> 16) / 2) << 16 |
            (unsigned int)limit((unsigned char)(obj_tmp.color >> 8) +
            (unsigned char)(ray->color >> 8) / 2) << 8 |
            (unsigned int)limit((unsigned char)(obj_tmp.color) +
            (unsigned char) (ray->color)/ 2);*/

      /* Creation rayon transmis avec indice de refraction */
      /* PENSER A INVERSER LE V.N au carree ou faire 1- */
      /*obj_tmp_r = sub(vector_mult_x(ray->dir, 0.5), vector_mult(add(vector_mult_x(vector_mult(ray->dir, obj_tmp.normal), 0.5), sqrtf(-0.75 * vector_mult(vector_mult(ray->dir, obj_tmp.normal), vector_mult(ray->dir, obj_tmp.normal)), obj_tmp.normal)));*/
      /*
      obj_tmp_r = obj_tmp;
      ray->pos = obj_tmp.collision;
      det_reflct = check_object(obj, *ray, &id, 5);
      if (det_reflct == -1)
          return ;
      obj_tmp_r.collision = coordinates_collision(ray->pos, ray->dir, det);
      get_normal_object(&obj_tmp_r, *ray, det);

      obj_tmp_r.refraction = 1;
      ray->color = (unsigned int)limit((unsigned char)(ray->color >> 24) +
            (unsigned char)(ray->color >> 24) / 2) << 24 |
            (unsigned int)limit((unsigned char)(ray->color >> 16) +
            (unsigned char)(ray->color >> 16) / 2) << 16 |
            (unsigned int)limit((unsigned char)(ray->color >> 8) +
            (unsigned char)(ray->color >> 8) / 2) << 8 |
            (unsigned int)limit((unsigned char)(ray->color) +
            (unsigned char) (ray->color)/ 2);
*/
    }
//------------------------------------------------------------------------------
    else
    {
        bump_mapping(&obj_tmp);
        light(e, id, obj_tmp, ray);
    }
}
