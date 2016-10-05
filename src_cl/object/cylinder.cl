#include "lib_RT_CL.hl"

void    cylinder(t_obj *obj, t_ray ray)
{
    t_evo   evo;

    evo.a = ray.b.x * ray.b.x + ray.b.z * ray.b.z;
    evo.b = 2 * ((ray.a.x - obj->pos.x) * ray.b.x
        + (ray.a.z - obj->pos.z) * ray.b.z);
    evo.c = (ray.a.x - obj->pos.x) * (ray.a.x - obj->pos.x)
        + (ray.a.z - obj->pos.z) * (ray.a.z - obj->pos.z)
        - obj->radius * obj->radius;
    evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
    if (evo.det > 0)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
        obj->det = (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    else
        obj->det = -1;
}
