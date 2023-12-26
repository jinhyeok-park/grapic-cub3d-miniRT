/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:04:39 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/26 20:33:05 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "light.h"
#include "plane.h"

void    scene_init(t_scene *s)
{
    s->canvas = canvas(1000, 800);
    s->camera = camera(&(s->canvas), point3(0, 0, 0));
    double ka;
    t_object **lights;
    t_light *li;

    t_sphere    *sp;
    t_sphere    *sp1;
    t_sphere    *sp2;
    t_plane     *p;
    // t_plane     *p1;

    sp = sphere(point3(1, 0, -10), 2);
    sp1 = sphere(point3(-1, 0, -10), 2);
    sp2= sphere(point3(0, -1000, 0), 994);
    p = plane(point3(0,0,0), vec3(0,0.5,0));
    // p1 = plane(point3(0,0,0), vec3(0.5,0,0));
    t_object **obj;
    
    obj = create_object();
    // object_add(obj, p1, PLANE, color3(1,1,1));
    object_add(obj, p, PLANE, color3(0,0,1));
    object_add(obj, sp, CIRCLE, color3(0.5, 0, 0));
    object_add(obj, sp1, CIRCLE, color3(0, 0.5, 0));
    object_add(obj, sp2, CIRCLE, color3(1, 1, 1));

    lights = create_object();
    s->world = obj;
    s->light = NULL;
    li = light_point(point3(0,20,0), color3(1,1,1), 0.5);
    object_add(lights, (void*)li, LIGHT, color3(0,0,0));
    s->light = lights;
    ka = 0.1;
    s->ambient = cmult(color3(1, 1, 1), ka);
}
