#include "lib_RT_CL.hl"

void    plan(t_obj *obj, t_ray ray)
{
    float3  tmp_v;
    float3  origine;
    float   det;
    float   d;
    float3  normal;

    origine.x = 0;
    origine.y = 0;
    origine.z = 0;

    tmp_v = obj->pos - origine;
    normal = normalize(obj->rotate);
    d = sqrt(dot(tmp_v, tmp_v));
    det = -(normal.x * ray.a.x + normal.y * ray.a.y + normal.z * ray.a.z + d)
        / (normal.x * ray.b.x + normal.y * ray.b.y + normal.z * ray.b.z);
    obj->det = (det < 0) ? -1 : det;
}
