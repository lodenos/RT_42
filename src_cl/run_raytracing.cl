typedef struct  s_evo
{
    float       a;
    float       b;
    float       c;
    float       det;
    float       ta;
    float       tb;
}               t_evo;

typedef struct  s_ray
{
    float3      a;
    float3      b;
}               t_ray;

typedef struct  s_obj
{
    float3      pos;
    float       radius;
    float3      rotate;
}               t_obj;

float sphere(t_obj obj, t_ray ray)
{
    t_evo   evo;
    float3  tmp;

    evo.a = dot(ray.b, ray.b);
    tmp = ray.a - obj.pos;
    evo.b = 2.0 * dot(ray.b, tmp);
    evo.c = dot(tmp, tmp) - obj.radius * obj.radius;
    evo.det = evo.b * evo.b - 4.0 * evo.a * evo.c;
    if (evo.det >= 0.0f)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2.0 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2.0 * evo.a);
        return (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    return -1;
}

kernel void         run_raytracing(global int *img)
{
    size_t  id;
    t_obj   obj;
    t_ray   ray;
    int  x;
    int  y;

    id = get_global_id(0);

    obj.pos = (float3)(0.0f, 0.0f, -500.0f);
    obj.radius = 50;
    ray.a = (float3)(0.0f, 0.0f, 0.0f);

    x = (id + 1) % 1920;
    y = (id + 1) / 1080;

    ray.b.x = x - 1920 / 2;
    ray.b.y = y - 1080 / 2;
    ray.b.z = 1000;

    ray.b = normalize(ray.b - ray.a);
 
    if (sphere(obj, ray) != -1)
        img[id] = 0xFFFF;
}
