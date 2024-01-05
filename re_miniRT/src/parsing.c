/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:25:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 01:17:40 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_line(char *line, char **tmp, t_input *input_data)
{
	if (ft_strcmp(line, "A") == 0)
		parse_ambient(input_data, tmp);
	else if (ft_strcmp(line, "C") == 0)
		parse_camera(input_data, tmp);
	else if (ft_strcmp(line, "L") == 0)
		parse_light(input_data, tmp);
	else if (ft_strcmp(line, "sp") == 0)
		parse_sphere(input_data, tmp);
	else if (ft_strcmp(line, "pl") == 0)
		parse_plane(input_data, tmp);
	else if (ft_strcmp(line, "cy") == 0)
		parse_cylinder(input_data, tmp);
	else if (ft_strcmp(line, "\n") == 0)
		return ;
	else
	{
		ft_error("Error: Wrong identifier");
	}
}

void	count_object(char *line, t_input *input_data)
{
	if (input_data->num_amb >= 2 || input_data->num_cam >= 2)
		ft_error("Error: Too many ambient or camera");
	if (ft_strcmp(line, "A") == 0)
		input_data->num_amb++;
	else if (ft_strcmp(line, "C") == 0)
		input_data->num_cam++;
	else if (ft_strcmp(line, "L") == 0)
		input_data->num_li++;
	else if (ft_strcmp(line, "sp") == 0)
		input_data->num_sp++;
	else if (ft_strcmp(line, "pl") == 0)
		input_data->num_pl++;
	else if (ft_strcmp(line, "cy") == 0)
		input_data->num_cy++;
	else if (ft_strcmp(line, "\n") == 0)
		return ;
}

void	process_file(int fd, t_input *input_data)
{
	char	*str;
	char	**tmp;

	str = get_next_line(fd);
	while (str != NULL)
	{
		tmp = ft_split(str, ' ');
		if (!tmp)
			ft_error("Error: Cannot split");
		if (*tmp)
			count_object(*tmp, input_data);
		free_split(tmp);
		free(str);
		str = get_next_line(fd);
	}
	if (input_data->num_amb == 0 || input_data->num_cam == 0 \
		|| input_data->num_li == 0)
		ft_error("Error: Missing object");
	if (input_data->num_cy == 0 && input_data->num_pl == 0 \
		&& input_data->num_sp == 0)
		ft_error("Error: Object is not exist");
}

void	parse_file(int fd, t_input *input_data)
{
	char	*str;
	char	**tmp;

	str = get_next_line(fd);
	while (str != NULL)
	{
		tmp = ft_split(str, ' ');
		if (!tmp)
			ft_error("Error: Cannot split");
		if (*tmp)
			parse_line(*tmp, tmp, input_data);
		free_split(tmp);
		free(str);
		str = get_next_line(fd);
	}
}

void	parsing(int ac, char **av, t_input *input_data)
{
	int	fd;

	initialize_input_data(input_data);
	if (check_file(ac, av))
		ft_error("Error: Wrong file type, filename.rt");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error: Cannot open file");
	process_file(fd, input_data);
	input_data->total_object = input_data->num_cy + input_data->num_pl \
								+ input_data->num_sp;
	close(fd);
	malloc_object(input_data);
	fd = open(av[1], O_RDONLY);
	parse_file(fd, input_data);
	close(fd);
}
