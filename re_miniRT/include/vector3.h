/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:36 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 15:33:47 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
void		vset(t_vec3 *vec, double x, double y, double z);
double		vlength2(t_vec3 vec);
double		vlength(t_vec3 vec);
t_vec3		vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		vplus_(t_vec3 vec, double x, double y, double z);
t_vec3		vminus(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus_(t_vec3 vec, double x, double y, double z);
t_vec3		vmult(t_vec3 vec, double t);
t_vec3		vmult_(t_vec3 vec, t_vec3 vec2);
t_vec3		vdivide(t_vec3 vec, double t);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);
t_vec3		reflect(t_vec3 v, t_vec3 n);

#endif