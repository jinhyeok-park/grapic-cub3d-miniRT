/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:26:23 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 17:24:09 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define FALSE	0
# define TRUE	1
# define EPSILON 1e-6
# define CIRCLE 1
# define LIGHT 2
# define PLANE 3
# define CYLINDER 4
# define KSN 64;
# define KS 0.5;
# define EPYS 0.00001;

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef char				t_bool;
typedef long long			t_int64;
typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_hit_record	t_hit_record;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_color3
{
	double	r;
	double	g;
	double	b;
}	t_color3;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_plane
{
	t_point3	point;
	t_vec3		normal;
	t_color3	color;
}	t_plane;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
	t_color3	color;
}	t_sphere;

typedef struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}	t_light;

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
};

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

typedef struct s_object
{
	int			type;
	int			size;
	int			real_size;
	void		*element;
	t_color3	albedo;
}	t_object;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
}	t_mlx;

typedef struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
	t_point3	dir;
	double		fov;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_camera_helper
{
	t_point3	look_at;
	t_vec3		vup;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
}	t_camera_helper;

typedef struct s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		radius;
	double		height;
	t_color3	color;
}	t_cylinder;

typedef struct s_cylinder_calc
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	double	root1;
	double	m;
	double	m1;
}	t_cylinder_calc;

typedef struct s_input
{
	t_color3	ambient;
	t_camera	cam;
	t_light		*light;	
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	int			num_amb;
	int			num_cam;
	int			num_sp;
	int			num_pl;
	int			num_cy;
	int			num_li;
	int			total_object;
}	t_input;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		**world;
	t_object		**light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

//main.c
int				close_window(int keycode);
int				key_hook(int keycode);
//camera.c
t_canvas		canvas(int width, int height);
double			degrees_to_radians(double degrees);
t_camera		camera(t_canvas *canvas, t_point3 orig, \
					double fov, t_vec3 direction);

//color.c
t_color3		color3(double r, double g, double b);
t_color3		cplus(t_color3 vec, t_color3 vec2);
t_color3		cmult(t_color3 vec, double t);
t_color3		cmult_(t_color3 vec, t_color3 col);
t_color3		cmin(t_color3 vec1, t_color3 vec2);

//cylinder.c
t_cylinder		*cylinder(t_point3 center, double radius, double height, \
					t_vec3 normal);
void			set_face_normal_cylinder(t_ray *r, t_hit_record *rec, \
									t_vec3 outward_normal);
t_bool			check_cylinder_root(double root, double m, t_hit_record *rec, \
						t_cylinder *cy);
t_cylinder_calc	calculate_cylinder_params(t_cylinder *cy, t_ray *ray);
void			update_cylinder_roots_and_m(t_cylinder_calc *calc, \
								t_cylinder *cy, t_ray *ray);
t_bool			hit_cylinder_side(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_side);
t_bool			hit_cylinder_top_cap(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_cap);
t_bool			hit_cylinder_bottom_cap(t_cylinder *cy, t_ray *ray, \
							t_hit_record *rec, double *t_cap);
t_bool			hit_cylinder_caps(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_cap);
void			handle_hit_side(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double t_side);
void			handle_hit_caps(t_cylinder *cy, t_ray *ray, t_hit_record *rec, \
					double *caps);
t_bool			hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);

//light
t_light			*light_point(t_point3 light_origin, t_color3 light_color, \
					double bright_ratio);

//object
t_object		**create_object(int size);
void			object_add(t_object **vector, void *ele, \
							int type, t_color3 albedo);

//parsing
int				check_file(int ac, char **av);
void			free_split(char **s);
void			ft_error(char *str);
int				ft_strcmp(char *s1, char *s2);
double			ft_atod(const char *str);
t_color3		get_color(char *s);
t_vec3			get_vec(char *s);
void			parse_ambient(t_input *src, char **tocken);
void			parse_camera(t_input *src, char **tockens);
void			parse_light(t_input *src, char **tockens);
void			parse_sphere(t_input *src, char **tockens);
t_vec3			get_vec_plane(char *s);
void			parse_plane(t_input *src, char **tockens);
void			validate_tokens(char **tokens);
void			check_normal_vector(t_vec3 normal);
void			set_cylinder_properties(t_cylinder *cylinder, char **tokens);
void			parse_cylinder(t_input *src, char **tokens);
void			parse_line(char *line, char **tmp, t_input *input_data);
void			count_object(char *line, t_input *input_data);
void			malloc_object(t_input *input_data);
void			initialize_input_data(t_input *input_data);
void			process_file(int fd, t_input *input_data);
void			parse_file(int fd, t_input *input_data);
void			parsing(int ac, char **av, t_input *input_data);

//pixel
void			write_color(t_color3 pixel_color, t_data *img, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

//plane
t_bool			hit_plane(t_plane *p, t_ray *ray, t_hit_record *rec);
t_plane			*plane(t_point3 point, t_vec3 normal);

//record
t_hit_record	record_init(void);

//scene
void			scene_init(t_scene *s, t_input *input_data);
void			init_canvas_camera(t_scene *s, t_input *input_data);
void			create_objects_lights(t_scene *s, t_input *input_data, \
							t_object ***obj, t_object ***lights);

//sphere
t_sphere		*sphere(t_point3 center, double radius);
t_bool			hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
void			set_face_normal(t_ray *r, t_hit_record *rec);
double			get_discriminant(t_sphere *sp, t_ray *ray);

//trace
t_ray			ray(t_point3 orig, t_vec3 dir);
t_point3		ray_at(t_ray *ray, double t);
t_ray			ray_primary(t_camera *cam, double u, double v);
t_color3		ray_color(t_scene *s);
t_color3		phong_lighting(t_scene *scene);
t_color3		point_light_get(t_scene *scene, t_light *light);
t_color3		diffus_get(t_scene *s, t_vec3 light_dir, t_light *light);
t_color3		specular_get(t_scene *s, t_light *light, t_vec3 light_dir);
t_bool			hit_divide2(int index, t_scene *s, t_ray *ray, \
					t_hit_record *local_rec);
t_bool			hit(t_scene *s, t_ray *ray, t_hit_record *rec);
t_bool			hit_divide(int index, t_scene *s, t_ray *ray, \
					t_hit_record *rec);
t_bool			is_shadow(t_scene *s, t_light *light);

//vector3
t_vec3			vec3(double x, double y, double z);
t_point3		point3(double x, double y, double z);
void			vset(t_vec3 *vec, double x, double y, double z);
double			vlength2(t_vec3 vec);
double			vlength(t_vec3 vec);
t_vec3			vplus(t_vec3 vec, t_vec3 vec2);
t_vec3			vplus_(t_vec3 vec, double x, double y, double z);
t_vec3			vminus(t_vec3 vec, t_vec3 vec2);
t_vec3			vminus_(t_vec3 vec, double x, double y, double z);
t_vec3			vmult(t_vec3 vec, double t);
t_vec3			vmult_(t_vec3 vec, t_vec3 vec2);
t_vec3			vdivide(t_vec3 vec, double t);
double			vdot(t_vec3 vec, t_vec3 vec2);
t_vec3			vcross(t_vec3 vec, t_vec3 vec2);
t_vec3			vunit(t_vec3 vec);
t_vec3			vmin(t_vec3 vec1, t_vec3 vec2);
t_vec3			reflect(t_vec3 v, t_vec3 n);

#endif