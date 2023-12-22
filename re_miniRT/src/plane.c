/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:03:54 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/22 15:30:51 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_plane *plane(t_point3 point, t_vec3 normal)
{
    t_plane *ret;

    ret = malloc(sizeof(t_plane));
    ret->point = point;
    ret->normal = normal;
    return (ret);
}

// t_bool  hit_plane(t_plane *p, t_ray *ray, t_hit_record *rec)
// {
    
// }