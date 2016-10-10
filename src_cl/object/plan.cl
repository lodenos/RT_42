#include "lib_RT_CL.hl"

float   plan(__global t_obj *obj, t_ray ray)
{
    float3  tmp_v;
    float3  origine;
    float   det;
    float   d;
    float3  normal;

    origine = (float3)(0.0, 0.0, 0.0);

    tmp_v = obj->pos - origine;
    normal = normalize(obj->rotate);
    d = sqrt(dot(tmp_v, tmp_v));
    det = -(normal.x * ray.a.x + normal.y * ray.a.y + normal.z * ray.a.z + d)
        / (normal.x * ray.b.x + normal.y * ray.b.y + normal.z * ray.b.z);
    return (det < 0) ? -1 : det;
}
