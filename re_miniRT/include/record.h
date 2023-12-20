/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:40:18 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/20 14:00:00 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_H
#define RECORD_H

#include "commontype.h"
#include "vector3.h"
#include "color3.h"

typedef struct s_hit_record t_hit_record;

struct s_hit_record
{
    t_point3    p;
    t_vec3      normal;
    double      tmin;
    double      tmax;
    double      t;
    t_bool      front_face;
    t_color3    albedo;
};

t_hit_record record_init(void);

#endif