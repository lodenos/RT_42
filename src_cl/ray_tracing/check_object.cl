#include "lib_RT_CL.hl"

/*  TODO add worker */

size_t  check_object(t_obj *obj, t_ray *ray)
{
    int     i;
    size_t  id;
    float   tmp_det;

    i = -1;
    id = 0;
    tmp_det = 20000;
    ray->rgba = (t_rgba){0, 0, 0, 255};
    while (obj[++i].end)
    {
        run_object(&obj[i], *ray);
        if (0 <= obj[i].det && obj[i].det <= tmp_det)
            tmp_det = obj[(id = (size_t)i)].det;
    }
    return (id);
}
