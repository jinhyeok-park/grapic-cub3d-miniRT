/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:23:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/05 22:22:39 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "commontype.h"

t_object	**create_object(int size)
{
	int			i;
	t_object	**ret;

	ret = (t_object **)malloc(sizeof(t_object *) * size);
	if (!ret)
	{
		printf("malloc error\n");
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}

t_object	*object(int type, void *ele, t_color3 albedo)
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

int	assign_type(int type)
{
	if (type == CIRCLE)
		return (CIRCLE);
	else if (type == LIGHT)
		return (LIGHT);
	else if (type == PLANE)
		return (PLANE);
	else if (type == CYLINDER)
		return (CYLINDER);
	else
		return (-1);
}

void	object_add(t_object **vector, void *ele, int type, t_color3 albedo)
{
	t_object	*temp;
	int			i;
	int			c_size;

	if (!vector || !ele)
		exit(1);
	temp = (t_object *)malloc(sizeof(t_object));
	if (!temp)
		exit(1);
	temp->type = assign_type(type);
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
