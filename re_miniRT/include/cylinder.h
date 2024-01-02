/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:22:23 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/02 14:11:33 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "ray.h"
# include "object.h"

typedef struct s_cylinder
{
    t_point3 center; // center of the bottom base
    t_vec3 normal;
    double radius;
    double height;
} t_cylinder;

//t_cylinder *cylinder(t_point3 center, double radius, double height);
t_cylinder *cylinder(t_point3 center, double radius, double height, t_vec3 normal);
t_bool hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);

#endif