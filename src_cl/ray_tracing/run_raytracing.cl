#include "lib_RT_CL.hl"

__kernel void   run_raytracing(__global int *img, __constant t_obj *obj,
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

    ray.rgba = obj_tmp.rgba;

    if (obj_tmp.det == -1)
        ray.rgba = (t_rgba){0,0,0,0};


    img[(y * scn->cam.w) + x] = (int)ray.rgba.red << 24 |
            (int)ray.rgba.green << 16 | (int)ray.rgba.blue << 8 |
            (int)ray.rgba.alpha;
}
