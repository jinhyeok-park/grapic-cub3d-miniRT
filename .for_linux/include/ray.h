/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:39:58 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/15 16:43:35 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "vector.h"

typedef struct s_ray t_ray;

struct s_ray
{
    t_point3    origin;
    t_vec3      direction;
};

#endif 