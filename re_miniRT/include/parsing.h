/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:18:29 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/05 15:04:12 by minjcho          ###   ########.fr       */
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
	t_light		*light;	
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	int			num_amb;
	int			num_cam;
	int			num_sp;
	int			num_pl;
	int			num_cy;
	int			num_li;
	int			total_object;
}	t_input;

int			check_file(int ac, char **av);
void		free_split(char **s);
void		ft_error(char *str);
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(const char *str);
t_color3	get_color(char *s);
t_vec3		get_vec(char *s);
void		parse_ambient(t_input *src, char **tocken);
void		parse_camera(t_input *src, char **tockens);
void		parse_light(t_input *src, char **tockens);
void		parse_sphere(t_input *src, char **tockens);
t_vec3		get_vec_plane(char *s);
void		parse_plane(t_input *src, char **tockens);
void		validate_tokens(char **tokens);
void		check_normal_vector(t_vec3 normal);
void		set_cylinder_properties(t_cylinder *cylinder, char **tokens);
void		parse_cylinder(t_input *src, char **tokens);
void		parse_line(char *line, char **tmp, t_input *input_data);
void		count_object(char *line, t_input *input_data);
void		malloc_object(t_input *input_data);
void		initialize_input_data(t_input *input_data);
void		process_file(int fd, t_input *input_data);
void		parse_file(int fd, t_input *input_data);
void		parsing(int ac, char **av, t_input *input_data);

#endif