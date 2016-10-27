
#include "lib_RT_CL.hl"

/*  TODO add worker */

inline float    check_object(__constant t_obj *obj, t_ray *ray, size_t *id, size_t mask)
{
    int     i;
    float   tmp_det;
    float   det;

    i = -1;
    *id = 0;
    tmp_det = 20000.0;
    while (obj[++i].end)
    {
        if (i == mask)
            continue ;
        det = run_object(&obj[i], *ray);
        if (0 < det && det < tmp_det)
        {
            tmp_det = det;
            *id = (size_t)i;
        }
    }
    if (tmp_det == 20000)
        return -1;
    return (tmp_det);
}
