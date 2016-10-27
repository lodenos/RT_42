
#include "lib_RT_CL.hl"

inline void bump_mapping(t_obj *obj)
{
    switch(obj->type_bump)
    {
        case 0 :
            return ;
        case 1 :
            obj->normal -= sin(obj->collision - obj->pos) * 0.1f;
            return ;
        case 2 :


            if ((int)(obj->collision.x + obj->collision.y + obj->collision.z -
                    obj->pos.x + obj->pos.y + obj->pos.z) % 2)
                obj->color /= 2;

            return ;
        default :
            return ;
    }
}
