/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:55:30 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/20 14:54:43 by jinhyeok         ###   ########.fr       */
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

t_vec3          reflect(t_vec3 v, t_vec3 n)
{
    //v - 2 * dot(v, n) * n;
    // double  temp;
    // t_vec3  tem;


    return (vminus(v, vmult(n, vdot(v,n) * 2)));
    // temp = vec_dot(v, n);
    // tem = vec_multi_scala(n, temp * 2);
    // tem = vec_minus(v, &tem);
    // //return (vminus(v, vmult(n, vdot(v, n) * 2)));
    // return (tem);
}