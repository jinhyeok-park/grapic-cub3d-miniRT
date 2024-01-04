/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:25:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/04 15:57:07 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_file(int ac, char **av)
{
	int	i;
	int	fd;

	fd = 0;
	if (ac != 2)
		return (1);
	if (!av[1])
		return (1);
	i = ft_strlen(av[1]);
	if (i < 4)
		return (1);
	if (av[1][i - 1] == 't' || av[1][i - 2] == 'r' || av[1][i - 3] == '.')
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (1);
		close(fd);
	}
	else
		return (1);
	return (0);
}

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1 && s2 && s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

double	ft_atod(const char *str)
{
	double	nb;
	int		signe;
	int		i;
	int		aux;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe = -1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] != '.')
		return ((double)nb * signe);
	aux = 10;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		nb = nb + (double)(str[i] - '0') / aux;
		aux = aux * 10;
	}
	return ((double)nb * signe);
}

t_color3	get_color(char *s)
{
	char	**params;
	t_color3	color;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
		ft_error("invalid color");
	color = color3(ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2]));
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

void	parse_ambient(t_input *src, char **tocken)
{
	if (!tocken || !tocken[1] || !tocken[2] || tocken[3])
	{
		ft_error("invalid ambiant!");
	}
	double ratio = ft_atod(tocken[1]);
	if (ratio < 0 || ratio > 1)
		ft_error("enter ambient lighting ratio in range [0.0,1.0]");
	t_color3 color = get_color(tocken[2]);
	src->ambient = cmult(color, ratio);
}

void	parse_camera(t_input *src, char **tockens)
{
	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_error("invalid camera !");
	src->cam.orig = get_vec(tockens[1]);
	src->cam.dir = get_vec(tockens[2]);
	if (src->cam.dir.x > 1 || src->cam.dir.y > 1 || src->cam.dir.z > 1)
		ft_error("invalid orientation camera");
	if (src->cam.dir.x < -1 || src->cam.dir.y < -1 || src->cam.dir.z < -1)
		ft_error("invalid orientation camera");
	if (src->cam.dir.x == 0 && src->cam.dir.y == 0 && src->cam.dir.z == 0)
		ft_error("invalid orientation camera");
	src->cam.fov = ft_atod(tockens[3]);
	if (src->cam.fov < 0 || src->cam.fov > 180)
		ft_error("FOV  in range [0,180]");
}

void	parse_light(t_input *src, char **tockens)
{
	static int	i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || tockens[3])
		ft_error("invalid light !");
	src->light[i].origin = get_vec(tockens[1]);
	src->light[i].bright_ratio = ft_atod(tockens[2]);
	if (src->light[i].bright_ratio < 0 || src->light[i].bright_ratio > 1)
		ft_error("enter the light brightness ratio in range [0.0,1.0]");
	i++;
	src->num_li = i;
}

void	parse_sphere(t_input *src, char **tockens)
{
	static int	i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_error("invalid sphere");
	src->sphere[i].center = get_vec(tockens[1]);
	src->sphere[i].radius = ft_atod(tockens[2]);
	src->sphere[i].radius2 = pow(src->sphere[i].radius, 2);
	if (src->sphere[i].radius <= 0)
		ft_error("invalid diameter sphere");
	src->sphere[i].color = get_color(tockens[3]);
	i++;
	src->num_sp = i;
}

void	parse_plane(t_input *src, char **tockens)
{
	static int	i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_error("invalid plane");
	src->plane[i].point = get_vec(tockens[1]);
	src->plane[i].normal = get_vec(tockens[2]);
	if (src->plane[i].normal.x > 1 || src->plane[i].normal.y > 1 || src->plane[i].normal.z > 1)
		ft_error("invalid plane normal");
	if (src->plane[i].normal.x < -1 || src->plane[i].normal.y < -1 || src->plane[i].normal.z < -1)
		ft_error("invalid plane normal");
	if (src->plane[i].normal.x == 0 && src->plane[i].normal.y == 0 && src->plane[i].normal.z == 0)
		ft_error("invalid plane normal");
	src->plane[i].color = get_color(tockens[3]);
	i++;
	src->num_pl = i;
}

void	parse_cylinder(t_input *src, char **tockens)
{
	static int i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || !tockens[4] || !tockens[5] || tockens[6])
		ft_error("invalid cylinder");
	src->cylinder[i].center = get_vec(tockens[1]);
	src->cylinder[i].normal = get_vec(tockens[2]);
	if (src->cylinder[i].normal.x > 1 || src->cylinder[i].normal.y > 1 || src->cylinder[i].normal.z > 1)
		ft_error("invalid cylinder normal");
	if (src->cylinder[i].normal.x < -1 || src->cylinder[i].normal.y < -1 || src->cylinder[i].normal.z < -1)
		ft_error("invalid cylinder normal");
	if (src->cylinder[i].normal.x == 0 && src->cylinder[i].normal.y == 0 && src->cylinder[i].normal.z == 0)
		ft_error("invalid cylinder normal");
	src->cylinder[i].radius = ft_atod(tockens[3]);
	if (src->cylinder[i].radius <= 0)
		ft_error("invalid cylinder diameter");
	src->cylinder[i].height = ft_atod(tockens[4]);
	if (src->cylinder[i].height <= 0)
		ft_error("invalid cylinder height");
	src->cylinder[i].color = get_color(tockens[5]);
	i++;
	src->num_cy = i;
}

void	parse_line(char *line, char **tmp, t_input *input_data)
{
	if (ft_strcmp(line, "A") == 0)
	{	
		parse_ambient(input_data, tmp);
	}
	else if (ft_strcmp(line, "C") == 0)
	{
		parse_camera(input_data, tmp);
	}
	else if (ft_strcmp(line, "L") == 0)
	{	
		parse_light(input_data, tmp);
	}
	else if (ft_strcmp(line, "sp") == 0)
	{
		parse_sphere(input_data, tmp);
	}
	else if (ft_strcmp(line, "pl") == 0)
	{
		parse_plane(input_data, tmp);
	}
	else if (ft_strcmp(line, "cy") == 0)
	{
		parse_cylinder(input_data, tmp);
	}
	else if (ft_strcmp(line, "\n") == 0)
	{
		return ;
	}
	else
	{
		printf("Error : Wrong identifier [%s]", line);
		ft_error("\n");
	}
}

void	parsing(int ac, char **av, t_input *input_data)
{
    int fd;
	input_data->num_sp = 0;
	input_data->num_pl = 0;
	input_data->num_cy = 0;
	input_data->num_li = 0;

    if (check_file(ac, av))
        ft_error("Error: Wrong file type, filename.rt");

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        ft_error("Error: Cannot open file");

    char *str;
    while ((str = get_next_line(fd)) != NULL)
	{
        char **tmp = ft_split(str, ' ');
        if (!tmp) {
            free(str);
            break;
        }
        if (*tmp)
            parse_line(*tmp, tmp, input_data);
        free_split(tmp);
        free(str);
    }
    close(fd);
	input_data->total_object = input_data->num_cy + input_data->num_li + input_data->num_pl + input_data->num_sp;
}
