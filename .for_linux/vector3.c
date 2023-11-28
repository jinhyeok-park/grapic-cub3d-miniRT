/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:36 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:25 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3  vec_multi_scala(t_vec3 *vec, double val)
{
    t_vec3 ret;

    ret.x = vec->x * val;
    ret.y = vec->y * val;
    ret.z = vec->z * val;
    return (ret);
}

t_vec3  vec_multi_component(t_vec3 *vec, t_vec3 *vec2)
{
    t_vec3 ret;

    ret.x = vec->x * vec2->x;
    ret.y = vec->y * vec2->y;
    ret.z = vec->z * vec2->z;
    return (ret);
}

t_vec3  vec_divide_scala(t_vec3 *vec, double val)
{
    t_vec3 ret;

    ret.x = vec->x / val;
    ret.y = vec->y / val;
    ret.z = vec->z / val;
    return (ret);
}
