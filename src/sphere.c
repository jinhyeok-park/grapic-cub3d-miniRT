/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:14:51 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/16 01:37:13 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "trace.h"
#include "hit_record.h"
#include <math.h>


t_sphere sphere(t_point3 center, double radius)
{
    t_sphere ret;
    
    ret.center = center;
    ret.radius = radius;
    ret.radius_square = radius * radius;
    return (ret);
}

#include <stdio.h>

t_bool  sphere_hit(t_sphere *sphere, t_ray *ray, t_hit_record *rec)
{
    t_vec3  vec;
    double  a;
    double  b;
    double  c;
    double  dicrintmant;

    vec = vec3_bypoint(&(ray->origin), &(sphere->center));
    a = vec_dot(&(ray->direction), &(ray->direction));
    b = vec_dot(&vec, &(ray->direction));
    c = vec_dot(&vec, &vec) - sphere->radius_square;

    dicrintmant = b * b - (a * c);

    if (dicrintmant < 0)
        return (FALSE);
    double sqrtd = (double)sqrt(dicrintmant);
    double root = (- b - sqrtd) / a;
    if (root < rec->tmin || rec->tmax < root)
    {
     root = (- b + sqrtd) / a;
     if (root < rec->tmin || rec->tmax < root)
          return (FALSE);
    }
    rec->t = root;
    rec->p = ray_headpoint(ray, root);
    rec->normal = vec3_bypoint(&(rec->p), &(sphere->center));
    rec->normal = vec_divide_scala(&(rec->normal), sphere->radius);
    set_face_normal(ray, rec);
    return (TRUE);
}

void    set_face_normal(t_ray *ray, t_hit_record *rec)
{
    rec->front_face = vec_dot(&(ray->direction), &(rec->normal));
    if (rec->front_face < 0)
        rec->normal = vec_multi_scala(&(rec->normal), -1);
}
