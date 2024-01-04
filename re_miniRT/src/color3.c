/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:38:19 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 18:44:30 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color3.h"

t_color3	color3(double r, double g, double b)
{
	t_color3	ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	return (ret);
}

t_color3	cplus(t_color3 vec, t_color3 vec2)
{
	vec.r += vec2.r;
	vec.g += vec2.g;
	vec.b += vec2.b;
	return (vec);
}

t_color3	cmult(t_color3 vec, double t)
{
	vec.r *= t;
	vec.g *= t;
	vec.b *= t;
	return (vec);
}

t_color3	cmult_(t_color3 vec, t_color3 col)
{
	vec.r *= col.r;
	vec.g *= col.g;
	vec.b *= col.b;
	return (vec);
}

t_color3	cmin(t_color3 vec1, t_color3 vec2)
{
	if (vec1.r > vec2.r)
		vec1.r = vec2.r;
	if (vec1.g > vec2.g)
		vec1.g = vec2.g;
	if (vec1.b > vec2.b)
		vec1.b = vec2.b;
	return (vec1);
}
