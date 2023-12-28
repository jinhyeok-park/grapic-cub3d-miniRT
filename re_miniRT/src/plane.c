/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:03:54 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/27 18:50:18 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_plane *plane(t_point3 point, t_vec3 normal)
{
    t_plane *ret;

    ret = malloc(sizeof(t_plane));
    ret->point = point;
    ret->normal = normal;
    return (ret);
}

t_bool  hit_plane(t_plane *p, t_ray *ray, t_hit_record *rec)
{
    double  dot;
    t_vec3  vec;
    double  t;

    dot = vdot(ray->dir, p->normal);
    t = 0;
    if (dot < 0)
    {
        t = -(p->point.x * (p->normal.x - vec.x) + p->point.y * (p->normal.y - vec.y) + p->point.z * (p->point.z - vec.z) ) / dot;
        if (t >= 0)
        {
            rec->t = t;
            rec->p = vplus(ray->orig, vmult(ray->dir, t));
            rec->normal = p->normal;
            return (TRUE);
        }
        // vec = vmult(ray->dir, INFINITY);
        // vec = vminus(p->point, ray->orig);
        // t = vdot(p->normal, vec) / dot;
        // if (t >= 0) {
        //     rec->t = t;
        //     rec->p = vplus(ray->orig, vmult(ray->dir, t));
        //     rec->normal = p->normal;
        // }
        // return (TRUE);
    }
    return (FALSE);
}

// t_point3    intersect_plane(t_plane *p, t_vec3 vec, double dot, t_hit_record *rec, t_ray *ray)
// {
//     double t; //= -((plane.A * (pointOnPlane.x - direction.x) + plane.B * (pointOnPlane.y - direction.y) + plane.C * (pointOnPlane.z - direction.z)) /
//                //  (plane.A * direction.x + plane.B * direction.y + plane.C * direction.z));
//     t = (p->point.x * (p->normal.x - vec.x) + p->point.y * (p->normal.y - vec.y) + p->point.z * (p->point.z - vec.z) ) / dot;
//     if (t >= 0)
//     {
//         rec->t = t;
//         ret->p = vplus(ray->)
//     }
// }