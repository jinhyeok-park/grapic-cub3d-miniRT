/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:16:26 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/29 06:54:03 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object    **vector_create(void)
{
    t_object **ret;

    ret = (t_object **)malloc(sizeof(t_object *) * VECTORSIZE);
    return (ret);
}

void    vector_push_back(t_object **vector, void *ele, int type)
{
    t_object *temp;

    if (!vector || !ele)
        return ;
    if ((*vector)->size >= 100)
    {
        //realloc
    }
    temp = (t_object *)malloc(sizeof(t_object));
    if (type == CIRCLE)
        temp->type = CIRCLE;
    temp->element = ele;
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