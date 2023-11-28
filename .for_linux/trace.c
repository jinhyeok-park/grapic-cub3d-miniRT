/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:48:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/28 20:32:32 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "sphere.h"
#include "hit_record.h"

t_ray	ray(t_point3 *origin, t_vec3 *direction)
{
	t_ray ray;

	ray.origin = *origin;
	ray.direction = *direction;
	return (ray);
}

t_point3	ray_headpoint(t_ray *ray, double distance)
{
	t_point3	ret;
	t_vec3		temp;

	temp = vec_multi_scala(&(ray->direction), distance);
	ret = vec_plus(&ray->origin, &temp);
	return (ret);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray		ret;
	t_vec3		multi_result;
	t_point3	temp;

	ret.origin = cam->camera_position;
	multi_result = vec_multi_scala(&(cam->horiziontal_vec), u);
	temp = point_move_plus(&(cam->left_bottom_p), &multi_result);
	multi_result = vec_multi_scala(&(cam->vertical_vec), v);
	temp = point_move_minus(&temp, &multi_result);
	ret.direction = vec3_bypoint(&temp, &(cam->camera_position));
	return (ret);
}
#include <stdio.h>

t_color3    ray_color(t_ray *r, t_sphere *sphere)
{
    double  	t;
	t_color3	temp;
	t_color3	temp2;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = __DBL_MAX__;
	if (sphere_hit(sphere, r))
	{
		return (color3(1,0,0));
	}
    t = 0.5 * (r->direction.y + 1.0);// linear 
	temp = color3(1, 1, 1);
	temp2 = color3(0.5, 0.7, 1.0);
	temp = color_multi_scala(&temp, 1.0 - t);
	temp2 = color_multi_scala(&temp2, t);
	return (color_plus(&temp, &temp2));
    //return (vec_plus(vec_mult(color3(1, 1, 1), 1.0 - t), vec_mult(color3(0.5, 0.7, 1.0), t)));
}
