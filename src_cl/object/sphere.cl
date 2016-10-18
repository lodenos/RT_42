#include "lib_RT_CL.hl"

float   sphere(__constant t_obj *obj, t_ray ray)
{
    float   b;
    float   c;

    ray.a -= obj->pos;
    b = dot(ray.a, ray.b);
    c = dot(ray.a, ray.a) - obj->radius * obj->radius;
    c = b * b - c;
    if (c < 0.0f)
		return -1;
    c = sqrt(c);
    return (-b - c > 0) ? -b - c : -b + c;
}
