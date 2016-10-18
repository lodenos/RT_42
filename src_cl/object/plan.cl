#include "lib_RT_CL.hl"

float   plan(__constant t_obj *obj, t_ray ray)
{
    float3  tmp_v;
    float3  origine;
    float   det;
    float   d;
    float3  normal;

    origine = (float3)(0.0, 0.0, 0.0);
    tmp_v = obj->pos - origine;
    normal = normalize(obj->rotate);

    det = -(dot(normal, ray.a) + sqrt(dot(tmp_v, tmp_v))) / dot(normal, ray.b);
    return (det < 0) ? -1 : det;
}
