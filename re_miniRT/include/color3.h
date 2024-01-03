/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:36:34 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 15:15:49 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR3_H
# define COLOR3_H

typedef struct s_color3
{
	double	r;
	double	g;
	double	b;
}	t_color3;

t_color3	color3(double r, double g, double b);
t_color3	cplus(t_color3 vec, t_color3 vec2);
t_color3	cmult(t_color3 vec, double t);
t_color3	cmult_(t_color3 vec, t_color3 col);
t_color3	cmin(t_color3 vec1, t_color3 vec2);

#endif
