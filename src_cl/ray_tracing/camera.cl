
#include "lib_RT_CL.hl"

void    camera(t_cam cam, t_ray *ray, size_t x, size_t y)
{

    float   FOV;
    float   t;



    FOV = 1;

    ray->a = cam.pos;

    ray->b.x = ((float)x * FOV - cam.w / 2) / cam.h;
    ray->b.y = ((float)y * FOV - cam.h / 2) / cam.h;
    ray->b.z = 1.0f;

    ray->b = normalize(ray->b);


    t = ray->b.y;

    ray->b.y = t * cosf(cam.rotate.x) - ray->b.z * sinf(cam.rotate.x);
    ray->b.z = t * sinf(cam.rotate.x) + ray->b.z * cosf(cam.rotate.x);

    t = ray->b.z;

    ray->b.z = t * cosf(cam.rotate.y) - ray->b.x * sinf(cam.rotate.y);
    ray->b.x = t * sinf(cam.rotate.y) + ray->b.x * cosf(cam.rotate.y);

}
