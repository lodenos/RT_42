#include "lib_RT_CL.hl"

inline t_ray    diffused_light(t_ray ray, __global t_spt *spt, t_obj obj)
{
    float  z;

    z = -(dot(normalize(obj.collision - spt->pos), obj.normal) * spt->diffuse);
    ray.color = (unsigned int)limit_rgba((((unsigned char)(ray.color >> 24) +
            (unsigned char)(spt->color >> 24)) / 2) * z) << 24 |
            (unsigned int)limit_rgba((((unsigned char)(ray.color >> 16) +
            (unsigned char)(spt->color >> 16)) / 2) * z) << 16 |
            (unsigned int)limit_rgba((((unsigned char)(ray.color >> 8) +
            (unsigned char)(spt->color >> 8)) / 2) * z) << 8 |
            (unsigned int)limit_rgba((((unsigned char)ray.color +
            (unsigned char)spt->color) / 2) * z);
    return ray;
}
