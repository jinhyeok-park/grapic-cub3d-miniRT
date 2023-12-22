/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:21:03 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/22 14:28:47 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

#define OBJECTSIZE 100
#define CIRCLE 1
#define LIGHT 2
#define PLANE 3
#include <stdlib.h>
#include "color3.h"

typedef struct s_object
{
    int         type;
    int         size;
    void        *element;
    t_color3    albedo;
} t_object ;

t_object **create_object(void);
t_object    *object(int type, void* ele, t_color3 albedo);
void    object_add(t_object **vector, void *ele, int type, t_color3 albedo);
// void    object_add(t_object **vector, void *ele, int type);

#endif