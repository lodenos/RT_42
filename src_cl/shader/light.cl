#include "lib_RT_CL.hl"

void    light(env *e, t_ray *ray, t_rgba *c_diff, size_t id_obj)
{
    diffused_light(ray, e->spt, e->obj);
}
