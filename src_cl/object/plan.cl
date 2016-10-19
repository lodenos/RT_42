#include "lib_RT_CL.hl"

float   plan(__constant t_obj *obj, t_ray ray)
{
    float   a;
    float   b;

    if ((a = dot(ray.b, obj->rotate)) <= 0.0f)
        return -1;
    if ((b = -(dot(obj->rotate, ray.a - obj->pos) / a)) <= 0.0f)
        return -1;
    return b;
}
