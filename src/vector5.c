/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:50:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/17 16:39:43 by jinhyeok         ###   ########.fr       */
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
