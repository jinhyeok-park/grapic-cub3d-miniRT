/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:01:27 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/17 20:38:37 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "vector.h"

typedef struct s_input 
{
    //ambient
    //camera
    //lgiht
    //sphere
    t_sphere **sp;
} t_input;

typedef struct s_sphere
{
    t_point3    center;
    double      diameter;
    t_color3    color;
} t_sphere;



void    parsing(int ac, char **av, t_input *data);

#endif