/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_RT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:02:05 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/30 12:55:15 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RT_H

#define LIB_RT_H

#include <arpa/inet.h>
#include <libft.h>
#include <OpenCL/cl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <SDL2/SDL.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define TITLE       "RT"
#define THREAD      4
#define WIDTH       960
#define HEIGHT      540
#define CONE        1
#define CYLINDER    2
#define PLAN        3
#define SPHERE      4
#define TORUS       5

#define NO_MASK     0xFFFFFFFFFFFFFFFF

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
    float               angle;          /* Angle                                */
    cl_float3           collision;      /* Point collision ray                  */
    _Bool               end;            /* 1 -> next ; 0 -x end                 */
    size_t              id;             /* Id Group                             */
    cl_float3           normal;         /* Vector Normal                        */
    cl_float3           pos;            /* Position Object                      */
    float               radius;         /* radius of the object                 */
    unsigned int        color;          /* Calors of the object                 */
    cl_float3           rotate;         /* Angle of rotation                    */
    size_t              type;           /* Type Object                          */
    size_t              type_bump;      /* Type Bump Mapping                    */
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
    float               ambient;        /* Ambient light                        */
    float               diffuse;        /* Diffused light                       */
    _Bool               end;            /* 1 -> next ; 0 -x end                 */
    size_t              id;             /* Id Group                             */
    float               light;          /* Power light                          */
    cl_float3           pos;            /* Position spotlight                   */
    unsigned int        color;          /* Color light                          */
    float               specular;       /* Specular light                       */
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
    t_cam               cam;            /* Struct camera                        */
    t_mimg              mimg;           /* Struct Mapping Image x1y1 -> x2y2    */
    size_t              n_obj;          /* Number object                        */
    size_t              n_spt;          /* Number spotlight                     */
    size_t              resolution;     /* Super Sampling Resolution            */
};

struct                  s_env           /* Variable Master                      */
{
    SDL_Event           event;          /* Event SDL                            */
    _Bool               exit;           /* Var quit programme                   */
    t_opcl              cl;             /* Struct OpenCl                        */
    _Bool               config;         /* */
    char                host;           /* Host or not host                     */
    t_img               img;            /* Struct Image                         */
    t_key               key;            /* Struct Keyboard                      */
    _Bool               gpu;            /* Use GPU 1 yes 0 no                   */
    t_mouse             mouse;          /* Struct mouse                         */
    t_obj               *obj;           /* Struct Object                        */
    t_scn               scn;            /* Struct Scene                         */
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
    sockaddr_in         sck;            /**/
    int                 fds;            /**/
}                       t_slv;

cl_float3               add(register cl_float3 a, register cl_float3 b);
void                    bump_mapping(t_obj *obj);
void                    camera(register t_cam cam, t_ray *ray, register float x, register float y);
float                   check_object(t_obj *obj, register t_ray ray, size_t *id, size_t mask);
float                   cone(register t_obj obj, register t_ray ray);
cl_float3               coordinates_collision(register cl_float3 a, register cl_float3 b, register float det);
void                    create_window(t_env *e, Uint32 flags);
float                   cylinder(register t_obj obj, register t_ray ray);
void                    diffused_light(t_ray *ray, register t_spt spt, register t_obj obj);
float                   dot(register cl_float3 a, register cl_float3 b);
void                    err_cl(cl_int err);
void                    err_cl_sub(cl_int err);
void                    event_everything(t_env *e);
int                     event_RT(t_env *e);
void                    filtered_b_w(unsigned int *img, size_t resolution);
void                    filtered_rgb(unsigned int filter, unsigned int *img, size_t resolution);
void                    fps_info(void);
void                    get_camera(t_env *e, char **line);
unsigned int            get_color(char *str);
void                    get_cone(t_obj *obj, char **line);
void                    get_cylinder(t_obj *obj, char **line);
void                    get_file_mlt(t_env *e, char *file);
void                    get_file_obj(t_env *e, char *file);
void                    get_file_ort(t_env *e, char *file);
void                    get_file_ortv1(t_env *e, char *file);
char                    *get_file_raw(int fd);
void                    get_normal_object(t_obj *obj, register t_ray ray, register float det);
void                    get_ort(t_env *e, char **str);
void                    get_ort_cone(t_env *e, char **str, size_t *i);
void                    get_ort_config(t_env *e, char **str, size_t *i);
void                    get_ort_cylinder(t_env *e, char **str, size_t *i);
void                    get_ort_group(t_env *e, char **str, size_t *i);
void                    get_ort_plan(t_env *e, char **str, size_t *i);
void                    get_ort_scene(t_env *e, char **str, size_t *i);
void                    get_ort_sphere(t_env *e, char **str, size_t *i);
void                    get_ort_texture(t_env *e, char **str, size_t *i);
void                    get_ort_torus(t_env *e, char **str, size_t *i);
void                    get_plan(t_obj *obj, char **line);
void                    get_scene(t_env *e, char *file);
void                    get_sphere(t_obj *obj, char **line);
void                    get_spot(t_spt *spt, char **line);
void                    get_src_opencl(t_opcl *cl);
void                    get_torus(t_obj *obj, char **line);
cl_float3               get_vec3(char *str);
void                    *host(void *arg);
void                    init_keyboard(t_key *key);
void                    init_mouse(t_mouse *mouse);
void                    key_press(t_env *e);
void                    key_release(t_env *e);
void                    light(t_env *e, size_t id, t_obj tmp_obj, t_ray *ray);
unsigned int            limit(register float x);
void                    lunch_opencl(t_opcl *cl);
void                    OCL_run_raytracing(t_env *e);
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
float                   specular_light(register t_spt spt, register t_obj obj);
float                   sphere(register t_obj obj, register t_ray ray);
cl_float3               sub(register cl_float3 a, register cl_float3 b);
void                    super_sampling(t_env *e, t_ray *ray, cl_float2 pos, size_t resolution);
float                   torus(register t_obj obj, register t_ray ray);
cl_float3               vector_mult(register cl_float3 a, register cl_float3 b);
cl_float3               vector_mult_x(register cl_float3 vect, register float x);

float       perlin(cl_float2 n);

#endif
