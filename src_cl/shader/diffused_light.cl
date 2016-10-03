#include "lib_RT_CL.hl"

void    diffused_light(t_ray *ray, t_spt spt, t_obj obj)
{
    float3  l;
    double  z;

    l = normalize(obj.collision - spt.pos);
    z = -dot(l, obj.normal) * diffuse;
}
