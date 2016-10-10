/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_RT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:02:05 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/09 01:17:24 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RT_H
#define LIB_RT_H
#include <libft.h>
#include <OpenCL/cl.h>
#include <pthread.h>
#include <SDL2/SDL.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define TITLE "RT"
#define WIDTH 1920
#define HEIGHT 1080

typedef struct sockaddr_in  sockaddr_in;
typedef struct sockaddr     sockaddr;

typedef struct              s_evo       /**/
{
    float                   a;          /**/
    float                   b;          /**/
    float                   c;          /**/
    float                   det;        /**/
    float                   ta;         /**/
    float                   tb;         /**/
}                           t_evo;      /**/

typedef struct              s_img       /* Window & Image SDL           */
{
    Uint32                  flags;      /* Flag Window                  */
    size_t                  h;          /* Resolution height y          */
    int                     *img;       /* Image buffer OpenCL          */
    SDL_Renderer            *rend;      /* Renderer Image               */
    SDL_Window              *win;       /* Window                       */
    size_t                  w;          /* Resolution width x           */
    size_t                  x;          /* Position pixel screen x      */
    size_t                  y;          /* Positiom pixel screen y      */
}                           t_img;

typedef struct              s_rgba      /* Color                        */
{
    unsigned char           red;        /* Red   0 - 255                */
    unsigned char           green;      /* Green 0 - 255                */
    unsigned char           blue;       /* Blue  0 - 255                */
    unsigned char           alpha;      /* Alpha 0 - 255                */
}                           t_rgba;

typedef struct              s_cam       /* Camera                       */
{
    float                   fov;        /* FOV                          */
    size_t                  h;          /* Resolution screen view x     */
    cl_float3               pos;        /* Position canera              */
    cl_float3               rotate;     /* Angle of rotation            */
    cl_float3               view;       /* Positon view scren {0, 0}    */
    size_t                  w;          /* Resolution screen view y     */
}                           t_cam;

typedef struct              s_ray       /* Ray                          */
{
    cl_float3               a;          /* Point Start                  */
    cl_float3               b;          /* Point reach                  */
    size_t                  max;        /* Maximun reflexion            */
    struct s_rgba           rgba;       /* Calor of the ray             */
}                           t_ray;

typedef struct              s_obj       /* Object                       */
{
    float                   angle;      /* Angle                        */
    cl_float3               collision;  /* Point collision ray          */
    float                   det;        /* Determinant matrice          */
    char                    end;        /* 1 -> next ; 0 -x end         */
    size_t                  id;         /* Id Group                     */
    cl_float3               normal;     /* Vector Normal                */
    cl_float3               pos;        /* Position Object              */
    float                   radius;     /* radius of the object         */
    struct s_rgba           rgba;       /* Calors of the object         */
    cl_float3               rotate;     /* Angle of rotation            */
    size_t                  type;       /* Type Object                  */
}                           t_obj;

typedef struct              s_key       /* Keyboard for key repet       */
{
    _Bool                   key_a;      /**/
    _Bool                   key_comma;  /**/
    _Bool                   key_d;      /**/
    _Bool                   key_down;   /**/
    _Bool                   key_left;   /**/
    _Bool                   key_lshift; /**/
    _Bool                   key_point;  /**/
    _Bool                   key_right;  /**/
    _Bool                   key_s;      /**/
    _Bool                   key_space;  /**/
    _Bool                   key_up;     /**/
    _Bool                   key_w;      /**/
}                           t_key;

typedef struct              s_krnl      /* Struct Kernel OpenCL             */
{
    cl_kernel               run_raytracing; /* Function Kernel run_raytracing */
}                           t_krnl;

typedef struct              s_opcl      /**/
{
    char                    **file;     /**/
    char                    **src;      /**/
    size_t                  *size_src;  /**/
    char                    *flags;     /**/
    cl_device_id            device_id;  /**/
    cl_context              contx;      /**/
    cl_command_queue        cmd_que;    /**/
    struct s_krnl           krnl;       /**/
    cl_uint                 nbr_src;    /**/
    cl_program              prog;       /**/
    cl_platform_id          platf_id;   /**/
    cl_uint                 num_device; /**/
    cl_uint                 num_platf;  /**/
    cl_int                  err;        /**/
}                           t_opcl;     /**/

typedef struct              s_spt       /**/
{
    float                   ambient;    /**/
    float                   diffuse;    /**/
    char                    end;        /**/
    size_t                  id;         /**/
    float                   light;      /**/
    cl_float3               pos;        /**/
    struct s_rgba           rgba;       /**/
    float                   specular;   /**/
}                           t_spt;

typedef struct              s_scn
{
    struct s_rgba           *c_diff;    /* Struct *color diffuse    */
    struct s_cam            cam;        /* Struct camera            */
    size_t                  n_obj;      /* Number object            */
    size_t                  n_spt;      /* Number spotlight         */
    struct s_obj            *obj;       /* Struct Object            */
    struct s_spt            *spt;       /* Struct Spotlight         */
}                           t_scn;

typedef struct              s_env       /* Variable Master          */
{
    SDL_Event               event;      /* Event SDL                */
    _Bool                   exit;       /* Var quit programme       */
    struct s_opcl           cl;         /* Struct OpenCl            */
    char                    host;       /* Host or not host         */
    struct s_img            img;        /* Struct Image             */
    struct s_key            key;        /* Struct Keyboard          */
    int                     gpu;        /* Use GPU 1 yes 0 no       */
    struct s_scn            scn;        /* Struct Scene             */
    char                    slave;      /* slave or no slave        */
}                           t_env;

typedef struct              s_slv       /* struct connexion fd -> socket    */
{
    sockaddr_in             sck;
    int                     fds;
}                           t_slv;

void                        camera(register t_cam cam, t_ray *ray,
                                    register size_t x, register size_t y);
size_t                              check_object(t_obj *obj, t_ray *ray);
void                        cone(register t_obj *obj, register t_ray ray);
cl_float3                   coordinates_collision(register cl_float3 a,
                                    register cl_float3 b, register float det);
void                        create_window(t_env *e, Uint32 flags);
void                        cylinder(register t_obj *obj, register t_ray ray);
void                        diffused_light(t_ray *ray, register t_spt spt,
                                    register t_obj obj);
void                        err_cl(cl_int err);
void                        err_cl_sub(cl_int err);
void                        event_everything(t_env *e);
void                        get_camera(t_env *e, char **line);
t_rgba                      get_color(char *str);
void                        get_cone(t_obj *obj, char **line);
void                        get_cylinder(t_obj *obj, char **line);
void                        get_file_mlt(t_env *e, char *file);
void                        get_file_obj(t_env *e, char *file);
void                        get_file_ortv1(t_env *e, char *file);
char                        *get_file_raw(int fd);
void                        get_normal_object(t_obj *obj, t_ray ray);
void                        get_plan(t_obj *obj, char **line);
void                        get_scene(t_env *e, char *file);
void                        get_sphere(t_obj *obj, char **line);
void                        get_spot(t_spt *spt, char **line);
void                        get_src_opencl(t_opcl *cl);
void                        get_torus(t_obj *obj, char **line);
cl_float3                   get_vec3(char *str);
void                        *host(void *arg);
void                        init_keyboard(t_key *key);
void                        key_press(t_env *e);
void                        key_release(t_env *e);
void                        light(t_env *e, t_ray *ray, t_rgba *c_diff,
                                    register size_t id);
unsigned char               limit_rgba(register double x);
void                        lunch_opencl(t_opcl *cl);
cl_float3                   matrix_rotate(register cl_float3 point, register
                                    cl_float3 rot);
void                        OCL_run_raytracing(t_env *e, SDL_Renderer *rend);
void                        pixel_put(SDL_Renderer *rend, t_rgba rgba, size_t x,
                                    size_t y);
void                        plan(register t_obj *obj, register t_ray ray);
void                        play_scene(t_env *e, SDL_Renderer *rend);
void                        run_object(t_obj *obj, t_ray ray);
void                        run_raytracing(t_env *e, t_obj *obj, t_ray *ray);
double                      specular_light(register t_spt spt,
                                    register t_obj obj);
void                        sphere(register t_obj *obj, register t_ray ray);
void                        torus(register t_obj *obj, register t_ray ray);
cl_float3                   vector_add(register cl_float3 a,
                                    register cl_float3 b);
cl_float3                   vector_mult_x(register cl_float3 vect,
                                    register float x);
cl_float3                   vector_normalize(register cl_float3 vect);
cl_float3                   vector_reverse(register cl_float3 vect);
t_ray                       vector_rotate_ray(register t_ray ray, register
                                    cl_float3 pos, register cl_float3 rotate);
float                       vector_scalar(register cl_float3 a,
                                    register cl_float3 b);
cl_float3                   vector_sub(register cl_float3 a,
                                    register cl_float3 b);
void                        window_resize(t_env *e);

#endif
