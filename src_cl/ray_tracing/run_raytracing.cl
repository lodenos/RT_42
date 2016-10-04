#include "lib_RT_CL.hl"

static void     get_normal_object(t_obj *obj, t_ray ray)
{
    if (obj->type == 1)
        obj->normal = vector_reverse(vector_normalize(vector_sub(obj->pos,
                vector_sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, vector_scalar(ray.b, obj->rotate) * obj->det +
                vector_scalar(ray.a, obj->rotate)), (1 + tan(obj->angle / 2) *
                tan(obj->angle / 2)))))));
    else if (obj->type == 2)
        obj->normal = vector_reverse(normalize(vector_sub(obj->pos,
                vector_sub(obj->collision, vector_mult_x(obj->rotate,
                dot(ray.b, obj->rotate) * obj->det +
                dot(ray.a, obj->rotate))))));
    else if (obj->type == 3)
        obj->normal = normalize(obj->rotate);
    else if (obj->type == 4)
        obj->normal = normalize(obj->collision - obj->pos);
}

__kernel void   run_raytracing(__global t_scn scn, __global size_t *img)
{
    size_t  id;
    t_ray   ray;
    size_t  wk;

    wk = get_global_id(0);
    camera(e.cam, &ray, id);
    ray.rgba = (t_rgba){0, 0, 0, 255};
    id = check_object(scn.obj, ray);
    if (scn.obj[id].det != -1)
    {
        scn.obj[id].collision = coordinates_collision(ray.a, ray.b,
                scn.obj[id].det);
        get_normal_object(&scn.obj[id], ray);
        light(e, &ray, scn.c_diff, id);
    }
    img[wk] = 0xFF00FFFF;
}
