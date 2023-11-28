/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:35:00 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/15 19:00:55 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

double	getVecLen(t_vec3 *vec)
{
	return (sqrt(getVecSize(vec)));
}

t_vec3	vec_plus(t_vec3 *vec, t_vec3 *vec2)
{
	t_vec3 ret;

	ret.x = vec->x + vec2->x;
	ret.y = vec->y + vec2->y;
	ret.z = vec->z + vec2->z;

	return (ret);
}

t_vec3	vec_plus_(t_vec3 *vec, double x, double y, double z)
{
	t_vec3 ret;

	ret.x = vec->x + x;
	ret.y = vec->y + y;
	ret.z = vec->z + z;

	return (ret);
}

t_vec3	vec_minus(t_vec3 *vec, t_vec3 *vec2)
{
	t_vec3 ret;

	ret.y = vec->y - vec2->y;
	ret.x = vec->x - vec2->x;
	ret.z = vec->z - vec2->z;

	return (ret);
}

t_vec3	vec_minus_(t_vec3 *vec, double x, double y, double z)
{
	t_vec3 ret;

	ret.x = vec->x - x;
	ret.y = vec->y - y;
	ret.z = vec->z - z;

	return (ret);
}
