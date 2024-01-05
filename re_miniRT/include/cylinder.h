/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:22:23 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/05 22:19:59 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "ray.h"
# include "object.h"

# define EPSILON 1e-6

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

t_cylinder	*cylinder(t_point3 center, double radius, double height, \
					t_vec3 normal);
void	set_face_normal_cylinder(t_ray *r, t_hit_record *rec, \
									t_vec3 outward_normal);
t_bool	check_cylinder_root(double root, double m, t_hit_record *rec, \
						t_cylinder *cy);
t_cylinder_calc	calculate_cylinder_params(t_cylinder *cy, t_ray *ray);
void	update_cylinder_roots_and_m(t_cylinder_calc *calc, \
								t_cylinder *cy, t_ray *ray);
t_bool	hit_cylinder_side(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_side);
t_bool	hit_cylinder_top_cap(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_cap);
t_bool	hit_cylinder_bottom_cap(t_cylinder *cy, t_ray *ray, \
							t_hit_record *rec, double *t_cap);
t_bool	hit_cylinder_caps(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_cap);
void	handle_hit_side(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double t_side);
void	handle_hit_caps(t_cylinder *cy, t_ray *ray, t_hit_record *rec, \
					double *caps);
t_bool		hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);

#endif