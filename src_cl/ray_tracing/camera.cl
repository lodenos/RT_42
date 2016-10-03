#include "lib_RT_CL.cl"

void    camera(t_cam cam, t_ray *ray, size_t id)
{
    int x;
    int y;

    x = (id + 1) % cam.w;
    y = (id + 1) / cam.w;
    ray->a = cam.pos;
    ray->b.x = (int)x - cam.w / 2;
    ray->b.y = (int)y - cam.h / 2;
    ray->b.z = cam.view.z;
    ray.b = normalize(ray->b - ray->a);
}
