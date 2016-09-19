/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_RT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:02:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/19 20:35:54 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RT_H
# define LIB_RT_H
# include <SDL2/SDL.h>
# include "libft.h"
# define WIDTH 1280
# define HEIGHT 720
# define TITLE "RT"

typedef struct      s_pos       /* Struct Position          */
{
    double          x;          /* position x               */
    double          y;          /* position y               */
    double          z;          /* position z               */
}                   t_pos;

typedef struct      s_cam       /* Struct Camera            */
{
    struct s_pos    pos;        /* position camera          */
    struct s_pos    view_plane; /* position view plane      */
    int             x;          /* position pixel x screen  */
    int             y;          /* position pixel y screen  */
    int             h;
    int             w;
}                   t_cam;

typedef struct      s_evo       /*  Struct env object       */
{
    double          a;
    double          b;
    double          c;
    double          det;
    double          ta;
    double          tb;
}                   t_evo;

typedef struct      s_img       /* Struct Window SDL        */
{
    int				x;
    int				y;
    int				w;
    int				h;
    Uint32          flags;
    int             trash_pad;
    SDL_Renderer    *rend;      /* Image SDL                */
    SDL_Window      *win;       /* Window SDL               */
}                   t_img;

typedef struct      s_ray
{
    int             max;
    struct s_pos    a;
    struct s_pos    b;
    unsigned int    rgb;
}                   t_ray;

typedef struct      s_obj
{
    double          det;        /*                          */
    int             end;        /*  End obj                 */
    double          (*ft)(struct s_obj, struct s_ray);
    struct s_pos    norm;       /*  Normal Object           */
    struct s_pos    pos;        /*  Position object         */
    double          r;          /*  Radius circle           */
    unsigned int    rgb;        /*  Color                   */
    int             trash_pad;
    int             trash_pad2;
}                   t_obj;

typedef struct      s_spt
{
    size_t          light;      /*  Intensity of light      */
    struct s_pos    pos;        /*  Pos                     */
    unsigned int    rgb;        /*  rgb                     */
    int             end;        /**/
}                   t_spt;

typedef struct		s_env       /* Struct environnemt       */
{
    int             n_obj;
    int             n_spt;
    SDL_Event       event;      /* Event SDL                */
    int             exit;       /* Exit programme           */
    struct s_cam    cam;        /**/
    struct s_img    img;        /* Struct image             */
    struct s_obj    *obj;       /* Struct obj               */
    struct s_ray    ray;        /* Struct ray               */
    struct s_spt    *spt;       /* Struct spt               */
}					t_env;

void                camera(t_cam *cam, t_ray *ray, int x, int y);
void                create_window(t_env *e, Uint32 flags);
void                event_everything(t_env *e);
void                get_scene(char *file, t_env *e);
void                play_scene(t_env *e, SDL_Renderer* rend);
void                progress_bar(void);
void                run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray);
double              sphere(t_obj obj, t_ray ray);

void                coordinates_collision(t_obj *obj, t_ray ray);
void                light(t_spt *spt, t_obj obj, t_ray *ray);
double              diffused_light(t_obj obj, t_ray ray); 

#endif
