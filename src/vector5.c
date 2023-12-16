/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:50:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/16 02:05:47 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_point3	point_move_plus(t_point3 *point, t_vec3 *vec)
{
	t_point3 ret;

	ret.x = point->x + vec->x;
	ret.y = point->y + vec->y;
	ret.z = point->z + vec->z;
	return (ret);
}

t_vec3  vec3_bypoint(t_point3 *point, t_point3 *point2)
{
    t_vec3  ret;

    ret.x = point->x - point2->x;
    ret.y = point->y - point2->y;
    ret.z = point->z - point2->z;
    return (ret);
}

t_vec3          reflect(t_vec3 *v, t_vec3 *n)
{
    //v - 2 * dot(v, n) * n;
    double  temp;
    t_vec3  tem;

    temp = vec_dot(v, n);
    tem = vec_multi_scala(n, temp * 2);
    tem = vec_minus(v, &tem);
    //return (vminus(v, vmult(n, vdot(v, n) * 2)));
    return (tem);
}