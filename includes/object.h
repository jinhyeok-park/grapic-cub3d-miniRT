/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:10:25 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 14:42:42 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

#define CIRCLE 1
#define VECTORSIZE 100

#include <stdlib.h>
#include "vector.h"

typedef struct s_object
{
	int			type;
	int			size;
	void		*element;
	t_color3	albedo;
} t_object;

t_object	*object(int type, void *elel, t_color3 albedo);
t_object    **vector_create(void);
void        vector_push_back(t_object **vector, void *ele, int type);

#endif