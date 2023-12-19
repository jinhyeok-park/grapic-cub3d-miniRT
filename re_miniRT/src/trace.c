/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:03:40 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/19 21:02:47 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "color3.h"
#include "record.h"

t_ray       ray(t_point3 orig, t_vec3 dir)
{
    t_ray ray;

    ray.orig = orig;
    ray.dir = vunit(dir);
    return (ray);
}

t_point3    ray_at(t_ray *ray, double t)
{
    t_point3 at;

    at = vplus(ray->orig, vmult(ray->dir, t));
    return (at);
}

t_ray       ray_primary(t_camera *cam, double u, double v)
{
    t_ray   ray;

    ray.orig = cam->orig;
    ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom, vmult(cam->horizontal, u)), vmult(cam->vertical, v)), cam->orig));
    return (ray);
}

t_color3    ray_color(t_ray *ray, t_sphere *sp)
{
    double  t;
    t_vec3  n;

    t_hit_record    rec;

    rec.tmin = 0;
    rec.tmax = INFINITY;
    if (hit_sphere(sp, ray, &rec))
    {
        t_vec3  temp = vmult(vplus(rec.normal, vec3(1, 1, 1)), 0.5);
        t_color3 ret = color3(temp.x, temp.y, temp.z);
        return (ret);
    }
    t = 0.5 * (ray->dir.y + 1.0);
    return (cplus(cmult(color3(1, 1, 1), 1.0 - t), cmult(color3(0.5, 0.7, 1.0), t)));
}
