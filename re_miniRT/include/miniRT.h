/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:26:23 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/05 22:22:42 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "commontype.h"
# include "mlx.h"
# include "color3.h"
# include "vector3.h"
# include "ray.h"
# include "pixel.h"
# include "sphere.h"
# include "camera.h"
# include "trace.h"
# include "object.h"
# include "scene.h"
# include "parsing.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
}	t_mlx;

int		close_window(int keycode);
int		key_hook(int keycode);
void	free_parsing(t_input *input_data);

#endif