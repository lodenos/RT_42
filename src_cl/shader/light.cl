
#include "lib_RT_CL.hl"

/*  TODO Le merge des couleur des multi-spot    */

void    light(size_t id, __constant t_obj *obj, t_obj obj_tmp, t_ray *ray,
        __constant t_scn *scn,  __constant t_spt *spt)
{
    size_t  i       = 0;
    size_t  index;
    t_ray   ray_spot;
    float   z       = 0.0f;
    float   tmp;
    int     np      = 0;
    float   det;
    float   red     = 0;
    float   green   = 0;
    float   blue    = 0;

    while (spt[i].end)
    {
        index = 0;
        ray->color = obj_tmp.color;
        ray_spot.pos = spt[i].pos;
        ray_spot.dir = normalize(obj_tmp.collision - ray_spot.pos);
        det = check_object(obj, &ray_spot, &index);
        if ((det == -1) || (id == index))
        {
            diffused_light(ray, &spt[i], obj_tmp);
            tmp = specular_light(&spt[i], obj_tmp);
            if (tmp >= z)
            {
                z = tmp;
                np = i;
            }
        }
        else
            ray->color = 0x0;
        red += (float)(unsigned char)(ray->color >> 24);
        green += (float)(unsigned char)(ray->color >> 16);
        blue += (float)(unsigned char)(ray->color >> 8);
        ++i;
    }
    ray->color = (unsigned int)(unsigned char)(red / scn->n_spt) << 24 |
            (unsigned int)(unsigned char)(green / scn->n_spt) << 16 |
            (unsigned int)(unsigned char)(blue / scn->n_spt) << 8 | 0xFF;
    if (z > 0.0f)
    {
        ray->color = limit((float)(unsigned char)(ray->color >> 24) +
                (float)(unsigned char)(spt->color >> 24) * z) << 24 |
                limit((float)(unsigned char)(ray->color >> 16) +
                (float)(unsigned char)(spt->color >> 16) * z) << 16 |
                limit((float)(unsigned char)(ray->color >> 8) +
                (float)(unsigned char)(spt->color >> 8) * z) << 8 | 0xFF;
    }
}
