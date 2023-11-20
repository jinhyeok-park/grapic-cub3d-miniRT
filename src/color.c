/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:20:14 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/17 17:46:09 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color3    color3(double r, double g, double b)
{
	t_color3	ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	return (ret);
}

t_color3    color_plus(t_color3 *color, t_color3 *color2)
{
    t_color3    ret;
    
    ret.r = color->r + color2->r;
    ret.g = color->g + color2->g;
    ret.b = color->b + color2->b;
    return (ret);
}

t_color3    color_multi_scala(t_color3 *color, double val)
{
    t_color3    ret;
    
    ret.r = color->r * val;
    ret.g = color->g * val;
    ret.b = color->b * val;
    return (ret);
}