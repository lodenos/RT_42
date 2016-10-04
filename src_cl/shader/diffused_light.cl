#include "lib_RT_CL.hl"

void    diffused_light(t_ray *ray, t_spt spt, t_obj obj)
{
    float3  l;
    float   z;

    l = normalize(obj.collision - spt.pos);
    z = dot(l, obj.normal);
    // TODO Corrige Ambient
    ray->rgba.red = limit_rgba(((ray->rgba.red + spt.rgba.red) / 2) * z);
    ray->rgba.green = limit_rgba(((ray->rgba.green + spt.rgba.green) / 2) * z);
    ray->rgba.blue = limit_rgba(((ray->rgba.blue + spt.rgba.blue) / 2) * z);
}
