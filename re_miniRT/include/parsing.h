/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:18:29 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/04 15:55:52 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "vector3.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "color3.h"
# include "light.h"
# include "sphere.h"
# include "plane.h"
# include "cylinder.h"
# include "camera.h"

typedef struct s_input
{
	t_color3	ambient;
	t_camera	cam;
	t_light		light[99];	
	t_sphere	sphere[99];
	t_plane		plane[99];
	t_cylinder	cylinder[99];
	int			num_sp;
	int			num_pl;
	int			num_cy;
	int			num_li;
	int			total_object;
}	t_input;

void	parsing(int ac, char **av, t_input *input_data);

#endif