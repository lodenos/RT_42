/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_RT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:02:05 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 01:49:31 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RT_H
#define LIB_RT_H
#include <libft.h>
#include <OpenCL/cl.h>
#include <SDL2/SDL.h>
#define TITLE "RT"
#define WIDTH 1280
#define HEIGHT 720

typedef struct          s_evo       /**/
{
    double              a;          /**/
    double              b;          /**/
    double              c;          /**/
    double              det;        /**/
    double              ta;         /**/
    double              tb;         /**/
}                       t_evo;      /**/

typedef struct          s_img       /* Window & Image SDL       */
{
    Uint32              flags;      /* Flag Window              */
    size_t              h;          /* Resolution height y      */
    SDL_Renderer        *rend;      /* Renderer Image           */
    SDL_Window          *win;       /* Window                   */
    size_t              w;          /* Resolution width x       */
    size_t              x;          /* Position pixel screen x  */
    size_t              y;          /* Positiom pixel screen y  */
}                       t_img;

typedef struct          s_rgba      /* Color                    */
{
    unsigned char       red;        /* Red   0 - 255            */
    unsigned char       green;      /* Green 0 - 255            */
    unsigned char       blue;       /* Blue  0 - 255            */
    unsigned char       alpha;      /* Alpha 0 - 255            */
}                       t_rgba;

typedef struct          s_vec3      /* Vector                   */
{
    double              x;          /* Position x               */
    double              y;          /* Position y               */
    double              z;          /* Position z               */
}                       t_vec3;

typedef struct          s_cam       /* Camera                   */
{
    float               fov;        /* FOV                      */
    size_t              h;          /* Resolution screen view x */
    struct s_vec3       pos;        /* Position canera          */
    struct s_vec3       rotate;     /* Angle of rotation        */
    struct s_vec3       view;       /* Positon view scren {0, 0}*/ 
    size_t              w;          /* Resolution screen view y */
}                       t_cam;

typedef struct          s_ray       /* Ray                      */
{
    struct s_vec3       a;          /* Point Start              */
    struct s_vec3       b;          /* Point reach              */
    size_t              max;        /* Maximun reflexion        */
    struct s_rgba       rgba;       /* Calor of the ray         */
}                       t_ray;

typedef struct          s_obj       /* Object                   */
{
    struct s_vec3       collision;  /* Point collision ray      */
    double              det;        /* Determinant matrice      */
    char                end;        /* 1 -> next ; 0 -x end     */
    void                (*ft)(struct s_obj *, struct s_ray);
    size_t              id;         /* Id Group                 */
    struct s_vec3       normal;     /* the normal of the object */
    struct s_vec3       pos;        /* Position Object          */
    double              radius;     /* radius of the object     */
    struct s_rgba       rgba;       /* Calors of the object     */
    struct s_vec3       rotate;     /* Angle of rotation        */
}                       t_obj;

typedef struct          s_krnl
{
    cl_kernel           run_raytracing;
}                       t_krnl;

typedef struct          s_opcl      /**/
{
    char                **file;     /**/
    char                **src;      /**/
    size_t              *size_src;  /**/
    char                *flags;     /**/
    cl_device_id        device_id;  /**/
    cl_context          contx;      /**/
    cl_command_queue    cmd_que;    /**/
    struct s_krnl       krnl;       /**/
    cl_program          prog;       /**/
    cl_platform_id      platf_id;   /**/
    cl_uint             num_device; /**/
    cl_uint             num_platf;  /**/
    cl_int              err;        /**/
}                       t_opcl;     /**/

typedef struct          s_spt       /**/
{
    char                ambient;    /**/
    char                end;        /**/
    size_t              id;         /**/
    char                light;      /**/
    struct s_vec3       pos;        /**/
    struct s_rgba       rgba;       /**/
}                       t_spt;


typedef struct          s_env       /* Variable Master          */
{
    struct s_cam        cam;        /* Struct camera            */
    SDL_Event           event;      /* Event SDL                */
    _Bool               exit;       /* Var quit programme       */
    struct s_opcl       cl;         /* Struct OpenCl            */
    struct s_img        img;        /* Struct Image             */
    size_t              n_obj;      /* Number object            */
    size_t              n_spt;      /* Number spotlight         */
    struct s_obj        *obj;       /* Struct Object            */
    struct s_ray        ray;        /* Struct Ray               */
    struct s_spt        *spt;       /* Struct Spotlight         */
}                       t_env;

void                    camera(register t_cam cam, t_ray *ray,                 \
                                register size_t x, register size_t y);
void                    cone(register t_obj *obj, register t_ray ray);
t_vec3                  coordinates_collision(register t_vec3 a,               \
                                register t_vec3 b, register double det);
void                    create_window(t_env *e, Uint32 flags);
void                    cylinder(register t_obj *obj, register t_ray ray);
double                  diffused_light(t_obj obj, t_spt spt);
void                    err_cl(cl_int err);
void                    event_everything(t_env *e);
void                    get_camera(t_env *e, char **line);
t_rgba                  get_color(char *str);
void                    get_cone(t_obj *obj, char **line);
void                    get_cylinder(t_obj *obj, char **line);
void                    get_file_mlt(t_env *e, char *file);
void                    get_file_obj(t_env *e, char *file);
void                    get_file_ortv1(t_env *e, char *file);
char                    *get_file_raw(int fd);
void                    get_plan(t_obj *obj, char **line);
void                    get_scene(t_env *e, char *file);
void                    get_sphere(t_obj *obj, char **line);
void                    get_spot(t_spt *spt, char **line);
void                    get_src_opencl(t_opcl *cl);
void                    get_torus(t_obj *obj, char **line);
t_vec3                  get_vec3(char *str);
void                    light(t_spt *spt, t_obj obj, t_ray *ray);
unsigned char           limit_rgba(register double x);
void                    lunch_opencl(t_opcl *cl);
void                    pixel_put(SDL_Renderer *rend, t_rgba rgba, size_t x,   \
                                size_t y);
void                    plan(register t_obj *obj, register t_ray ray);
void                    play_scene(t_env *e, SDL_Renderer *rend);
void                    run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray);
void                    specular_light(t_ray *ray, register t_spt spt,
                                register t_obj obj);
void                    sphere(register t_obj *obj, register t_ray ray);
void                    torus(register t_obj *obj, register t_ray ray);
t_vec3                  vector_add(register t_vec3 a, register t_vec3 b);
t_vec3                  vector_mult_x(register t_vec3 vect, register double x);
t_vec3                  vector_normalize(register t_vec3 vect);
t_vec3                  vector_reverse(register t_vec3 vect);
double                  vector_scalar(register t_vec3 a, register t_vec3 b);
t_vec3                  vector_sub(register t_vec3 a, register t_vec3 b);

#endif
