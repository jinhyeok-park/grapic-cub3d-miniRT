/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:52:36 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/06 01:17:44 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_color3	get_color(char *s)
{
	char		**params;
	t_color3	color;

	params = ft_split(s, ',');
	if (ft_strcmp(params[2], "\n") == 0)
		ft_error("invalid color");
	if (!params || !params[1] || !params[2] || params[3])
		ft_error("invalid color");
	color = color3(ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2]));
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 \
		|| color.b < 0 || color.b > 255)
		ft_error("invalid color");
	color = color3(ft_atod(params[0]) / 255, ft_atod(params[1]) / 255 \
	, ft_atod(params[2]) / 255);
	free_split(params);
	return (color);
}

t_vec3	get_vec(char *s)
{
	char	**params;
	t_vec3	cord;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
		ft_error("invalid coordinates");
	cord = vec3(ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2]));
	free_split(params);
	return (cord);
}

t_vec3	get_vec_plane(char *s)
{
	char	**params;
	t_vec3	cord;

	params = ft_split(s, ',');
	if (!params[2])
	{
		params[2] = ft_strdup("0");
		params[3] = NULL;
	}
	if (!params || !params[1] || !params[2] || params[3])
		ft_error("invalid coordinatesiiiii");
	cord = vec3(ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2]));
	free_split(params);
	return (cord);
}

void	validate_tokens(char **tokens)
{
	if (ft_strcmp(tokens[6], "\n") == 0)
		ft_error("No space after cylinder");
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || \
		!tokens[4] || !tokens[5] || tokens[6])
		ft_error("invalid cylinder");
}

void	check_normal_vector(t_vec3 normal)
{
	if (normal.x > 1 || normal.y > 1 || normal.z > 1 || \
		normal.x < -1 || normal.y < -1 || normal.z < -1 || \
		(normal.x == 0 && normal.y == 0 && normal.z == 0))
		ft_error("invalid cylinder normal");
}
