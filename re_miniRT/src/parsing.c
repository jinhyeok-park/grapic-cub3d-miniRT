/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:25:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/02 02:45:58 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	t_color3	cord;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
		ft_err("invalid color!");
	cord = (t_color3){ft_atoi(params[0]), ft_atoi(params[1]), ft_atoi(params[2])};
	if (cord.r > 255 || cord.g > 255 || cord.b > 255)
		ft_err("invalid color");
	if (cord.r < 0 || cord.g < 0 || cord.b < 0)
		ft_err("invalid color");
	free_split(params);
	return (cord);
}

t_vec3	get_vec(char *s)
{
	char	**params;
	t_vec3	cord;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
		ft_err("invalid coordinates");
	cord = vec3(ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2]));
	free_split(params);
	return (cord);
}

void	parse_ambient(t_input *src, char **tocken)
{
	if (!tocken || !tocken[1] || !tocken[2] || tocken[3])
		ft_err("invalid ambiant!");
	src->amb.ratio = ft_atod(tocken[1]);
	if (src->amb.ratio < 0 || src->amb.ratio > 1)
		ft_err("enter ambient lighting ratio in range [0.0,1.0]");
	src->amb.color = get_color(tocken[2]);
}

void	parse_camera(t_input *src, char **tockens)
{
	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_err("invalid camera !");
	src->cam.cen = get_vec(tockens[1]);
	src->cam.dir = get_vec(tockens[2]);
	if (src->cam.dir.x > 1 || src->cam.dir.y > 1 || src->cam.dir.z > 1)
		ft_err("invalid orientation camera");
	if (src->cam.dir.x < -1 || src->cam.dir.y < -1 || src->cam.dir.z < -1)
		ft_err("invalid orientation camera");
	if (src->cam.dir.x == 0 && src->cam.dir.y == 0 && src->cam.dir.z == 0)
		ft_err("invalid orientation camera");
	src->cam.fov = ft_atod(tockens[3]);
	if (src->cam.fov < 0 || src->cam.fov > 180)
		ft_err("FOV  in range [0,180]");
}

void	parse_light(t_input *src, char **tockens)
{
	static int	i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || tockens[3])
		ft_err("invalid light !");
	src->light[i].src = get_vec(tockens[1]);
	src->light[i].ratio = ft_atod(tockens[2]);
	if (src->light[i].src < 0 || src->light[i].ratio > 1)
		ft_err("enter the light brightness ratio in range [0.0,1.0]");
	i++;
}

void	parse_sphere(t_input *src, char **tockens)
{
	static int	i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_err("invalid sphere");
	src->sphere[i].cen = get_vec(tockens[1]);
	src->sphere[i].radius = ft_atod(tockens[2]);
	if (sphere[i].radius <= 0)
		ft_err("invalid diameter sphere");
	src->sphere[i].color = get_color(tockens[3]);
	i++;
}

void	parse_plane(t_input *src, char **tockens)
{
	static int	i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_err("invalid plane");
	src->plane[i].cen = get_vec(tockens[1]);
	src->plane[i].norm = get_vec(tockens[2]);
	if (src->plane[i].norm.x > 1 || src->plane[i].norm.y > 1 || src->plane[i].norm.z > 1)
		ft_err("invalid plane normal");
	if (src->plane[i].norm.x < -1 || src->plane[i].norm.y < -1 || src->plane[i].norm.z < -1)
		ft_err("invalid plane normal");
	if (src->plane[i].norm.x == 0 && src->plane[i].norm.y == 0 && src->plane[i].norm.z == 0)
		ft_err("invalid plane normal");
	src->plane[i].color = get_color(tockens[3]);
	i++;
}

void	parse_cylinder(t_input *src, char **tockens)
{
	static int i = 0;

	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || !tockens[4] || !tockens[5] || tockens[6])
		ft_err("invalid cylinder");
	src->cylinder[i].cen = get_vec(tockens[1]);
	src->cylinder[i].norm = get_vec(tockens[2]);
	if (src->cylinder[i].norm.x > 1 || src->cylinder[i].norm.y > 1 || src->cylinder[i].norm.z > 1)
		ft_err("invalid cylinder normal");
	if (src->cylinder[i].norm.x < -1 || src->cylinder[i].norm.y < -1 || src->cylinder[i].norm.z < -1)
		ft_err("invalid cylinder normal");
	if (src->cylinder[i].norm.x == 0 && src->cylinder[i].norm.y == 0 && src->cylinder[i].norm.z == 0)
		ft_err("invalid cylinder normal");
	src->cylinder[i].radius = ft_atod(tockens[3]);
	if (src->cylinder[i].radius <= 0)
		ft_err("invalid cylinder diameter");
	src->cylinder[i].height = ft_atod(tockens[4]);
	if (src->cylinder[i].height <= 0)
		ft_err("invalid cylinder height");
	src->cylinder[i].color = get_color(tockens[5]);
	i++;
}

void	parse_line(char *line, char **tmp, t_input *input_data)
{
	if (ft_strcmp(line, "A") == 0)
		parse_ambient(tmp, input_data);
	else if (ft_strcmp(line, "C") == 0)
		parse_camera(tmp, input_data);
	else if (ft_strcmp(line, "L") == 0)
		parse_light(tmp, input_data);
	else if (ft_strcmp(line, "sp") == 0)
		parse_sphere(tmp, input_data);
	else if (ft_strcmp(line, "pl") == 0)
		parse_plane(tmp, input_data);
	else if (ft_strcmp(line, "cy") == 0)
		parse_cylinder(tmp, input_data);
}

void    parsing(int ac,char ** av, t_input *input_data)
{
	int	tmp_fd;
	int	fd;
	int	a;
	int	c;
	int	l;
	int	sp;
	int	pl;
	int	cy;

	a = 0;
	c = 0;
	l = 0;
	sp = 0;
	pl = 0;
	cy = 0;
	if (check_file(ac, av))
		ft_error("Error : Wrong file type, filename.rt\n");
	tmp_fd = open(av[1], O_RDONLY);
	while (1)
	{
		char **tmp = ft_split(get_next_line(tmp_fd), ' ');
		if (!tmp)
			break ;
		if (ft_strcmp(*tmp, "A") == 0)
			a++;
		else if (ft_strcmp(*tmp, "C") == 0)
			c++;
		else if (ft_strcmp(*tmp, "L") == 0)
			l++;
		else if (ft_strcmp(*tmp, "sp") == 0)
			sp++;
		else if (ft_strcmp(*tmp, "pl") == 0)
			pl++;
		else if (ft_strcmp(*tmp, "cy") == 0)
			cy++;
		else
			ft_error("Error : Wrong identifier\n");
		free_split(tmp);
	}
	close(tmp_fd);
	// 동적할당
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		char **tmp = ft_split(get_next_line(fd), ' ');
		if (!tmp)
			break ;
		if (*tmp)
			parse_line(*tmp, tmp, input_data);
		free_split(tmp);
	}
	close(fd);
}
