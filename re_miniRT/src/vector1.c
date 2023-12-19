/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:50:24 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/19 14:53:21 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vec3      vec3(double x, double y, double z)
{
    t_vec3 vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}

t_point3    point3(double x, double y, double z)
{
    t_point3 point;

    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

void        vset(t_vec3 *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

double      vlength2(t_vec3 vec)
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double      vlength(t_vec3 vec)
{
    return (sqrt(vlength2(vec)));
}
