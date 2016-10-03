#include "lib_RT_CL.hl"

kernel void         run_raytracing(global int *img)
{
    size_t  id;
    t_obj   obj;
    t_ray   ray;
      x;
    int  y;
    
    id = get_global_id(0);

    obj.pos = (float3)(0.0f, 0.0f, -500.0f);
    obj.radius = 100;
    ray.a = (float3)(0.0f, 0.0f, 0.0f);

    x = (id + 1) % 1920;
    y = (id + 1) / 1920;

    ray.b.x = x - 1920 / 2;
    ray.b.y = y - 1080 / 2;
    ray.b.z = 1000;

    ray.b = normalize(ray.b - ray.a);

    if (sphere(obj, ray) != -1)
        img[id] = 0xFFFF;
}
