/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:09:00 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 14:43:52 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"

#define LIGHT -1

typedef struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}t_light;

#endif