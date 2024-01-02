/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:19:41 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/02 17:34:59y jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "cylinder.h"

#include <stdio.h>

t_cylinder *cylinder(t_point3 center, double radius, double height, t_vec3 normal)
{
	t_cylinder *ret;

	ret = malloc(sizeof(t_cylinder));
	ret->center = center;
	ret->radius = radius;
	ret->height  = height;
    ret->normal = normal;
	return (ret);
}

static void set_face_normal(t_ray *r, t_hit_record *rec, t_vec3 outward_normal)
{
	rec->front_face = vdot(r->dir, outward_normal) < 0;
	rec->normal = rec->front_face ? outward_normal : vmult(outward_normal, -1);
}

t_bool hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
    // C = cy->center;
    // A = cy->center * (cy->height / 2 * cy->normal);
    //
    t_vec3 x;
    double  a;
    double  b;
    double  c;
    double  dis;
    double  root;
    double  root1;
    double  sqrtd;

    x = vminus(ray->orig, cy->center);
    a = vdot(ray->dir, ray->dir) - pow((vdot(ray->dir, cy->normal)), 2);
    b = vdot(ray->dir, x) - vdot(ray->dir, cy->normal) * vdot(x, cy->normal);
    c = vdot(x, x) - pow(vdot(x, cy->normal), 2) - (cy->radius * cy->radius);

    dis = b * b - a * c;
    if (dis < 0)
    {
        //printf("hit false\n");
        return (FALSE);
    }
    sqrtd = sqrt(dis);
    root = (-b - sqrtd) / a;
    root1 = (-b + sqrtd) / a;

    if (root >= rec->tmin && root <= rec->tmax)
    {
        //printf("hit\n");
        root = root;
    }
    else if (root1 >= rec->tmin && root1 <= rec->tmax)
    {
        //printf("hit");
        root = root1;
    }
    else
        return FALSE;
    double  m;
    m = vdot(ray->dir, vmult(cy->normal, root)) + vdot(x, cy->normal);
    if (m > cy->height || m < 0)
        return FALSE;
    rec->t = root;
    rec->p = ray_at(ray, root);
    t_vec3  normal;
    normal = vminus(vminus(rec->p, cy->center), vmult(cy->normal, m));
    rec->normal = vunit(normal);
    
    //t_vec3 outward_normal = vunit(vminus(vminus(rec->p, cy->center), vmult(cy->normal, vdot(vminus(rec->p, cy->center), cy->normal))));
    //rec->normal = outward_normal;
    //rec->normal = cy->normal; // 정규화된 법선 벡터.
    //set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
    // set_face_normal(ray, rec, outward_normal);
    return (TRUE);
}


// t_bool hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
// {
//     t_vec3 oc = vminus(ray->orig, cy->center);
//     double a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
//     double b = 2.0 * (oc.x * ray->dir.x + oc.z * ray->dir.z);
//     double c = oc.x * oc.x + oc.z * oc.z - cy->radius * cy->radius;
//     double discriminant = b * b - 4 * a * c;
//     double min_root = INFINITY;
//     t_vec3 outward_normal;

//     // Check for intersection with the side of the cylinder
//     if (discriminant >= 0) {
//         double sqrtd = sqrt(discriminant);
//         for (int i = 0; i < 2; i++) {
//             double root = (-b + (i == 0 ? -1 : 1) * sqrtd) / (2.0 * a);
//             double y = ray->orig.y + root * ray->dir.y;
//             if (root < rec->tmin || rec->tmax < root || y < cy->center.y || y > cy->center.y + cy->height)
//                 continue;

//             if (root < min_root) {
//                 min_root = root;
//                 outward_normal = (t_vec3){ (ray->orig.x + root * ray->dir.x - cy->center.x) / cy->radius, 0, (ray->orig.z + root * ray->dir.z - cy->center.z) / cy->radius };
//             }
//         }
//     }

//     // Check for intersection with the top and bottom caps
//     for (int i = 0; i < 2; i++) {
//         double y_plane = (i == 0) ? cy->center.y : cy->center.y + cy->height; // bottom or top cap
//         double t = (y_plane - ray->orig.y) / ray->dir.y;
//         if (t < rec->tmin || rec->tmax < t) continue;

//         double x = ray->orig.x + t * ray->dir.x;
//         double z = ray->orig.z + t * ray->dir.z;
//         if ((x - cy->center.x) * (x - cy->center.x) + (z - cy->center.z) * (z - cy->center.z) <= cy->radius * cy->radius) {
//             if (t < min_root) {
//                 min_root = t;
//                 outward_normal = (t_vec3){0, i == 0 ? -1 : 1, 0}; // normal pointing down for bottom, up for top
//             }
//         }
//     }

//     // If a valid intersection is found
//     if (min_root < rec->tmax) {
//         rec->t = min_root;
//         rec->p = ray_at(ray, min_root);
//         set_face_normal(ray, rec, outward_normal);
//         return TRUE;
//     }

//     return FALSE;
// }
