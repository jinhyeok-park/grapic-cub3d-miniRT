/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:58:28 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 15:25:19 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vector3.h"
# include "commontype.h"
# include "ray.h"
# include "record.h"

typedef struct s_plane
{
	t_point3	point;
	t_vec3		normal;
	t_color3	color;
}	t_plane;

t_bool	hit_plane(t_plane *p, t_ray *ray, t_hit_record *rec);
t_plane	*plane(t_point3 point, t_vec3 normal);

#endif