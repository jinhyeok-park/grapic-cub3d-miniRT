/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:16:26 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 15:18:52 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"
#include <stdio.h>
#include "light.h"

t_object    **vector_create(void)
{
    t_object **ret;
    int     i;

    ret = (t_object **)malloc(sizeof(t_object *) * VECTORSIZE);
    i = 0;
    while (i < VECTORSIZE)
    {
        ret[i] = NULL;
        i++;
    }
    return (ret);
}

t_object    *object(int type, void* ele,t_color3 albedo)
{
    t_object    *ret;

    ret = malloc(sizeof(t_object));
    if (!ret)
        exit(1);
    if (type == CIRCLE)
        ret->type = CIRCLE;
    else if (type == LIGHT)
        ret->type = LIGHT;
    ret->size = 1;
    ret->element = ele;
    return (ret);
}

void    vector_push_back(t_object **vector, void *ele, int type)
{
    t_object *temp;

    if (!vector || !ele)
        return ;
    if (*vector && (*vector)->size >= 100)
    {
        //realloc
    }
    temp = (t_object *)malloc(sizeof(t_object));
    if (type == CIRCLE)
        temp->type = CIRCLE;
    else if (type == LIGHT)
        temp->type = LIGHT;
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