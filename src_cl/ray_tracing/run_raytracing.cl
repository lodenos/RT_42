
#include "lib_RT_CL.hl"

static void     get_normal_object(t_obj *obj, t_ray ray, float det)
{
    switch(obj->type)
    {
        case CONE :
            obj->normal = -normalize(obj->pos - obj->collision - obj->rotate *
                (dot(ray.dir, obj->rotate) * det + dot(ray.pos, obj->rotate)))
                * ((1.0f + tan(obj->angle / 2) * tan(obj->angle / 2)));
            return ;
        case CYLINDER :
            obj->normal = -normalize(obj->pos - obj->collision - obj->rotate *
                    (dot(ray.dir, obj->rotate) * det +
                    dot(ray.pos, obj->rotate)));
            return ;
        case PLAN :
            obj->normal = obj->rotate;
            return ;
        case SPHERE :
            obj->normal = normalize(obj->collision - obj->pos);
            return ;
        case TORUS :
            obj->normal = (float3)(0, 0, 0);
            return ;
        default:
            obj->normal = (float3)(0, 0, 0);
            return ;
    }
}

__kernel void   run_raytracing(__global unsigned int *img, __constant t_obj *obj,
        __constant t_scn *scn, __constant t_spt *spt)
{
    float   blue        = 0;
    float   det;
    float   div;
    float   green       = 0;
    size_t  i           = 0;
    size_t  id          = 0;
    size_t  j;
    size_t  max;
    t_obj   obj_tmp;
    float2  pos;
    t_ray   ray;
    float   red         = 0;
    size_t  resolution  = 1;
    size_t  x           = get_global_id(0);
    size_t  y           = get_global_id(1);
    /*float   reflct;
    t_ray   tmp_ray;*/

    pos.x = (float)x;
    pos.y = (float)y;
    div = 1.0f / (float)resolution;
    max = resolution * resolution;
    while (i < resolution)
    {
        j = 0;

        while (j < resolution)
        {
            camera(scn->cam, &ray, pos.x, pos.y);
            det = check_object(obj, &ray, &id);
            if (det == -1)
            {
                img[(y * scn->cam.w) + x] = 0x0;
                return ;
            }
            obj_tmp = obj[id];
            obj_tmp.collision = ray.pos + ray.dir * det;
            get_normal_object(&obj_tmp, ray, det);

            /*tmp_ray.pos = obj[id].collision;
            tmp_ray.dir = reflection(&obj[id], &ray);
            reflct = check_object(obj, &tmp_ray, &id);
            if (reflct != -1)
            {

              light(id, obj, obj_tmp, &tmp_ray, scn, spt);
              light(id, obj, obj_tmp, &ray, scn, spt);
              ray.color =
              (unsigned int)(((float)(unsigned char)(ray.color >> 24) * 0.5f + (float)(unsigned char)(tmp_ray.color >> 24)) / (2.0f * (1.0f + 0.5f))) << 24 |
              (unsigned int)(((float)(unsigned char)(ray.color >> 16) * 0.5f + (float)(unsigned char)(tmp_ray.color >> 16)) / (2.0f * (1.0f + 0.5f))) << 24 |
              (unsigned int)(((float)(unsigned char)(ray.color >> 8) * 0.5f + (float)(unsigned char)(tmp_ray.color >> 8)) / (2.0f * (1.0f + 0.5f))) << 24 |
              (unsigned int)0xFF;

            }
            else*/
              light(id, obj, obj_tmp, &ray, scn, spt);
            red += (float)(((unsigned char)(ray.color >> 24)));
            green += (float)(((unsigned char)(ray.color >> 16)));
            blue += (float)(((unsigned char)(ray.color >> 8)));
            pos.x += div;
            ++j;
        }
        pos.x = (float)x;
        pos.y += div;
        ++i;
    }
    ray.color = (unsigned int)((unsigned char)(red / (float)max)) << 24 |
            (unsigned int)((unsigned char)(green / (float)max)) << 16 |
            (unsigned int)((unsigned char)(blue / (float)max)) << 8 | 0xFF;
    img[(y * scn->cam.w) + x] = ray.color ;
}
