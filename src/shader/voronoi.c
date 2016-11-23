#include "lib_RT.h"

cl_float2 random2(cl_float2 c)
{
    float j = 4906.0*sin(dot_vec(c,(cl_float2){200.7, 5.8}));
    cl_float2 r;
    r.x = fract(512.0 * j);
    j *= .125;
    r.y = fract(512.0*j);
    return (sub_vec_lol(r,0.5));
}


float smooth_voronoi(cl_float2 x)
{
    cl_float2 lol;
    cl_float2 b;
    cl_float2 p = (cl_float2){floor(x.x), floor(x.y)};
    cl_float2 f = fract_vec( x );

    float res = 0.0;
    for( int j=-1; j<=1; j++ )
        for( int i=-1; i<=1; i++ )
        {
            b = ((cl_float2){i, j});
            lol = add_vec(p, b);
            cl_float2  r = add_vec(sub_vec(b,f), random2(lol));
            float d = dot_vec( r, r );

            res += 1.0/pow( d, 8.0 );
        }
    return pow( 1.0/res, 1.0/8.0 );
}
