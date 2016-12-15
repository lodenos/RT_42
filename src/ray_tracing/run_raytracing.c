/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 14:51:35 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

inline cl_float3	rayon_refracte(cl_float3 normal, cl_float3 incident,
		float n1, float n2)
{
	float		n;
	cl_float3	inv;
	float		cos_t;
	float		cos_i;
	cl_float3	t;

	n = (n1 / n2) * sin(n1 / n2);
	inv = reverse(incident);
	cos_i = dot(normal, inv);
	cos_t = sqrt(1 - n * n * (1 - (cos_i * cos_i)));
	if (cos_i > 0)
		t = add(vector_mult_x(normal, (cos_i * n - cos_t)),
			vector_mult_x(incident, n));
	else
		t = add(vector_mult_x(normal, (cos_i * n + cos_i)),
			vector_mult_x(incident, n));
	return (t);
}

inline void			get_normal_object_sub(t_obj *obj, register t_ray ray,
		register float det)
{
	register float		k;
	register float		m;
	register cl_float3	a;

	(void)det;
	k = dot(sub(obj->collision, obj->pos_a), ray.dir);
	a = sub(obj->collision, vector_mult_x(ray.dir, k));
	m = sqrt(pow(obj->radius_b.x, 2.0f) - (k * k));
	obj->normal = normalize(sub(sub(obj->collision, a),
		vector_mult_x(sub(obj->pos_a, a), (m / (obj->radius_a.x + m)))));
}

inline void			get_normal_object(t_obj *obj, register t_ray ray,
		register float det)
{
	if (obj->type == CONE)
		obj->normal = reverse(normalize(sub(obj->pos_a,
			sub(obj->collision, vector_mult_x(vector_mult_x(
			obj->rotate, dot(ray.dir, obj->rotate) * det +
			dot(ray.pos, obj->rotate)), (1.0f + tanf(obj->angle / 2.0f) *
			tanf(obj->angle / 2.0f)))))));
	else if (obj->type == CYLINDER)
		obj->normal = reverse(normalize(sub(obj->pos_a, sub(obj->collision,
					vector_mult_x(obj->rotate, dot(ray.dir, obj->rotate) * det +
					dot(ray.pos, obj->rotate))))));
	else if (obj->type == PLAN)
		obj->normal = obj->rotate;
	else if (obj->type == TRIANGLE)
		obj->normal = normalize(cross(sub(obj->pos_b, obj->pos_a),
			sub(obj->pos_c, obj->pos_a)));
	else if (obj->type == SPHERE)
		obj->normal = normalize(sub(obj->collision, obj->pos_a));
	else if (obj->type == ELLIPSOID)
		obj->normal = normalize(get_ellipsoid_normale(obj, det));
	else if (obj->type == TORUS)
		get_normal_object_sub(obj, ray, det);
}

void				run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
{
	register float	det;
	size_t			id;
	t_obj			obj_tmp;
	int				i;

	i = 0;
	ray->color = 0x0;
	det = check_object(obj, *ray, &id, NO_MASK);
	if ((int)det == -1)
		return ;
	obj_tmp = obj[id];
	obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
	get_normal_object(&obj_tmp, *ray, det);
	if (obj_tmp.reflexion > 0)
		reflexion(e, ray, obj_tmp, id);
	else if (obj_tmp.refraction > 0)
		refraction(e, ray, obj_tmp, id);
	else
	{
		bump_mapping(&obj_tmp);
		light(e, id, obj_tmp, ray);
	}
}
