/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_RT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:02:05 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 15:10:46 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIB_RT_H
#define	LIB_RT_H

#define	MAC
//#define WINDOWS

#include <libft.h>
#include <math.h>
#include <pthread.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#ifdef MAC

	#include <arpa/inet.h>
	#include <OpenCL/cl.h>
	#include <netdb.h>
	#include <netinet/in.h>
	#include <sys/socket.h>
	#include <sys/types.h>
	#include <sys/time.h>

#endif

#ifdef  WINDOWS

	#include <windows.h>
	#include <winsock2.h>
	#include <CL/cl.h>

#endif

#define TITLE "RT"
#define CONE 2
#define CYLINDER 4
#define PLAN 8
#define SPHERE 16
#define TORUS 32
#define TRIANGLE 64
#define ELLIPSOID 128
#define NO_MASK 0xFFFFFFFF
#define D_TO_RAD 0.01745329251f
#define EPSILON 0.000001
#define VALID "RT_Protocol_Clusturing_GLodenos_"
#define CONNECT "RT_Protocol_Clusturing_Slave_OK_"
#define FILTERED_RGB 1
#define FILTERED_SEPIA 2
#define FILTERED_BLACK_WHITE 3
#define STEREOSCOPIE 4
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct s_cam		t_cam;
typedef struct s_env		t_env;
typedef struct s_img		t_img;
typedef struct s_key		t_key;
typedef struct s_krnl		t_krnl;
typedef struct s_mimg		t_mimg;
typedef struct s_mouse		t_mouse;
typedef struct s_mppng		t_mppng;
typedef struct s_obj		t_obj;
typedef struct s_opcl		t_opcl;
typedef struct s_ray		t_ray;
typedef struct s_scn		t_scn;
typedef struct s_slv		t_slv;
typedef struct sockaddr_in	sockaddr_in;
typedef struct sockaddr		sockaddr;
typedef struct s_spt		t_spt;
typedef struct s_roots		t_roots;
typedef struct s_complex	t_complex;
typedef struct s_equ		t_equ;
typedef struct s_ssamp		t_ssamp;
typedef struct s_voronoi	t_voronoi;

struct					s_voronoi
{
	cl_float2			lol;
	cl_float2			b;
	cl_float2			p;
	cl_float2			f;
	cl_float2			r;
};

struct					s_ssamp
{
	size_t				i;
	size_t				j;
	float				x;
	float				div;
	size_t				max;
	cl_float3			rgb;
};

struct					s_equ
{
	double				a;
	double				b;
	double				c;
	double				d;
	double				e;
};

struct					s_complex
{
	double				r;
	double				i;
};

struct					s_roots
{
	double				x1;
	double				x2;
	double				x3;
	double				x4;
	t_complex			complex1;
	t_complex			complex2;
};

struct					s_cam
{
	float				fov;
	size_t				h;
	cl_float3			pos;
	cl_float3			rotate;
	size_t				w;
};

struct					s_img
{
	Uint32				flags;
	size_t				h;
	unsigned int		*img;
	SDL_Renderer		*rend;
	SDL_Window			*win;
	size_t				w;
	size_t				x;
	size_t				y;
};

struct	  				s_ray
{
	cl_float3			pos;
	cl_float3			dir;
	size_t				max;
	unsigned int		color;
};

struct					s_obj
{
	float				angle;
	cl_float3			collision;
	unsigned int		color;
	float				diffuse;
	_Bool				end;
	float				gloss;
	size_t				id;
	cl_float3			normal;
	cl_float3			pos_a;
	cl_float3			pos_b;
	cl_float3			pos_c;
	cl_float3			radius_a;
	cl_float3			radius_b;
	float				reflexion;
	float				refraction;
	cl_float3			rotate;
	size_t				type;
	size_t				type_bump;
};

struct					s_key
{
	_Bool				key_a;
	_Bool				key_comma;
	_Bool				key_d;
	_Bool				key_down;
	_Bool				key_left;
	_Bool				key_lshift;
	_Bool				key_period;
	_Bool				key_right;
	_Bool				key_s;
	_Bool				key_space;
	_Bool				key_up;
	_Bool				key_w;
};

struct					s_mouse
{
	int					id;
	_Bool				left;
	_Bool				right;
	int					x;
	int					y;
};

struct					s_krnl
{
	cl_mem				buff_img;
	cl_mem				buff_obj;
	cl_mem				buff_scn;
	cl_mem				buff_spt;
	cl_kernel			run_raytracing;
	size_t				*wk;
};

struct					s_opcl
{
	char				**file;
	char				**src;
	size_t				*size_src;
	char				*flags;
	cl_device_id		device_id;
	cl_context			contx;
	cl_command_queue	cmd_que;
	t_krnl				krnl;
	cl_uint				nbr_src;
	cl_program			prog;
	cl_platform_id		platf_id;
	cl_uint				num_device;
	cl_uint				num_platf;
};

struct					s_spt
{
	unsigned int		color;
	_Bool				end;
	size_t				id;
	float				light;
	cl_float3			pos;
};

struct					s_mimg
{
	size_t				start_x;
	size_t				start_y;
	size_t				stop_x;
	size_t				stop_y;
};

struct					s_scn
{
	float				ambient;
	t_cam	   			cam;
	t_mimg	  			mimg;
	size_t	  			n_obj;
	size_t	  			n_spt;
	size_t	  			resolution;
	float	   			specular;

	unsigned int		color;
	size_t				filter;
};

struct	  				s_env
{
	_Bool	   			camera;
	t_opcl	  			cl;
	_Bool	   			config;
	SDL_Event	   		event;
	size_t	  			elem_gp;
	size_t	  			elem_obj;
	size_t	  			elem_spt;
	_Bool	   			exit;
	_Bool	   			group;
	char				host;
	t_img	   			img;
	t_key	   			key;
	_Bool	   			gpu;
	t_mouse	 			mouse;
	size_t	  			nbr_slv;
	t_obj	   			*obj;
	t_scn	   			scn;
	_Bool	   			scene;
	char				slave;
	t_spt	   			*spt;
	_Bool	   			start;
	size_t	  			thread;
};

struct	  				s_mppng
{
	t_env	   			*e;
	t_mimg	  			mimg;
};

typedef struct	  		s_slv
{
	t_env	   			*e;
	int					fds;
	pthread_t			pthr;
	float				ping;
	sockaddr_in			sck;
}						t_slv;

typedef struct			s_mem
{
	int	 				fds;
	size_t				size;
}						t_mem;


cl_float3	   			add(register cl_float3 a, register cl_float3 b);
void					bump_mapping(t_obj *obj);
void					camera(register t_cam cam, t_ray *ray, register float x, register float y);
float	   				check_object(t_obj *obj, register t_ray ray, size_t *id, size_t mask);
t_mem	   				cluster_create_buffer(int fds, size_t size);
void					*cluster_read_buffer(t_mem mem);
int						cluster_write_buffer(t_mem mem, void *data);
float	   				cone(register t_obj obj, register t_ray ray);
cl_float3				coordinates_collision(register cl_float3 a, register cl_float3 b, register float det);
void					create_window(t_env *e, Uint32 flags);
float	   				cylinder(register t_obj obj, register t_ray ray);
void					diffused_light(t_ray *ray, register t_spt spt, register t_obj obj);
float	   				dot(register cl_float3 a, register cl_float3 b);
void					err_cl(cl_int err);
void					err_cl_sub(cl_int err);
void					event_everything(t_env *e);
int	 					event_rt(t_env *e);
void					fps_info(void);
void					get_camera(t_env *e, char **line);
unsigned int			get_color(char *str);
void					get_file_mlt(t_env *e, char *file);
void					get_file_obj(t_env *e, char *file);
void					get_file_ort(t_env *e, char *file);
char					*get_file_raw(int fd);
void					get_info_angle(t_env *e, char **str, size_t *i);
void					get_info_color(unsigned int *color, char *str);
void					get_info_diffuse(float *diffuse, char *str);
void					get_info_ort(t_env *e, char **str, size_t *i);
void					get_info_position(cl_float3 *pos, char *str);
void					get_info_radius(cl_float3 *radius, char *str);
void					get_info_rotate(cl_float3 *rotate, char *str);
void					get_normal_object(t_obj *obj, register t_ray ray, register float det);
void					get_ort(t_env *e, char **str);
void					get_ort_camera(t_env *e, char **str, size_t *i);
void					get_ort_config(t_env *e, char **str, size_t *i);
void					get_ort_group(t_env *e, char **str, size_t *i);
void					get_ort_obj_info(t_env *e, char **str, size_t *i, size_t type);
void					get_ort_scene(t_env *e, char **str, size_t *i);
void					get_ort_spotlight(t_env *e, char **str, size_t *i);
void					get_ort_texture(t_env *e, char **str, size_t *i);
void					get_scene(t_env *e, char *file);
void					get_src_opencl(t_opcl *cl);
void					*host(void *arg);
void					init_keyboard(t_key *key);
void					init_mouse(t_mouse *mouse);
void					key_press(t_env *e);
void					key_release(t_env *e);
void					light(t_env *e, size_t id, t_obj tmp_obj, t_ray *ray);
unsigned int			limit(register float x);
void					lunch_opencl(t_opcl *cl);
void					ocl_run_raytracing(t_env *e);
void					*mapping(void *arg);
cl_float3				normalize(register cl_float3 vect);
float	   				plan(register t_obj obj, register t_ray ray);
void					*play_scene(void *arg);
void					push_to_window(SDL_Renderer *rend, unsigned int *img, size_t w, size_t h);
cl_float3	   			reverse(register cl_float3 vect);
cl_float3	   			rotate_x(register cl_float3 point, register float angle);
cl_float3	   			rotate_y(register cl_float3 point, register float angle);
cl_float3	   			rotate_z(register cl_float3 point, register float angle);
float	   				run_object(register t_obj obj, register t_ray ray);
void					run_raytracing(t_env *e, t_obj *obj, t_ray *ray);
void					*slave(void *arg);
void					*slave_connection(void *arg);
unsigned int   			*stereoscopie(unsigned int *img_l,
							unsigned int *img_r, size_t resolution);
float	   				specular_light(register t_spt spt, register t_obj obj);
float	   				sphere(register t_obj obj, register t_ray ray);
void					filtered_rgb(unsigned int filter, unsigned int *img,
								size_t resolution);
cl_float3				sub(register cl_float3 a, register cl_float3 b);
void					super_sampling(t_env *e, t_ray *ray, cl_float2 pos, size_t resolution);
float	   				torus(register t_obj obj, register t_ray ray);
cl_float3	   			vector_mult(register cl_float3 a, register cl_float3 b);
cl_float3	   			vector_mult_x(register cl_float3 vect, register float x);
void					window_resize(t_env *e);

//  New Prototype

char					*clustering_hash_contribution(size_t nbr_elem, size_t nbr_block);
size_t	  				cluster_get_contribution(size_t id, char *tab_work, t_img img, unsigned int *img_work, t_mimg mimg);
void					cluster_finish_contribution(size_t id, char *tab_work, t_img img, unsigned int *img_work, t_mimg mimg);

cl_float2	   			add_vec(cl_float2 a, cl_float2 b);
cl_float2	   			div_vec(cl_float2 a, cl_float b);
cl_float2	   			dot_vec_f(cl_float2 a, cl_float b);
float	   				dot_vec(cl_float2 a, cl_float2 b);
float	   				fract(float x);
cl_float2	   			fract_2d(cl_float2 v);
cl_float2	   			fract_vec(cl_float2 x);
cl_float2	   			sub_vec(cl_float2 a, cl_float2 b);
cl_float2	   			sub_vec_lol(cl_float2 a, cl_float b);

float	   				ft_max(float x, float min, float maxi);
float	   				noise(cl_float2 n);
float	   				perlin(cl_float2 n);

cl_float2	   			random2(cl_float2 c);
float	   				smooth_voronoi(cl_float2 x);

_Bool					move(cl_float3 *pos, t_key key);
_Bool					rotate(cl_float3 *rotate, t_key key);
void 					sepia(unsigned int *img, size_t resolution);
void					filtered_black_white(unsigned int *img, size_t resolution);
cl_float2               random2(cl_float2 c);
float                   smooth_voronoi(cl_float2 x);
float					ellipsoid(register t_obj obj, register t_ray ray);
float					triangle(register t_obj obj, register t_ray ray);

t_roots					solve_quartic_equation(register t_equ q);
float					ellipsoid(register t_obj obj, register t_ray ray);
cl_float3				get_ellipsoid_normale(register t_obj *obj, register float det);
cl_float3				cross(register cl_float3 a, register cl_float3 b);
t_roots					solve_cubic_equation(register double a, register double b,
								register double c, register double d);

void					refraction(t_env *e, t_ray *ray, t_obj obj_tmp, size_t id);
void					reflexion(t_env *e, t_ray *ray, t_obj obj_tmp, size_t id);
cl_float3				rayon_refracte(cl_float3 normal, cl_float3 incident, float n1, float n2);
void					get_normal_object_sub(t_obj *obj, register t_ray ray, register float det);
void					get_normal_object(t_obj *obj, register t_ray ray, register float det);

void					init_ort_parser(t_env *e);
void					get_ort_config_sub(t_env *e, char **str, size_t *i);

#endif
