
#include "lib_RT_CL.hl"

void    get_normal_object(t_obj *obj, t_ray ray)
{
    if (obj->type == CONE)
        return ;
    else if (obj->type == CYLINDER)
        obj->normal = -normalize(obj->pos - obj->collision - obj->rotate *
                (dot(ray.b, obj->rotate) * obj->det + dot(ray.a, obj->rotate)));
    else if (obj->type == PLAN)
        obj->normal = obj->rotate;
    else if (obj->type == SPHERE)
        obj->normal = normalize(obj->collision - obj->pos);
    else if (obj->type == TORUS)
        return ;
}

__kernel void   run_raytracing(__global unsigned int *img, __constant t_obj *obj,
        __global t_scn *scn, __global t_spt *spt)
{
    size_t  id      = 0;
    t_ray   ray;
    size_t  x       = get_global_id(0);
    size_t  y       = get_global_id(1);
    t_obj   obj_tmp;
    float   det;

    camera(scn->cam, &ray, x, y);
    det = check_object(obj, &ray, &id);

    obj_tmp = obj[id];

    obj_tmp.collision = ray.a + ray.b * obj_tmp.det;

    obj_tmp.det = det;

    get_normal_object(&obj_tmp, ray);


    if (det >= 0.0f)
    {
        ray.color = obj_tmp.color;
        ray = diffused_light(ray, &spt[0], obj_tmp);
    }
    else
        ray.color = 0x0;

    img[(y * scn->cam.w) + x] = ray.color;
}
