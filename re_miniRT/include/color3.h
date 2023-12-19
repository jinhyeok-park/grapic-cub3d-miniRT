/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:36:34 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/19 15:15:29 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR3_H
#define COLOR3_H

typedef struct s_color3
{
    double  r;
    double  g;
    double  b;
} t_color3;

t_color3    color3(double r, double g, double b);
t_color3      cplus(t_color3 vec, t_color3 vec2);
t_color3      cmult(t_color3 vec, double t);

#endif