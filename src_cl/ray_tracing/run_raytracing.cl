#include "lib_RT_CL.hl"

inline void     get_normal_object(t_obj *obj, t_ray ray)
{
    if (obj->type == 1)
        obj->normal = normalize(obj->collision - obj->pos);
/*        obj->normal = vector_reverse(vector_normalize(vector_sub(obj->pos,
                vector_sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, vector_scalar(ray.b, obj->rotate) * obj->det +
                vector_scalar(ray.a, obj->rotate)), (1.0 + tanf(obj->angle / 2)
                * tanf(obj->angle / 2)))))));*/
    else if (obj->type == 2)
    {
        obj->normal = normalize(obj->collision - obj->pos);
/*        obj->normal = vector_reverse(vector_normalize(vector_sub(obj->pos,
                vector_sub(obj->collision, vector_mult_x(obj->rotate,
                vector_scalar(ray.b, obj->rotate) * obj->det +
                vector_scalar(ray.a, obj->rotate))))));*/
    }
    else if (obj->type == 3)
        obj->normal = normalize(obj->rotate);
    else if (obj->type == 4)
        obj->normal = normalize(obj->collision - obj->pos);
}

__kernel void   run_raytracing(__global int *img, __global t_obj *obj,
        __global t_scn *scn, __global t_spt *spt)
{
    size_t  id      = 0;
    t_ray   ray;
    size_t  x       = get_global_id(0);
    size_t  y       = get_global_id(1); 
    t_obj   obj_tmp;

    ray.rgba = (t_rgba){0, 0, 0, 255};
    camera(scn->cam, &ray, x, y);
    obj_tmp.det = check_object(obj, &ray, &id);

    obj_tmp.type = obj[id].type;
    obj_tmp.rotate = obj[id].rotate;
    obj_tmp.pos = obj[id].pos;
    obj_tmp.collision = ray.a + ray.b * obj_tmp.det;
    obj_tmp.rgba = obj[id].rgba;
    get_normal_object(&obj_tmp, ray);

    ray.rgba = obj_tmp.rgba;
    diffused_light(&ray, &spt[0], &obj_tmp);

    img[(y * scn->cam.w) + x] = (int)ray.rgba.red << 24 |
            (int)ray.rgba.green << 16 | (int)ray.rgba.blue << 8 |
            (int)ray.rgba.alpha;
}
