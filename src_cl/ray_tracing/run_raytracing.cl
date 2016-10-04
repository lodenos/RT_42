#include "lib_RT_CL.hl"

kernel void run_raytracing(global env e, global int *img)
{
    size_t  id;
    t_ray   ray;
    
    id = get_global_id(0);
    camera(e.cam, &ray, id);

    if ((e.obj.det = sphere(e.obj, ray)) != -1)
    {

        ray.b.x *= e.obj.det;
        ray.b.y *= e.obj.det;
        ray.b.z *= e.obj.det;

        e.obj.collision = ray.a + ray.b;
        e.obj.normal = e.obj.collision;
        light(&e, &ray, e.c_diff, 1);
        img[id] = ray.rgba.red * 255;
    }
    else
        img[id] = 0x00001AFF;
}
