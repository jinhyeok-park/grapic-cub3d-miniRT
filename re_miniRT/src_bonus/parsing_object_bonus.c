/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:54:17 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/06 01:17:26 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	parse_ambient(t_input *src, char **tocken)
{
	double		ratio;
	t_color3	color;

	if (ft_strcmp(tocken[3], "\n") == 0)
		ft_error("No space after ambiant");
	if (!tocken || !tocken[1] || !tocken[2] || tocken[3])
		ft_error("invalid ambiant!");
	ratio = ft_atod(tocken[1]);
	if (ratio < 0 || ratio > 1)
		ft_error("enter ambient lighting ratio in range [0.0,1.0]");
	color = get_color(tocken[2]);
	src->ambient = cmult(color, ratio);
}

void	parse_camera(t_input *src, char **tockens)
{
	if (ft_strcmp(tockens[4], "\n") == 0)
		ft_error("No space after camera");
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
	if (src->cam.dir.x == 0 && src->cam.dir.z == 0)
		ft_error("invalid orientation camera");
}

void	parse_light(t_input *src, char **tockens)
{
	static int	i = 0;

	if (ft_strcmp(tockens[3], "\n") == 0)
		ft_error("No space after light");
	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_error("invalid light !");
	src->light[i].origin = get_vec(tockens[1]);
	src->light[i].bright_ratio = ft_atod(tockens[2]);
	if (src->light[i].bright_ratio < 0 || src->light[i].bright_ratio > 1)
		ft_error("enter the light brightness ratio in range [0.0,1.0]");
	src->light[i].light_color = get_color(tockens[3]);
	i++;
}

void	parse_sphere(t_input *src, char **tockens)
{
	static int	i = 0;

	if (ft_strcmp(tockens[4], "\n") == 0)
		ft_error("No space after sphere");
	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_error("invalid sphere");
	src->sphere[i].center = get_vec(tockens[1]);
	src->sphere[i].radius = ft_atod(tockens[2]) / 2;
	src->sphere[i].radius2 = pow(src->sphere[i].radius, 2);
	if (src->sphere[i].radius <= 0)
		ft_error("invalid diameter sphere");
	src->sphere[i].color = get_color(tockens[3]);
	i++;
}

void	parse_plane(t_input *src, char **tockens)
{
	static int	i = 0;

	if (ft_strcmp(tockens[4], "\n") == 0)
		ft_error("No space after plane");
	if (!tockens || !tockens[1] || !tockens[2] || !tockens[3] || tockens[4])
		ft_error("invalid plane");
	src->plane[i].point = get_vec_plane(tockens[1]);
	src->plane[i].normal = get_vec(tockens[2]);
	if (src->plane[i].normal.x > 1 || src->plane[i].normal.y > 1 \
		|| src->plane[i].normal.z > 1)
		ft_error("invalid plane normal");
	if (src->plane[i].normal.x < -1 || src->plane[i].normal.y < -1 \
		|| src->plane[i].normal.z < -1)
		ft_error("invalid plane normal");
	if (src->plane[i].normal.x == 0 && src->plane[i].normal.y == 0 \
		&& src->plane[i].normal.z == 0)
		ft_error("invalid plane normal");
	src->plane[i].color = get_color(tockens[3]);
	i++;
}
