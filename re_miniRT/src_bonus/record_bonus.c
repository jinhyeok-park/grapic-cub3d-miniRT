/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:45:04 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 01:17:36 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = 0.00001;
	record.tmax = INFINITY;
	record.t = INFINITY;
	return (record);
}
