/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:21:03 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/05 22:21:44 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# define OBJECTSIZE 100
# define CIRCLE 1
# define LIGHT 2
# define PLANE 3
# define CYLINDER 4
# include <stdlib.h>
# include <stdio.h>
# include "color3.h"

typedef struct s_object
{
	int			type;
	int			size;
	int			real_size;
	void		*element;
	t_color3	albedo;
}	t_object;

t_object	**create_object(int size);
t_object	*object(int type, void *ele, t_color3 albedo);
void		object_add(t_object **vector, void *ele, int type, t_color3 albedo);

#endif