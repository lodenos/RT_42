#include "lib_RT_CL.hl"

static void     get_normal_object(t_obj *obj, t_ray ray)
{
    if (obj->type == 1)
        obj->normal = normalize(obj->collision - obj->pos);
    else if (obj->type == 2)
        obj->normal = normalize(obj->collision - obj->pos);
    else if (obj->type == 3)
        obj->normal = normalize(obj->rotate);
    else if (obj->type == 4)
        obj->normal = normalize(obj->collision - obj->pos);
}

__kernel void   run_raytracing(__global t_scn *scn, __global size_t *img)
{
    size_t  wk;

    wk = get_global_id(0);
    img[wk] = 255 * 255 * (scn->n_obj * 100);
}
