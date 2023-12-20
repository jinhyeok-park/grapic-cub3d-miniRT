/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:03:40 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/20 14:55:03 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "sphere.h"


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

//t_color3    ray_color(t_ray *ray, t_sphere *sp)
// t_color3    ray_color(t_ray *ray, t_object **obj)
// {
//     double  t;
//     int     i;
//     int     size;
//     t_vec3  n;

//     t_hit_record    rec;

//     rec.tmin = 0;
//     rec.tmax = INFINITY;
//     i = 0;
//     size = obj[0]->size;
//     while (i < size)
//     {
//         if (obj[i]->type == CIRCLE)
//         {
//             t_sphere *sp;

//             sp = (t_sphere *)obj[i]->element;
//             if (hit_sphere(sp, ray, &rec))
//             {
//                 t_vec3  temp = vmult(vplus(rec.normal, vec3(1, 1, 1)), 0.5);
//                 t_color3 ret = color3(temp.x, temp.y, temp.z);
//                 return (ret);
//             }
//         }
//         i++;
//     }
//     // if (hit_sphere(sp, ray, &rec))
//     // {
//     //     t_vec3  temp = vmult(vplus(rec.normal, vec3(1, 1, 1)), 0.5);
//     //     t_color3 ret = color3(temp.x, temp.y, temp.z);
//     //     return (ret);
//     // }
//     t = 0.5 * (ray->dir.y + 1.0);
//     return (cplus(cmult(color3(1, 1, 1), 1.0 - t), cmult(color3(0.5, 0.7, 1.0), t)));
// }
#include <stdio.h>
t_color3    ray_color(t_scene *s)
{
    double      t;
    int         i;
    int         size;
    t_vec3          n;

    i = 0;
    s->rec = record_init();
    size = s->world[0]->size;
    while (i < size)
    {
        if (s->world[i]->type == CIRCLE)
        {
            t_sphere *sp;
            sp = (t_sphere *)s->world[i]->element;
            if (hit_sphere(sp, &(s->ray), &(s->rec)))
            {
                // t_vec3  temp = vmult(vplus(s->rec.normal, vec3(1, 1, 1)), 0.5);
                // t_color3 ret = color3(temp.x, temp.y, temp.z);
                s->rec.albedo.r = s->world[i]->albedo.r;
                s->rec.albedo.g = s->world[i]->albedo.g;
                s->rec.albedo.b = s->world[i]->albedo.b;
                //return (ret);
                return (phong_lighting(s));
            }
        }
        i++;
    }
    t = 0.5 * (s->ray.dir.y + 1.0);
    return (cplus(cmult(color3(1, 1, 1), 1.0 - t), cmult(color3(0.5, 0.7, 1.0), t)));
}

t_color3        phong_lighting(t_scene *scene)
{
    t_color3    light_color;
    t_object    **lights;
    int         size;
    int         i;

    light_color = color3(0, 0, 0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
    lights = scene->light;
    i = 0;
    size = scene->light[0]->size;
    while (i < size)
    {
        if (scene->light[i]->type == LIGHT)
        {
            light_color = cplus(light_color, point_light_get(scene, (t_light *)scene->light[i]->element));
        }
        i++;
    }

    // while (lights) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
    // {
    //     if(lights->type == LIGHT_POINT)
    //         light_color = vplus(light_color, point_light_get(scene, lights->element));
    //     lights = lights->next;
    // }
    light_color = cplus(light_color, scene->ambient);
    return (cmin(cmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
    //모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}

#include "light.h"

t_color3        point_light_get(t_scene *scene, t_light *light)
{
    t_color3    diffuse;
    t_vec3      light_dir;
    double      kd; // diffuse의 강도

    t_color3    specular;
    t_vec3      view_dir;
    t_vec3      reflect_dir;
    double      spec;
    double      ksn;
    double      ks;

    light_dir = vunit(vminus(light->origin, scene->rec.p)); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
    // cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
    kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
    diffuse = cmult(light->light_color, kd);
    view_dir = vunit(vmult(scene->ray.dir, -1));
    reflect_dir = reflect(vmult(light_dir, -1), scene->rec.normal);
    ksn = 64; // shininess value
    ks = 0.5; // specular strength
    spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
    specular = cmult(cmult(light->light_color, ks), spec);
    return (cplus(diffuse, specular));
    // return (diffuse);
}