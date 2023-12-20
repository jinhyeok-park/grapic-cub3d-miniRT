/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:04:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/20 14:46:10 by jinhyeok         ###   ########.fr       */
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



#endif