
#include "lib_RT_CL.hl"

static float    power(float x, size_t y)
{
    size_t  i;
    float   val;

    i = 0;
    val = x;
    while (++i <= y)
        val *= x;
    return (val);
}

inline float    specular_light(__constant t_spt *spt, t_obj obj)
{
    float3  l;

    l = normalize(spt->pos - obj.collision);
    return (power(dot(-l, l + obj.normal * 2 * dot(-obj.normal, l) ), 50) *
            spt->specular);
}
