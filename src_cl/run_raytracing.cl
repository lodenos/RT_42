__kernel void   run_raytracing(__global char* img)
{
    size_t  id;

    id = get_global_id(0);
    img[id] = '64';
}
