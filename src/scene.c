/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:57:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/18 21:21:38 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "light.h"

t_scene *scene_init3(void)
{
    t_scene *scene = malloc(sizeof(t_scene));
    if (!scene)
        exit(1);

    scene->canvas = canvas(1980, 1080);

    scene->camera = camera(&(scene->canvas), point3(0, 0, -10));

    scene->world = vector_create();
    t_sphere *circle = malloc(sizeof(t_sphere));
    *circle = sphere(point3(-2, 0, -15), 2);
    vector_push_back(scene->world, circle, CIRCLE);
    scene->world[0]->albedo = color3(0.5 , 0 , 0);

    t_sphere *circle2 = malloc(sizeof(t_sphere));
    *circle2 = sphere(point3(2, 0, -15), 2);
    vector_push_back(scene->world, circle2, CIRCLE);
    scene->world[1]->albedo = color3(0 , 0.5 , 0);


    t_sphere *circle3 = malloc(sizeof(t_sphere));
    *circle3 = sphere(point3(0, -1000, 0), 994);
    vector_push_back(scene->world, circle3, CIRCLE);
    scene->world[2]->albedo = color3(1 , 1 , 1);

    scene->light = vector_create();
    t_light *temp = malloc(sizeof(t_light));
    temp = light_point(point3(-5, 5, -5), color3(1, 1, 1), 0.5);
    vector_push_back(scene->light, temp, LIGHT);

    double ka = 0.1;
    scene->ambient = color3(1 * ka, 1 * ka, 1 * ka);

    return scene;
}