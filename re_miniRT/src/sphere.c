/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:54:38 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/02 14:44:01 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "trace.h"

t_sphere *sphere(t_point3 center, double radius)
{
    t_sphere *ret;
    
    ret = malloc(sizeof(t_sphere));
    ret->center = center;
    ret->radius = radius;
    ret->radius2 = radius * radius;
    return (ret);
}

t_bool      hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
    t_vec3  oc;
    double  a;
    double  b;
    double  c;
    double  discriminant;
    double  sqrtd;
    double  root;

    oc = vminus(ray->orig, sp->center);
    a = vlength2(ray->dir);
    b = vdot(oc, ray->dir);
    c = vlength2(oc) - sp->radius2;
    discriminant = b * b - a * c;

    if (discriminant < 0)
        return (FALSE);
    sqrtd = sqrt(discriminant);
    root = (-b - sqrtd) / a;
    if (root < rec->tmin || rec->tmax < root)
    {
        root = (-b + sqrtd) / a;
        if (root < rec->tmin || rec->tmax < root)
            return (FALSE);
    }
    rec->t = root;
    rec->p = ray_at(ray, root);
    rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터.
    set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
    return (TRUE);
}

void    set_face_normal(t_ray *r, t_hit_record *rec)
{
    if (vdot(r->dir, rec->normal) < 0)
        rec->front_face = -1;
    else
        rec->front_face = 1;
    if (rec->front_face)
        rec->normal = rec->normal;
    else
        rec->normal = vmult(rec->normal, -1);
}