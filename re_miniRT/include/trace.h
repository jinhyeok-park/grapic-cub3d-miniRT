/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:04:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/05 22:23:28 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "scene.h"
# define KSN 64;
# define KS 0.5;
# define EPYS 0.00001;

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *s);
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_color3	diffus_get(t_scene *s, t_vec3 light_dir, t_light *light);
t_color3	specular_get(t_scene *s, t_light *light, t_vec3 light_dir);
t_bool		hit_divide2(int index, t_scene *s, t_ray *ray, \
					t_hit_record *local_rec);
t_bool		hit(t_scene *s, t_ray *ray, t_hit_record *rec);
t_bool		hit_divide(int index, t_scene *s, t_ray *ray, t_hit_record *rec);
t_bool		is_shadow(t_scene *s, t_light *light);
t_bool		shadow_hit(t_scene *s, t_ray light_ray, t_hit_record light_rec);

#endif