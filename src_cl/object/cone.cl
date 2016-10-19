#include "lib_RT_CL.hl"

inline float    cone(constant t_obj *obj, t_ray ray)
{
    float   a;
    float   b;
    float   c;
    float   ta;
    float   tb;
    float   det;


    a = ray.b.x * ray.b.x + ray.b.z * ray.b.z - ray.b.y * ray.b.y *
        obj->angle;
    b = 2.0 * ((ray.a.x - obj->pos.x) * ray.b.x +
        (ray.a.z - obj->pos.z) * ray.b.z -
        (ray.a.y - obj->pos.y) * ray.b.y * obj->angle);
    c = ((ray.a.x - obj->pos.x) * (ray.a.x - obj->pos.x)) +
        ((ray.a.z - obj->pos.z) * (ray.a.z - obj->pos.z)) -
        ((ray.a.y - obj->pos.y) * (ray.a.y - obj->pos.y)) * obj->angle  -
        obj->radius * obj->radius;
    det = b * b - 4.0 * (a * c);
    if (det > 0)
    {
        ta = (-b + sqrt(det)) / (2.0 * a);
        tb = (-b - sqrt(det)) / (2.0 * a);
        return (ta > tb) ? tb : ta;
    }
    return -1;
}
