#include "lib_RT_CL.hl"

inline float    run_object(__constant t_obj *obj, t_ray ray)
{
    if (obj->type == 1)
        return cone(obj, ray);
    else if (obj->type == 2)
        return cylinder(obj, ray);
    else if (obj->type == 3)
        return plan(obj, ray);
    else if (obj->type == 4)
        return sphere(obj, ray);
}
