/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:14:51 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/23 17:03:16 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere sphere(t_point3 center, double radius)
{
    t_sphere ret;
    
    ret.center = center;
    ret.radius = radius;
    ret.radius_square = radius * radius;
    return (ret);
}

t_bool  sphere_hit(t_sphere *sphere, t_ray *ray)
{
    t_vec3  vec;
    double  a;
    double  b;
    double  c;
    double  dicrintmant;

    vec = vec3_bypoint(&(ray->origin), &(sphere->center));
    a = vec_dot(&(ray->direction), &(ray->direction));
    b = 2.0 * vec_dot(&vec, &(ray->direction));
    //b = 2.0 * vec_dot(&(ray->direction), &vec);
    c = vec_dot(&vec, &vec) - sphere->radius_square;
    dicrintmant = b * b - (4.0 * a * c);
    if (dicrintmant > 0)
    {
        return (TRUE);
    }
    return (FALSE);
}
