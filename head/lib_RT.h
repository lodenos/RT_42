/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_RT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:02:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:26:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RT_H
# define LIB_RT_H
# include <SDL2/SDL.h>
# include <OpenCL/cl.h>
# include "libft.h"
# define WIDTH 1280
# define HEIGHT 720
# define TITLE "RT"

typedef struct          s_vec3      /* Struct Position          */
{
    double              x;          /* position x               */
    double              y;          /* position y               */
    double              z;          /* position z               */
}                       t_vec3;

typedef struct          s_cam       /* Struct Camera            */
{
    struct s_vec3       dir;
    struct s_vec3       pos;        /* position camera          */
    struct s_vec3       view_plane; /* position view plane      */
    int                 x;          /* position pixel x screen  */
    int                 y;          /* position pixel y screen  */
    int                 h;
    int                 w;
}                       t_cam;

typedef struct          s_evo       /*  Struct env object       */
{
    double              a;
    double              b;
    double              c;
    double              det;
    double              ta;
    double              tb;
}                       t_evo;

typedef struct          s_img       /* Struct Window SDL        */
{
    int                 x;
    int                 y;
    int                 w;
    int                 h;
    Uint32              flags;
    SDL_Renderer        *rend;      /* Image SDL                */
    SDL_Window          *win;       /* Window SDL               */
}                       t_img;

typedef struct          s_rgb
{
    unsigned char       red;
    unsigned char       green;
    unsigned char       blue;
}                       t_rgb;

typedef struct          s_ray
{
    int                 index;
    int                 tmin;
    int                 max;
    struct s_vec3       a;
    struct s_vec3       b;
    struct s_rgb        rgb;
}                       t_ray;

typedef struct          s_obj
{
    struct s_vec3       rot;
    double              det;        /*                          */
    int                 end;        /*  End obj                 */
    double              (*ft)(struct s_obj, struct s_ray);
    struct s_vec3       norm;       /*  Normal Object           */
    struct s_vec3       pos;        /*  Position object         */
    double              r;          /*  Radius circle           */
    struct s_rgb        rgb;        /*  Color                   */
}                       t_obj;

typedef struct          s_spt
{
    size_t              light;      /*  Intensity of light      */
    struct s_vec3       pos;        /*  Pos                     */
    struct s_rgb        rgb;        /*  rgb                     */
    int                 end;        /**/
}                       t_spt;

typedef struct          s_opcl
{
    char                **file;
    char                **src;
    size_t              *size_src;
    char                *flags;
    cl_device_id        device_id;
    cl_context          contx;
    cl_command_queue    cmd_que;
    cl_program          prog;
    cl_platform_id      platf_id;
    cl_uint             num_device;
    cl_uint             num_platf;
    cl_int              err;
}                       t_opcl;

typedef struct	    	s_env       /* Struct environnemt       */
{
    int                 n_obj;
    int                 n_spt;
    SDL_Event           event;      /* Event SDL                */
    int                 exit;       /* Exit programme           */
    struct s_cam        cam;        /*                          */
    struct s_opcl       cl;         /* variable opencl          */
    struct s_img        img;        /* Struct image             */
    struct s_obj        *obj;       /* Struct obj               */
    struct s_ray        ray;        /* Struct ray               */
    struct s_spt        *spt;       /* Struct spt               */
}					    t_env;

void                    camera(t_cam *cam, t_ray *ray, int x, int y);
void                    create_window(t_env *e, Uint32 flags);
void                    event_everything(t_env *e);
void                    play_scene(t_env *e, SDL_Renderer* rend);
void                    progress_bar(void);
void                    run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray);
double                  sphere(t_obj obj, t_ray ray);

void                    coordinates_collision(t_obj *obj, t_ray ray);
void                    light(t_spt *spt, t_obj obj, t_ray *ray);
double                  diffused_light(t_obj obj, t_ray ray); 
void                    lunch_opencl(t_opcl *cl);
void                    err_cl(cl_int err);
char                    **get_src_opencl(char **file);
void                    specular_light(t_ray *ray, t_spt spt, t_obj obj);
void                    parser(t_env *e, int argc, char **argv);
void                    get_scene(t_env *e, t_list *list);
void                    get_camera(t_env *e, char *cam, int index);
void                    get_spot(t_env *e, char *data, int s, int index);
void                    get_object(t_env *e, t_list *list, int s, int o);
double                  cone(t_obj obj, t_ray ray);
char                    *ft_strconc(char *str, char start, char end);
void                    ft_lstpushback(t_list **blist, void const *content,
                                size_t content_size);
double                  plan(t_obj obj, t_ray ray);
double                  torus(t_obj obj, t_ray ray);
double                  cylinder(t_obj obj, t_ray ray);
void                    get_spotinfo(t_env *e, t_list *list, int s);

t_vec3                  vector_add(t_vec3 a, t_vec3 b);
double                  vector_mult(t_vec3 a, t_vec3 b);
t_vec3                  vector_mult_x(t_vec3 vect, double x);
t_vec3                  vector_normalize(t_vec3 vect);
t_vec3                  vector_reverse(t_vec3 vect);
double                  vector_scalar(t_vec3 a, t_vec3 b);
t_vec3                  vector_sub(t_vec3 a, t_vec3);

#endif
