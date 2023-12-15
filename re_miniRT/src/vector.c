/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:52:58 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 16:57:31 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vector3(double x, double y, double z)
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

t_point3	color3(double x, double y, double z)
{
	t_color3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
