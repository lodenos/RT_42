#include "lib_RT_CL.hl"

void    run_object(t_obj *obj, t_ray ray)
{
    if (obj->type == 1)
        cone(obj, ray);
    else if (obj->type == 2)
        cylinder(obj, ray);
    else if (obj->type == 3)
        plan(obj, ray);
    else if (obj->type == 4)
        sphere(obj, ray);
}
