
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
            ray.pos -= obj->pos_a;
            x = dot(ray.dir, obj->rotate);
            y = dot(ray.pos, obj->rotate);
            a = dot(ray.dir, ray.dir) - x * x;
            b = dot(ray.dir, ray.dir) - x * y;
            c = b * b - a * dot(ray.pos, ray.pos) - obj->radius_a.x * obj->radius_a.x
                - y * y;
            if (c < 0.0f)
                return -1.0f;
            c = sqrt(c);
            return (-b - c > 0) ? -b - c : -b + c;
        case PLAN :
            if ((a = dot(ray.dir, obj->rotate)) < 0.0f)
            {
                if ((a = dot(ray.dir, -obj->rotate)) < 0.0f)
                    return -1.0f;
                if ((b = -(dot(-obj->rotate, ray.pos - obj->pos_a) / a)) < 0.0f)
                    return -1.0f;
                return b;
            }
            if ((b = -(dot(obj->rotate, ray.pos - obj->pos_a) / a)) < 0.0f)
                return -1.0f;
            return b;
        case SPHERE :
            ray.pos -= obj->pos_a;
            b = dot(ray.pos, ray.dir);
            c = b * b - (dot(ray.pos, ray.pos) - obj->radius_a.x * obj->radius_a.x);
            if (c < 0.0f)
    	       return -1.0f;
            c = sqrt(c);
            return (-b - c > 0) ? -b - c : -b + c;
        case TORUS :
            return -1.0f;
        default :
            return -1.0f;
    }
    return -1.0f;
}
