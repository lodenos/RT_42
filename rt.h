/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:57:30 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/15 15:42:16 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# define TITLE "RTv1"
# define FOV		30

typedef struct		s_vec3d
{
	double			x;
	double			y;
	double			z;
}					t_vec3d;

typedef struct		s_rgb
{
    int				red;
    int				green;
    int				blue;
}					t_rgb;

typedef struct		s_aaf       /*  Anti-aliasing filter    */
{
    struct s_rgb	pixel[9];
}					t_aaf;

typedef struct		s_cam
{
    struct s_vec3d	pos;
    struct s_vec3d	dir;
}                   t_cam;

typedef struct		s_evo       /*  Struct env object       */
{
    double			a;
    double			b;
    double			c;
    double			det;
    double			ta;
    double			tb;
}					t_evo;

typedef struct		s_img       /*  Fucking shit mlx        */
{
    int				a;
    int				b;
    int				c;
    void			*img;
    void			*mlx;
    char			*tab;
    void			*win;
}					t_img;

typedef struct      s_key
{
    int             f1;
}                   t_key;

typedef struct      s_ray       /*  Ray                     */
{
	double			tmin;
	int				index;
    size_t          max;        /*  Max reflection          */
    struct s_vec3d	ro;          /*  Point origin           */
    struct s_vec3d	rd;          /*  Point direction        */
    struct s_rgb    rgb;        /*  Color                   */
}                   t_ray;

typedef struct      s_obj       /*  Object                  */
{
    double          det;        /*                          */
    int             end;        /*  End obj                 */
    double          (*ft)(struct s_obj, struct s_ray);
    struct s_vec3d	norm;       /*  Normal Object           */
    struct s_vec3d	pos;        /*  Position Sphere         */
    double          r;          /*  Radius circle           */
    struct s_rgb    rgb;        /*  Color                   */
    struct s_vec3d	rot;        /*  Rotate                  */
}                   t_obj;

typedef struct      s_spt       /*  Struct Spot             */
{
    size_t          light;      /*  Intensity of light      */
    struct s_vec3d	pos;        /*  Pos                     */
    struct s_rgb    rgb;        /*  rgb                     */
    int             end;        /**/
}                   t_spt;

typedef struct      s_scn       /*  Struct Scene            */
{
    struct s_cam    cam;        /*  camera                  */
    int             n_obj;      /*  Number object           */
    int             n_spt;      /*  Number spot             */
    struct s_obj    *obj;       /*  object                  */
    struct s_spt    *spt;       /*  spot                    */
}                   t_scn;

typedef struct      s_env       /*  Environment Program     */
{
    struct s_aaf    aaf;        /*  Anti-Aliasing Filter    */
    struct s_img    img;        /*  MLX                     */
    struct s_key    key;        /*  Keyboard                */
    struct s_vec3d	pos;        /*  Position Pixel Screen   */
    struct s_ray    ray;        /*  Segment ray             */
    struct s_scn    scn;		/*  Scene                   */
	int				wid;
	int				hei;
}                   t_env;

void                camera(t_env *e);
void                coordinates_collision(t_obj *obj, t_ray ray);
double              diffused_light(t_obj obj, t_ray ray);
int                 event_key_press(int k, t_env *e);
int                 event_key_release(int k, t_env *e);
void                light(t_spt *spt, t_obj obj, t_ray *ray);
void                play_scene(t_env *e);
double              sphere(t_obj obj, t_ray ray);
double              plan(t_obj obj, t_ray ray);
double				cylinder(t_obj obj, t_ray ray);
double              cone(t_obj obj, t_ray ray);
double              torus(t_obj obj, t_ray ray);
void                run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray);
void				get_scene(t_env *e, t_list *list);
void				get_object(t_env *e, t_list *list, int s, int o);
void				get_spotinfo(t_env *e, t_list *list, int s);

t_env				*parser(t_env *e, int ac, char **av);
void				vecnorm(t_vec3d *v);
t_vec3d				veccopy(t_vec3d *v);
t_vec3d				vecsub(t_vec3d *a, t_vec3d *b);
double				vecdot(t_vec3d *a, t_vec3d *b);
t_vec3d				vecdot2(t_vec3d *v, double i);
t_vec3d				vecadd(t_vec3d *v,  t_vec3d *u);

#endif
