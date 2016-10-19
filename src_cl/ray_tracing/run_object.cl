#include "lib_RT_CL.hl"

inline float    run_object(constant t_obj *obj, t_ray ray)
{
    float   a;
    float   b;
    float   c;
    float   x;
    float   y;

    switch(obj->type)
    {
        case CONE :
            return cone(obj, ray);
        case CYLINDER :
            ray.a -= obj->pos;
            x = dot(ray.b, obj->rotate);
            y = dot(ray.a, obj->rotate);
            a = dot(ray.b, ray.b) - x * x;
            b = dot(ray.a, ray.b) - x * y;
            c = b * b - a * (dot(ray.a, ray.a) - obj->radius * obj->radius
                - y * y);
            if (c < 0.0f)
                return -1;
            c = sqrt(c);
            return (-b - c > 0) ? -b - c : -b + c;
        case PLAN :
            if ((a = dot(ray.b, obj->rotate)) <= 0.0f)
                return -1;
            if ((b = -(dot(obj->rotate, ray.a - obj->pos) / a)) <= 0.0f)
                return -1;
            return b;
        case SPHERE :
            ray.a -= obj->pos;
            b = dot(ray.a, ray.b);
            c = b * b - (dot(ray.a, ray.a) - obj->radius * obj->radius);
            if (c < 0.0f)
    	       return -1;
            c = sqrt(c);
            return (-b - c > 0) ? -b - c : -b + c;
        case TORUS :
            return -1;
        default :
            return -1;
    }
    return -1;
}
