/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:13:09 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 13:22:20 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdlib.h>

t_light *light_point(t_point3 origin, t_color3 color, double bright_ratio)
{
    t_light *ret;

    ret = malloc(sizeof(t_light));
    ret->origin = origin;
    ret->light_color = color;
    ret->bright_ratio = bright_ratio;
    return (ret);
}