#include "lib_RT_CL.hl"

void    light(t_scn *scn, t_ray *ray, t_rgba *c_diff, size_t id_obj)
{
    diffused_light(ray, scn->spt[0], scn->obj[0]);
}
