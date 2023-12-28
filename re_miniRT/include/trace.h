/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:04:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/28 23:52:27 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
#define TRACE_H

#include "scene.h"

t_ray       ray(t_point3 orig, t_vec3 dir);
t_point3    ray_at(t_ray *ray, double t);
t_ray       ray_primary(t_camera *cam, double u, double v);
//t_color3    ray_color(t_ray *r);
//t_color3    ray_color(t_ray *ray, t_sphere *sp);
//t_color3    ray_color(t_ray *ray, t_object **obj);
t_color3    ray_color(t_scene *s);
t_color3        phong_lighting(t_scene *scene);
t_color3        point_light_get(t_scene *scene, t_light *light);


//t_bool  hit_divide(int index, t_scene *s);
t_bool  hit(t_scene *s, t_ray *ray, t_hit_record *rec);
t_bool  hit_divide(int index, t_scene *s, t_ray *ray, t_hit_record *rec);
t_bool  is_shadow(t_scene *s, t_light *light);

// t_bool  hit_divide1(int index, t_scene *s);
// t_bool  hit1(t_scene *s, t_ray *ray, t_hit_record *rec);
//t_bool      hit(t_scene *s);
// t_bool      hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
// t_bool      hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);

#endif