/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:57:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 15:56:03 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "light.h"

t_scene	*scene_init(void)
{
    t_scene     *ret;
    t_point3    camera_point; // parsing 
    t_sphere    sphere1;
    t_sphere    sphere2;
    t_sphere    sphere3;
    t_object    **obj;
    t_object    **lights;

    sphere1 = sphere(point3(-2, 0, -15), 2);
    sphere2 = sphere(point3(2, 0, -15), 2);
    sphere3 = sphere(point3(0, -1000, 0), 994);
    obj = vector_create();
    lights = vector_create();
    vector_push_back(obj, &sphere1, CIRCLE);
    vector_push_back(obj, &sphere2, CIRCLE);
    vector_push_back(obj, &sphere3, CIRCLE);

    t_light *temp;
    temp = light_point(point3(0,5,0), color3(1,1,1), 0.5);
    vector_push_back(lights, temp, LIGHT);

    camera_point = point3(0,0,0);
    ret = malloc(sizeof(t_scene));
    if (!ret)
        exit(1);
    ret->canvas = canvas(1980, 1080);
    ret->camera = camera(&(ret->canvas), camera_point);
    ret->world = obj;
    ret->light = lights;
    double ka = 0.1;
    ret->ambient = color3(1 * ka, 1 * ka, 1 * ka);
    return (ret);
}