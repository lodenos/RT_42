#include "lib_RT_CL.hl"

float   sphere(t_obj obj, t_ray ray)
{
    t_evo   evo;
    float3  tmp;

    evo.a = dot(ray.b, ray.b);
    tmp = ray.a - obj.pos;
    evo.b = 2.0 * dot(ray.b, tmp);
    evo.c = dot(tmp, tmp) - obj.radius * obj.radius;
    evo.det = evo.b * evo.b - 4.0 * evo.a * evo.c;
    if (evo.det >= 0.0f)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2.0 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2.0 * evo.a);
        return (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    return -1;
}
