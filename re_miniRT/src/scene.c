/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:04:39 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 11:05:35 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "light.h"
#include "plane.h"
#include "cylinder.h"

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
    t_plane     *p1;
    t_vec3      temp;

    sp = sphere(point3(5, 0, -10), 2);
    sp1 = sphere(point3(-5, 0, -10), 2);
    sp2= sphere(point3(0, -1000, 0), 996);
    temp = vec3(0, 1, 0);
    temp = vunit(temp);

    // p = plane(point3(0,10,-20), vec3(0,0,0.5));
   p = plane(point3(0,-10,-20), temp);
    temp = vec3(0, 0.7, -0.7);
    temp = vec3(0, 0, 0.7);
    temp = vunit(temp);
    p1 = plane(point3(0,0,-20), temp);
	t_cylinder *cy = cylinder(point3(0, 0, -10), 2, 5, temp);
    t_object **obj;
    
    obj = create_object();
    object_add(obj, p1, PLANE, color3(0.7,1,0));
    object_add(obj, p, PLANE, color3(0,0,1));
    object_add(obj, sp, CIRCLE, color3(0.5, 0, 0));
    object_add(obj, sp1, CIRCLE, color3(0, 0.5, 0));
    // object_add(obj, sp2, CIRCLE, color3(1, 1, 1));
	object_add(obj, cy, CYLINDER, color3(1, 0, 0));

    lights = create_object();
    s->world = obj;
    s->light = NULL;
    li = light_point(point3(0,20,0), color3(1,1,1), 0.5);
    object_add(lights, (void*)li, LIGHT, color3(0,0,0));
    s->light = lights;
    ka = 0.1;
    s->ambient = cmult(color3(1, 1, 1), ka);
}
