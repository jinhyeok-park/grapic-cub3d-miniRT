/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:48:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/15 23:05:06by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "sphere.h"

t_ray	ray(t_point3 *origin, t_vec3 *direction)
{
	t_ray ray;

	ray.origin = *origin;
	ray.direction = *direction;
	return (ray);
}

t_point3	ray_headpoint(t_ray *ray, double distance)
{
	t_point3	ret;
	t_vec3		temp;

	temp = vec_multi_scala(&(ray->direction), distance);
	ret = vec_plus(&ray->origin, &temp);
	return (ret);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray		ret;
	t_vec3		multi_result;
	t_point3	temp;

	ret.origin = cam->camera_position;
	multi_result = vec_multi_scala(&(cam->horiziontal_vec), u);
	temp = point_move_plus(&(cam->left_bottom_p), &multi_result);
	multi_result = vec_multi_scala(&(cam->vertical_vec), v);
	temp = point_move_minus(&temp, &multi_result);
	ret.direction = vec3_bypoint(&temp, &(cam->camera_position));
	return (ret);
}

#include <stdio.h>
#include "hit_record.h"
#include "object.h"
#include "scene.h"
#include "light.h"

// t_color3    ray_color1(t_ray *r, t_object **obj_vector)
// {
//     double  	t;
// 	int			i;
// 	int			size;
// 	t_color3	temp;
// 	t_color3	temp2;
// 	t_hit_record rec;

// 	rec.tmin = 0;
// 	rec.tmax = __DBL_MAX__;

// 	i = -1;
// 	while ((*obj_vector)->size > ++i)
// 	{
// 		if (obj_vector[i]->type == CIRCLE)
// 		{
// 			t_sphere *sphere;
			
// 			sphere = (t_sphere *)obj_vector[i]->element;
// 			if (sphere_hit(sphere, r, &rec))
// 			{
// 				// t_point3 point;
// 				// t_color3 ret;
// 				// t_vec3	vec_temp;
// 				// point = ray_headpoint(r, rec.t);
// 				// t_vec3 vect = vec3_bypoint(&point, &(sphere->center));
// 				// vec_temp = vec_unit(&vect);
// 				// ret = color3((vec_temp.x + 1) * 0.5, (vec_temp.y + 1) * 0.5, (vec_temp.z + 1) * 0.5);
// 				// return (ret);
// 				return (phong_lighting(scene));
// 			}
// 		}
// 	}
//     t = 0.5 * (r->direction.y + 1.0);
// 	temp = color3(1, 1, 1);
// 	temp2 = color3(0.5, 0.7, 1.0);
// 	temp = color_multi_scala(&temp, 1.0 - t);
// 	temp2 = color_multi_scala(&temp2, t);
// 	return (color_plus(&temp, &temp2));
// }

#include <stdio.h>

t_color3    ray_color2(t_scene *s)
{
    double  	t;
	int			i;
	int			size;
	t_color3	temp;
	t_color3	temp2;
	t_hit_record rec;

	rec.tmin = 0.000001;
	rec.tmax = __DBL_MAX__;

	i = -1;
	//while ((*obj_vector)->size > ++i)
	size = s->world[0]->size;
	while (++i < size)
	{
		//if (obj_vector[i]->type == CIRCLE)
		if (s->world[i]->type == CIRCLE)
		{
			t_sphere *sphere;
			
			sphere = (t_sphere *)s->world[i]->element;
			if (sphere_hit(sphere, &(s->ray), &rec))
			{
				s->rec = rec;
				// s->rec.albedo = s->world[i]->albedo;
				// printf("%f", s->world[i]->albedo.r);
				// printf("%f", s->world[i]->albedo.g);
				// printf("%f\n", s->world[i]->albedo.b);
				// printf("%f", s->rec.albedo.r);
				// printf("%f", s->rec.albedo.g);
				// printf("%f", s->rec.albedo.b);
				// exit(1);
				s->rec.albedo.r = 0.5;
				s->rec.albedo.g = 0;
				s->rec.albedo.b = 0;
				return (phong_lighting(s));
			}
		}
	}
	//exit(1);
    t = 0.5 * (s->ray.direction.y + 1.0);
	temp = color3(1, 1, 1);
	temp2 = color3(0.5, 0.7, 1.0);
	temp = color_multi_scala(&temp, 1.0 - t);
	temp2 = color_multi_scala(&temp2, t);
	return (color_plus(&temp, &temp2));
}

t_color3        phong_lighting(t_scene *scene)
{
    t_color3    light_color;
    t_object    **lights;
	int			i;
	int			size;

    light_color = color3(0, 0, 0);
    lights = scene->light;
	size = lights[0]->size;
	i = 0;
    while (i < size)
    {
        if(lights[i]->type == LIGHT)
		{
			// t_color3	temp;
			// temp = point_light_get(scene, &(lights[i]));
			// light_color = color_plus(&temp, &light_color);
            //light_color = vplus(light_color, point_light_get(scene, lights->element));
			t_color3 temp;
    		t_light *light_obj = (t_light *)(lights[i]->element); // t_light 타입으로 캐스팅
    		temp = point_light_get(scene, light_obj);
    		light_color = color_plus(&temp, &light_color);
			
		}
		i++;
    }
	light_color = color_plus(&(light_color), &(scene->ambient));
	// printf("%f ", light_color.r);
	// 		printf("%f ", light_color.g);
	// 		printf("%f\n", light_color.b);
	t_color3 temp = color_multi(&light_color, &(scene->rec.albedo));
	t_color3 temp2 = color3(1,1,1);
	t_color3 color_ret = color_min(&temp, &temp2);
    return (color_ret);
}

#include <math.h>

t_color3        point_light_get(t_scene *s, t_light *light)
{  
    t_color3    diffuse;
    t_vec3      light_dir;
	t_vec3		temp;
    double      kd; // diffuse의 강도

	t_color3    specular;
    t_vec3      view_dir;
    t_vec3      reflect_dir;
    double      spec;
    double      ksn;
    double      ks;

	// printf("%f ", light->origin.x);
	// printf("%f ", light->origin.y);
	// printf("%f", light->origin.z);
	// printf("%f ", s->rec.p.x);
	// printf("%f ", s->rec.p.y);
	// printf("%f", s->rec.p.z);
	temp = vec3_bypoint((&light->origin), &(s->rec.p));
    //light_dir = vunit(vminus(light->origin, scene->rec.p)); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	light_dir = vec_unit(&temp);
    // cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
    //kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	kd = vec_dot((&s->rec.normal), &light_dir);
	kd = fmax(kd, 0.0);
	diffuse = color_multi_scala(&(light->light_color), kd);
	// printf("%f ", diffuse.r);
	// printf("%f ", diffuse.g);
	// printf("%f\n", diffuse.b);
	return (diffuse);

	view_dir = vec_multi_scala((&s->ray.direction), -1);
	//view_dir = vunit(vmult(scene->ray.dir, -1));
	view_dir = vec_unit(&view_dir);
	reflect_dir = vec_multi_scala(&light_dir, -1);
	reflect_dir = reflect(&reflect_dir, &(s->rec.normal));

    //reflect_dir = reflect(vmult(light_dir, -1), scene->rec.normal);
    ksn = 64; // shininess value
    ks = 0.5; // specular strength
	spec = vec_dot(&view_dir, &reflect_dir);
	spec = fmax(spec, 0.0);
	spec = pow(spec, ksn);
	specular = color_multi_scala(&(light->light_color), ks);
	specular = color_multi_scala(&specular, spec);
	diffuse = color_plus(&diffuse, &specular);
    //spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
    //specular = vmult(vmult(light->light_color, ks), spec);
    //return (vplus(diffuse, specular));
    return (diffuse);
}

// t_color3    ray_color(t_ray *r, t_sphere *sphere)
// {
//     double  	t;
// 	t_color3	temp;
// 	t_color3	temp2;
// 	t_hit_record rec;

// 	rec.tmin = 0;
// 	rec.tmax = __DBL_MAX__;
// 	//if (sphere_hit(sphere, r, rec))
// 	if (sphere_hit(sphere, r, &rec))
// 	{
// 		t_point3 point;
// 		t_color3 ret;
// 		t_vec3	vec_temp;
// 		point = ray_headpoint(r, rec.t);
// 		t_vec3 vect = vec3_bypoint(&point, &(sphere->center));
// 		vec_temp = vec_unit(&vect);

// 		ret = color3((vec_temp.x + 1) * 0.5, (vec_temp.y + 1) * 0.5, (vec_temp.z + 1) * 0.5);
// 		return (ret);
// 	}
//     t = 0.5 * (r->direction.y + 1.0);// linear 
// 	temp = color3(1, 1, 1);
// 	temp2 = color3(0.5, 0.7, 1.0);
// 	temp = color_multi_scala(&temp, 1.0 - t);
// 	temp2 = color_multi_scala(&temp2, t);
// 	return (color_plus(&temp, &temp2));
//     //return (vec_plus(vec_mult(color3(1, 1, 1), 1.0 - t), vec_mult(color3(0.5, 0.7, 1.0), t)));
// }
