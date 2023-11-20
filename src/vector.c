/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:26:03 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/17 17:20:02 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}



void	setVec(t_vec3 *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

double	getVecSize(t_vec3 *vec)
{
    return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}