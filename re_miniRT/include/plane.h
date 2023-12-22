/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:58:28 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/22 14:14:05 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
#define PLANE_H

#include "vector3.h"
#include "commontype.h"
#include "ray.h"
#include "record.h"



typedef struct s_plane
{
    t_point3    point;
    t_vec3      normal;
} t_plane;

t_bool  hit_plane(t_plane *p, t_ray *ray, t_hit_record *rec);
t_plane *plane(t_point3 point, t_vec3 normal);

#endif