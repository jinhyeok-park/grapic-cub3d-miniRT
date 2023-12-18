/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:01:27 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/18 16:11:51 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "vector.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

typedef struct s_isphere
{
    t_point3    center;
    double      diameter;
    t_color3    color;
} t_isphere;


typedef struct s_input 
{
    //ambient
    //camera
    //lgiht
    //sphere
    //cylinder
    //plane
    t_isphere **sp;
} t_input;

void    parsing(int ac,char ** av, t_input *input_data);


#endif