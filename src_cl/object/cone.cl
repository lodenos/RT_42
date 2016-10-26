#include "lib_RT_CL.hl"

inline float    cone(constant t_obj *obj, t_ray ray)
{
    float   a;
    float   b;
    float   c;
    float   ta;
    float   tb;
    float   det;


    a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z - ray.dir.y * ray.dir.y *
        obj->angle;
    b = 2.0 * ((ray.pos.x - obj->pos.x) * ray.dir.x +
        (ray.pos.z - obj->pos.z) * ray.dir.z -
        (ray.pos.y - obj->pos.y) * ray.dir.y * obj->angle);
    c = ((ray.pos.x - obj->pos.x) * (ray.pos.x - obj->pos.x)) +
        ((ray.pos.z - obj->pos.z) * (ray.pos.z - obj->pos.z)) -
        ((ray.pos.y - obj->pos.y) * (ray.pos.y - obj->pos.y)) * obj->angle  -
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
