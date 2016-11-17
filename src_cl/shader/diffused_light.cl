
#include "lib_RT_CL.hl"

inline void diffused_light(t_ray *ray, __constant t_spt *spt, t_obj obj)
{
    float   z;

    z = -(dot(normalize(obj.collision - spt->pos), obj.normal) * 1);
    ray->color = (unsigned int)limit((((unsigned char)(ray->color >> 24) *
            (unsigned char)(spt->color >> 24)) / 255) * z) << 24 |
            (unsigned int)limit((((unsigned char)(ray->color >> 16) *
            (unsigned char)(spt->color >> 16)) / 255) * z) << 16 |
            (unsigned int)limit((((unsigned char)(ray->color >> 8) *
            (unsigned char)(spt->color >> 8)) / 255) * z) << 8 |
            (unsigned int)limit((((unsigned char)ray->color *
            (unsigned char)spt->color) / 255) * z);
}
