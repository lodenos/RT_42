/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_RT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:02:05 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/13 12:10:46 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RT_H
#define LIB_RT_H

#define MAC
//#define WINDOW

#include <libft.h>
#include <math.h>
#include <pthread.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#ifdef  MAC

    #include <arpa/inet.h>
    #include <OpenCL/cl.h>
    #include <netdb.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/time.h>

#endif

#ifdef  WINDOW

    #include <windows.h>
    #include <winsock2.h>
    #include <CL/cl.h>

#endif

#define TITLE       "RT"
#define CONE        2
#define CYLINDER    4
#define PLAN        8
#define SPHERE      16
#define TORUS       32
#define TRIANGLE    64
#define ELLIPSOID	128
#define NO_MASK     0xFFFFFFFF
#define D_TO_RAD    0.01745329251f
#define EPSILON		0.000001
#define VALID       "RT_Protocol_Clusturing_GLodenos_"
#define CONNECT     "RT_Protocol_Clusturing_Slave_OK_"
#define ABS(x)		((x) < 0 ? -(x) : (x))

typedef struct s_cam        t_cam;
typedef struct s_env        t_env;
typedef struct s_img        t_img;
typedef struct s_key        t_key;
typedef struct s_krnl       t_krnl;
typedef struct s_mimg       t_mimg;
typedef struct s_mouse      t_mouse;
typedef struct s_mppng      t_mppng;
typedef struct s_obj        t_obj;
typedef struct s_opcl       t_opcl;
typedef struct s_ray        t_ray;
typedef struct s_scn        t_scn;
typedef struct s_slv        t_slv;
typedef struct sockaddr_in  sockaddr_in;    /* struct sockaddr_in -> sockaddr_in    */
typedef struct sockaddr     sockaddr;       /* stwruct sockaddr -> sockaddr         */
typedef struct s_spt        t_spt;
typedef struct s_roots		t_roots;
typedef struct s_complex	t_complex;
typedef struct s_equ		t_equ;

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

struct                  s_cam           /* Camera                               */
{
    float               fov;            /* FOV                                  */
    size_t              h;              /* Resolution screen view x             */
    cl_float3           pos;            /* Position canera                      */
    cl_float3           rotate;         /* Angle of rotation                    */
    size_t              w;              /* Resolution screen view y             */
};

struct                  s_img           /* Window & Image SDL                   */
{
    Uint32              flags;          /* Flag Window                          */
    size_t              h;              /* Resolution height y                  */
    unsigned int        *img;           /* Image buffer OpenCL                  */
    SDL_Renderer        *rend;          /* Renderer Image                       */
    SDL_Window          *win;           /* Window                               */
    size_t              w;              /* Resolution width x                   */
    size_t              x;              /* Position pixel screen x              */
    size_t              y;              /* Positiom pixel screen y              */
};

struct                  s_ray           /* Ray                                  */
{
    cl_float3           pos;            /* Point Start                          */
    cl_float3           dir;            /* Point reach                          */
    size_t              max;            /* Maximun reflexion                    */
    unsigned int        color;          /* Calor of the ray                     */
};

struct                  s_obj           /* Object                               */
{
    float               angle;          /* Angle                                |   Under-flags 1   */
    cl_float3           collision;      /* Point collision ray                  |   Under-flags 2   */
    unsigned int        color;          /* Calors of the object                 |   Under-flags 3   */
    float               diffuse;        /*                                      |   Under-flags 4   */
    _Bool               end;            /* 1 -> next ; 0 -x end                 |   Under-flags 5   */
    float               gloss;          /*                                      |   Under-flags 6   */
    size_t              id;             /* Id Group                             |   Under-flags 7   */
    cl_float3           normal;         /* Vector Normal                        |   Under-flags 8   */
    cl_float3           pos_a;          /* Position a                           |   Under-flags 9   */
    cl_float3           pos_b;          /* Position b                           |   Under-flags 10  */
    cl_float3           pos_c;          /* Position c                           |   Under-flags 11  */
    cl_float3           radius_a;       /* radius of the object                 |   Under-flags 12  */
    cl_float3           radius_b;       /* radius of the object                 |   Under-flags 13  */
    float               reflexion;      /*                                      |   Under-flags 14  */
    float               refraction;     /*                                      |   Under-flags 15  */
    cl_float3           rotate;         /* Angle of rotation                    |   Under-flags 16  */
    size_t              type;           /* Type Object                          |   Under-flags 17  */
    size_t              type_bump;      /* Type Bump Mapping                    |   Under-flags 18  */
};

struct                  s_key           /* Keyboard for key repet               */
{
    _Bool               key_a;          /* Key -> a                             */
    _Bool               key_comma;      /* Key -> ,                             */
    _Bool               key_d;          /* Key -> d                             */
    _Bool               key_down;       /* Key -> down                          */
    _Bool               key_left;       /* Key -> left <-                       */
    _Bool               key_lshift;     /* Key -> left shift                    */
    _Bool               key_period;     /* Key -> .                             */
    _Bool               key_right;      /* Key -> right ->                      */
    _Bool               key_s;          /* Key -> s                             */
    _Bool               key_space;      /* Key -> space                         */
    _Bool               key_up;         /* key -> up                            */
    _Bool               key_w;          /* Key -> w                             */
};

struct                  s_mouse         /* Struct Mouse                         */
{
    int                 id;             /* Id objet                             */
    _Bool               left;           /* Buttom left                          */
    _Bool               right;          /* Buttom right                         */
    int                 x;              /* Position x mouse                     */
    int                 y;              /* Position y mouse                     */
};

struct                  s_krnl          /* Struct Kernel OpenCL                 */
{
    cl_mem              buff_img;       /* Buffer *img                          */
    cl_mem              buff_obj;       /* Buffer struct *obj                   */
    cl_mem              buff_scn;       /* Buffer struct *scn                   */
    cl_mem              buff_spt;       /* Buffer struct *spt                   */
    cl_kernel           run_raytracing; /* Function Kernel run_raytracing       */
    size_t              *wk;            /* Worker "get_global_id()"             */
};

struct                  s_opcl          /* Struct Generic OpenCL                */
{
    char                **file;         /* Source file *.cl                     */
    char                **src;          /* Source load into memory              */
    size_t              *size_src;      /* Size load into memory sources        */
    char                *flags;         /* Compilation Flags OpenCL             */
    cl_device_id        device_id;      /* Device id                            */
    cl_context          contx;          /* Context OpenCL                       */
    cl_command_queue    cmd_que;        /* Commend queue                        */
    t_krnl              krnl;           /* Struct Kernel                        */
    cl_uint             nbr_src;        /* Number of source file                */
    cl_program          prog;           /* Programme OpenCL                     */
    cl_platform_id      platf_id;       /* Platform ID                          */
    cl_uint             num_device;     /* Number Device                        */
    cl_uint             num_platf;      /* Number Platform                      */
};

struct                  s_spt           /* Struct Spotlight                     */
{
    unsigned int        color;          /* Color light                          */
    _Bool               end;            /* 1 -> next ; 0 -x end                 */
    size_t              id;             /* Id Group                             */
    float               light;          /* Power light                          */
    cl_float3           pos;            /* Position spotlight                   */

};

struct                  s_mimg          /* Mapping Image x1y1 -> x2y2           */
{
    size_t              start_x;        /* Pixel image Start x                  */
    size_t              start_y;        /* Pixel image Start y                  */
    size_t              stop_x;         /* Pixel image Stop  x                  */
    size_t              stop_y;         /* Pixel image Stop  y                  */
};

struct                  s_scn           /* Struct Scene                         */
{
    float               ambient;        /*                                      | flags 1   */
    t_cam               cam;            /* Struct camera                        | flags 2   */
    t_mimg              mimg;           /* Struct Mapping Image x1y1 -> x2y2    | flags 3   */
    size_t              n_obj;          /* Number object                        | flags 4   */
    size_t              n_spt;          /* Number spotlight                     | flags 5   */
    size_t              resolution;     /* Super Sampling Resolution            | flags 6   */
    float               specular;       /*                                      | flags 7   */
};

struct                  s_env           /* Variable Master                      */
{
    _Bool               camera;         /**/
    t_opcl              cl;             /* Struct OpenCl                        */
    _Bool               config;         /* */
    SDL_Event           event;          /* Event SDL                            */
    size_t              elem_gp;        /**/
    size_t              elem_obj;       /**/
    size_t              elem_spt;       /**/
    _Bool               exit;           /* Var quit programme                   */
    _Bool               group;          /**/
    char                host;           /* Host or not host                     */
    t_img               img;            /* Struct Image                         */
    t_key               key;            /* Struct Keyboard                      */
    _Bool               gpu;            /* Use GPU 1 yes 0 no                   */
    t_mouse             mouse;          /* Struct mouse                         */
    size_t              nbr_slv;        /* Number of active slave               */
    t_obj               *obj;           /* Struct Object                        */
    t_scn               scn;            /* Struct Scene                         */
    _Bool               scene;          /* */
    char                slave;          /* slave or no slave                    */
    t_spt               *spt;           /* Struct Spotlight                     */
    _Bool               start;          /* First event_RT                       */
    size_t              thread;         /* Thread max*/
};

struct                  s_mppng         /* Struct env + mimg for thread mapping */
{
    t_env               *e;             /* Struct env                           */
    t_mimg              mimg;           /* Struct mimg                          */
};

typedef struct          s_slv           /* struct connexion fd -> socket        */
{
    t_env               *e;             /* Struct env                           */
    int                 fds;            /* fd Socket                            */
    pthread_t           pthr;           /* Id Thread                            */
    float               ping;           /* Ping                                 */
    sockaddr_in         sck;            /* Struct Socket                        */
}                       t_slv;

typedef struct          s_mem           /**/
{
    int                 fds;            /**/
    size_t              size;           /**/
}                       t_mem;


cl_float3               add(register cl_float3 a, register cl_float3 b);
void                    bump_mapping(t_obj *obj);
void                    camera(register t_cam cam, t_ray *ray, register float x, register float y);
float                   check_object(t_obj *obj, register t_ray ray, size_t *id, size_t mask);
t_mem                   cluster_create_buffer(int fds, size_t size);
void                    *cluster_read_buffer(t_mem mem);
int                     cluster_write_buffer(t_mem mem, void *data);
float                   cone(register t_obj obj, register t_ray ray);
cl_float3               coordinates_collision(register cl_float3 a, register cl_float3 b, register float det);
void                    create_window(t_env *e, Uint32 flags);
cl_float3				cross(register cl_float3 a, register cl_float3 b);
float                   cylinder(register t_obj obj, register t_ray ray);
void                    diffused_light(t_ray *ray, register t_spt spt, register t_obj obj);
float                   dot(register cl_float3 a, register cl_float3 b);
void                    err_cl(cl_int err);
void                    err_cl_sub(cl_int err);
void                    event_everything(t_env *e);
int                     event_RT(t_env *e);
void                    fps_info(void);
void                    get_camera(t_env *e, char **line);
unsigned int            get_color(char *str);
cl_float3				get_ellipsoid_normale(register t_obj *obj, register float det);
void                    get_file_mlt(t_env *e, char *file);
void                    get_file_obj(t_env *e, char *file);
void                    get_file_ort(t_env *e, char *file);
char                    *get_file_raw(int fd);
void                    get_info_angle(t_env *e, char **str, size_t *i);
void                    get_info_color(unsigned int *color, char *str);
void                    get_info_diffuse(float *diffuse, char *str);
void                    get_info_ort(t_env *e, char **str, size_t *i);
void                    get_info_position(cl_float3 *pos, char *str);
void                    get_info_radius(cl_float3 *radius, char *str);
void                    get_info_rotate(cl_float3 *rotate, char *str);
void                    get_normal_object(t_obj *obj, register t_ray ray, register float det);
void                    get_ort(t_env *e, char **str);
void                    get_ort_camera(t_env *e, char **str, size_t *i);
void                    get_ort_config(t_env *e, char **str, size_t *i);
void                    get_ort_group(t_env *e, char **str, size_t *i);
void                    get_ort_obj_info(t_env *e, char **str, size_t *i, size_t type);
void                    get_ort_scene(t_env *e, char **str, size_t *i);
void                    get_ort_spotlight(t_env *e, char **str, size_t *i);
void                    get_ort_texture(t_env *e, char **str, size_t *i);
void                    get_scene(t_env *e, char *file);
void                    get_src_opencl(t_opcl *cl);
void                    *host(void *arg);
void                    init_keyboard(t_key *key);
void                    init_mouse(t_mouse *mouse);
void                    key_press(t_env *e);
void                    key_release(t_env *e);
void                    light(t_env *e, size_t id, t_obj tmp_obj, t_ray *ray);
unsigned int            limit(register float x);
void                    lunch_opencl(t_opcl *cl);
void                    OCL_run_raytracing(t_env *e);
void                    *mapping(void *arg);
cl_float3               normalize(register cl_float3 vect);
float                   plan(register t_obj obj, register t_ray ray);
void                    *play_scene(void *arg);
void                    push_to_window(SDL_Renderer *rend, unsigned int *img, size_t w, size_t h);
cl_float3               reverse(register cl_float3 vect);
cl_float3               rotate_x(register cl_float3 point, register float angle);
cl_float3               rotate_y(register cl_float3 point, register float angle);
cl_float3               rotate_z(register cl_float3 point, register float angle);
float                   run_object(register t_obj obj, register t_ray ray);
void                    run_raytracing(t_env *e, t_obj *obj, t_ray *ray);
void                    *slave(void *arg);
void                    *slave_connection(void *arg);
struct s_roots			solve_cubic_equation(register double a, register double b, register double c, register double d);
struct s_roots			solve_quartic_equation(register double a, register double b, register double c, register double d, register double e);
float                   specular_light(register t_spt spt, register t_obj obj);
float                   sphere(register t_obj obj, register t_ray ray);
cl_float3               sub(register cl_float3 a, register cl_float3 b);
void                    super_sampling(t_env *e, t_ray *ray, cl_float2 pos, size_t resolution);
double                  torus(register t_obj obj, register t_ray ray);
cl_float3               vector_mult(register cl_float3 a, register cl_float3 b);
cl_float3               vector_mult_x(register cl_float3 vect, register float x);
cl_float3				vector_div(register cl_float3 a, register float x);
float					vector_len(register cl_float3 a);
void                    window_resize(t_env *e);

//  New Prototype

char                    *clustering_hash_contribution(size_t nbr_elem, size_t nbr_block);
size_t                  cluster_get_contribution(size_t id, char *tab_work, t_img img, unsigned int *img_work, t_mimg mimg);
void                    cluster_finish_contribution(size_t id, char *tab_work, t_img img, unsigned int *img_work, t_mimg mimg);

cl_float2               add_vec(cl_float2 a, cl_float2 b);
cl_float2               div_vec(cl_float2 a, cl_float b);
cl_float2               dot_vec_f(cl_float2 a, cl_float b);
float                   dot_vec(cl_float2 a, cl_float2 b);
float                   fract(float x);
cl_float2               fract_2d(cl_float2 v);
cl_float2               fract_vec(cl_float2 x);
cl_float2               sub_vec(cl_float2 a, cl_float2 b);
cl_float2               sub_vec_lol(cl_float2 a, cl_float b);

float                   ft_max(float x, float min, float maxi);
float                   noise(cl_float2 n);
float                   perlin(cl_float2 n);

cl_float2               random2(cl_float2 c);
float                   smooth_voronoi(cl_float2 x);

#endif
