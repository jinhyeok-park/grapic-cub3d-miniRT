/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:04:07 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/15 14:58:03 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
void		setVec(t_vec3 *vec, double x, double y, double z);
double		getVecSize(t_vec3 *vec);
double		getVecLen(t_vec3 *vec);

#endif