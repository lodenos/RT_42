
#include "lib_RT_CL.hl"

void    camera(t_cam cam, t_ray *ray, size_t x, size_t y)
{
    ray->a = cam.pos;
    ray->b.x = (float)x - cam.w / 2;
    ray->b.y = (float)y - cam.h / 2;
    ray->b.z = cam.view.z;
    ray->b = normalize(ray->b - ray->a);
}
