/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:45:04 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 14:13:21 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "record.h"

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = 0.00001;
	record.tmax = INFINITY;
	record.t = INFINITY;
	return (record);
}
