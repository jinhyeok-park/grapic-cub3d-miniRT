/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:53:17 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 17:02:10 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

struct s_vec3 {
	double x;
	double y;
	double z;
};

t_vec3		vector3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double x, double y, double z);

void		setVec(t_vec3 *vec, double x, double y, double z);
double		getVecSize(t_vec3 *vec);
double		getVecLen(t_vec3 *vec);
t_vec3      vec_plus(t_vec3 *vec, t_vec3 *vec2);
t_vec3      vec_plus_(t_vec3 *vec, double x, double y, double z);
t_vec3      vec_minus(t_vec3 *vec, t_vec3 *vec2);
t_vec3      vec_minus_(t_vec3 *vec, double x, double y, double z);
t_vec3      vec_multi_scala(t_vec3 *vec, double value);
t_vec3		vec_multi_component(t_vec3 *vec, t_vec3 *vec2);
t_vec3      vec_divide_scala(t_vec3 *vec, double value);
t_vec3		vec_min(t_vec3 *vec1, t_vec3 *vec2);
t_vec3		vec_unit(t_vec3 *vec);
t_vec3		vec_cross(t_vec3 *vec, t_vec3 *vec2);
double		vec_dot(t_vec3 *vec, t_vec3 *vec2);
t_point3	point_move_minus(t_point3 *point, t_vec3 *vec);
t_point3	point_move_plus(t_point3 *point, t_vec3 *vec);
t_vec3		vec3_bypoint(t_point3 *point, t_point3 *point2);

#endif