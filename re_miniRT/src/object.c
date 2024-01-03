/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:23:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 14:54:05 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "commontype.h"

t_object	**create_object(void)
{
	int			i;
	t_object	**ret;
	
	ret = (t_object **)malloc(sizeof(t_object *) * OBJECTSIZE);
	i = 0;
	while (i < OBJECTSIZE)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}

t_object	*object(int type, void* ele, t_color3 albedo)
{
	t_object	*ret;

	ret = malloc(sizeof(t_object));
	if (!ret)
		exit(1);
	if (type == CIRCLE)
		ret->type = CIRCLE;
	else if (type == LIGHT)
		ret->type = LIGHT;
	ret->size = 1;
	ret->element = ele;
	ret->albedo = albedo;
	return (ret);
}

void	object_add(t_object **vector, void *ele, int type, t_color3 albedo)
{
	t_object	*temp;
	int			i;
	int			c_size;

	if (!vector || !ele)
		return ;
	if (*vector && (*vector)->size >= (*vector)->real_size * OBJECTSIZE)
	{
		// (*vector)->real_size++;
		// t_object	**real;

		// c_size = (*vector)->real_size * OBJECTSIZE;
		// real = (t_object **)malloc(sizeof(t_object *) * c_size);
		// i = 0;
		// c_size = ((*vector)->real_size - 1) * OBJECTSIZE;
		// while (i < c_size)
		// {
			
		// }
	}
	temp = (t_object *)malloc(sizeof(t_object));
	if (!temp)
		exit(1);
	if (type == CIRCLE)
		temp->type = CIRCLE;
	else if (type == LIGHT)
		temp->type = LIGHT;
	else if (type == PLANE)
		temp->type = PLANE;
	else if (type == CYLINDER)
		temp->type = CYLINDER;
	else
		temp->type = -1;
	temp->element = ele;
	temp->real_size = 1;
	temp->albedo = albedo;
	if ((*vector))
	{
		vector[(*vector)->size] = temp;
		(*vector)->size++;
	}
	else
	{
		temp->size = 1;
		vector[0] = temp;
	}
}
