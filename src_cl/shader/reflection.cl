#include "lib_RT_CL.hl"

inline float3 reflection(__constant t_obj *obj, t_ray *ray)
{
    float3 reflct;

    reflct = ray->dir - 2 * dot(ray->dir, obj->normal) * obj->normal;

    return (reflct);
}
