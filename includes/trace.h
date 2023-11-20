/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:42:31 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/17 22:57:15 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

#include "ray.h"
#include "camera.h"

t_ray       ray(t_point3 *origin, t_vec3 *direction);
t_point3    ray_headpoint(t_ray *ray, double distance);
t_ray       ray_primary(t_camera *cam, double x, double y);
//t_color3	ray_color(t_ray *ray);
t_color3    ray_color(t_ray *r, t_sphere *sphere);


#endif