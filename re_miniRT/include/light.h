/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:12:47 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/05 15:04:20 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color3.h"
# include "vector3.h"

typedef struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}	t_light;

t_light	*light_point(t_point3 light_origin, t_color3 light_color, \
					double bright_ratio);

#endif