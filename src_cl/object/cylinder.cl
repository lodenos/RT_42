#include "lib_RT_CL.hl"

float   cylinder(__global t_obj *obj, t_ray ray)
{
    t_evo   evo;

    evo.a = ray.b.x * ray.b.x + ray.b.z * ray.b.z;
    evo.b = 2.0 * ((ray.a.x - obj->pos.x) * ray.b.x
        + (ray.a.z - obj->pos.z) * ray.b.z);
    evo.c = (ray.a.x - obj->pos.x) * (ray.a.x - obj->pos.x)
        + (ray.a.z - obj->pos.z) * (ray.a.z - obj->pos.z)
        - obj->radius * obj->radius;
    evo.det = evo.b * evo.b - 4.0 * evo.a * evo.c;
    if (evo.det > 0)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2.0 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2.0 * evo.a);
        return (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    return -1;
}
