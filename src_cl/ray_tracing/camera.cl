
#include "lib_RT_CL.hl"

void    camera(t_cam cam, t_ray *ray, size_t x, size_t y)
{
    float   FOV;
    float   t;

    FOV = 1;

    ray->pos = cam.pos;
    ray->dir.x = ((float)x * FOV - cam.w / 2) / cam.h;
    ray->dir.y = ((float)y * FOV - cam.h / 2) / cam.h;
    ray->dir.z = 1.0f;
    ray->dir = normalize(ray->dir);
    t = ray->dir.y;
    ray->dir.y = t * cosf(cam.rotate.x) - ray->dir.z * sinf(cam.rotate.x);
    ray->dir.z = t * sinf(cam.rotate.x) + ray->dir.z * cosf(cam.rotate.x);
    t = ray->dir.z;
    ray->dir.z = t * cosf(cam.rotate.y) - ray->dir.x * sinf(cam.rotate.y);
    ray->dir.x = t * sinf(cam.rotate.y) + ray->dir.x * cosf(cam.rotate.y);
}
