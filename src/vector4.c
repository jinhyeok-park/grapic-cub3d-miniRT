/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:39:57 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/15 21:23:24 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

double  vec_dot(t_vec3 *vec, t_vec3 *vec2)
{
	return (vec->x * vec2->x + vec->y * vec2->y + vec->z * vec2->z);
}

t_vec3  vec_cross(t_vec3 *vec, t_vec3 *vec2)
{
	t_vec3	ret;

	ret.x = vec->y * vec2->z - vec->z * vec2->y;
	ret.y = vec->z * vec2->x - vec->x * vec2->z;
	ret.z = vec->x * vec2->y - vec->y * vec2->x;
	return (ret);
}

t_vec3  vec_unit(t_vec3 *vec)
{
	double	len;
	t_vec3	ret;
	
	len = getVecLen(vec);
	if (len == 0)
	{
		printf("Error\n:Devider is 0");
		exit(0);
	}
	ret.x = vec->x / len;
	ret.y = vec->y / len;
	ret.z = vec->z / len;
	return (ret);
}

t_vec3  vec_min(t_vec3 *vec1, t_vec3 *vec2)
{
	t_vec3	ret;

	if (vec1->x > vec2->x)
		ret.x = vec2->x;
	else 
		ret.x = vec1->x;

	if (vec1->y > vec2->y)
		ret.y = vec2->y;
	else
		ret.y = vec1->y;

	if (vec1->z > vec2->z)
		ret.z = vec2->z;
	else
		ret.z = vec1->z;
	return (ret);
}

t_point3	point_move_minus(t_point3 *point, t_vec3 *vec)
{
	t_point3 ret;

	ret.x = point->x - vec->x;
	ret.y = point->y - vec->y;
	ret.z = point->z - vec->z;
	return (ret);
}