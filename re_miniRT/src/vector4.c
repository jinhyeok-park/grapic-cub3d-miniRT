/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:55:30 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/19 14:55:51 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vec3  vmin(t_vec3 vec1, t_vec3 vec2)
{
    if (vec1.x > vec2.x)
        vec1.x = vec2.x;
    if (vec1.y > vec2.y)
        vec1.y = vec2.y;
    if (vec1.z > vec2.z)
        vec1.z = vec2.z;
    return (vec1);
}