#include "lib_RT_CL.hl"

float   cylinder(__constant t_obj *obj, t_ray ray)
{
    float   a;
    float   b;
    float   c;
    float   x;
    float   y;

    ray.a -= obj->pos;
    x = dot(ray.b, obj->rotate);
    y = dot(ray.a, obj->rotate);
    a = dot(ray.b, ray.b) - x * x;
    b = dot(ray.a, ray.b) - x * y;
    c = b * b - a * (dot(ray.a, ray.a) - obj->radius * obj->radius - y * y);
    if (c < 0.0f)
		return -1;
    c = sqrt(c);
    return (-b - c > 0) ? -b - c : -b + c;
}
