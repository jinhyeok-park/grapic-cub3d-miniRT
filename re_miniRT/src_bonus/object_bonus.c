/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:23:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 19:08:01 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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
