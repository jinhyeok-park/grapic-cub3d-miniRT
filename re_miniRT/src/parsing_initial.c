/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_initial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:55:21 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/06 01:17:41 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_cylinder_properties(t_cylinder *cylinder, char **tokens)
{
	cylinder->center = get_vec(tokens[1]);
	cylinder->normal = get_vec(tokens[2]);
	check_normal_vector(cylinder->normal);
	cylinder->radius = ft_atod(tokens[3]) / 2;
	if (cylinder->radius <= 0)
		ft_error("invalid cylinder diameter");
	cylinder->height = ft_atod(tokens[4]);
	if (cylinder->height <= 0)
		ft_error("invalid cylinder height");
	cylinder->color = get_color(tokens[5]);
}

void	malloc_object(t_input *input_data)
{
	input_data->light = (t_light *)malloc(sizeof(t_light) * input_data->num_li);
	input_data->sphere = (t_sphere *)malloc(sizeof(t_sphere) \
											* input_data->num_sp);
	input_data->plane = (t_plane *)malloc(sizeof(t_plane) * input_data->num_pl);
	input_data->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder) * \
											input_data->num_cy);
}

void	initialize_input_data(t_input *input_data)
{
	input_data->num_amb = 0;
	input_data->num_cam = 0;
	input_data->num_sp = 0;
	input_data->num_pl = 0;
	input_data->num_cy = 0;
	input_data->num_li = 0;
}

void	parse_cylinder(t_input *src, char **tokens)
{
	static int	i = 0;

	validate_tokens(tokens);
	set_cylinder_properties(&src->cylinder[i], tokens);
	i++;
}
