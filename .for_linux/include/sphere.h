/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:15:09 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/20 10:29:15 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "vector.h"
#include "ray.h"
#include "commontype.h"

typedef struct s_sphere
{
	t_point3    center;
	double      radius;
	double      radius_square;
} t_sphere;

t_bool		sphere_hit(t_sphere *sphere, t_ray *ray);
t_sphere	sphere(t_point3 center, double radius);

# endif