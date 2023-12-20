/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:54:30 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/19 19:48:03 jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPHERE_H
#define SPHERE_H

#include "vector3.h"
#include "commontype.h"
#include "record.h"
#include "ray.h"

typedef struct  s_sphere
{
    t_point3    center;
    double      radius;
    double      radius2;
} t_sphere;

//t_sphere    sphere(t_point3 center, double radius);
t_sphere *sphere(t_point3 center, double radius);
//double      hit_sphere(t_sphere *sp, t_ray *ray);
t_bool      hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
void        set_face_normal(t_ray *r, t_hit_record *rec);

#endif