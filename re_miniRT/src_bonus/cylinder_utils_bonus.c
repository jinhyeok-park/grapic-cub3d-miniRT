/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:16:49 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/06 00:55:55 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	set_face_normal_cylinder(t_ray *r, t_hit_record *rec, \
									t_vec3 outward_normal)
{
	rec->front_face = vdot(r->dir, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vmult(outward_normal, -1);
}

t_bool	check_cylinder_root(double root, double m, t_hit_record *rec, \
						t_cylinder *cy)
{
	if (m >= 0 && m <= cy->height && root >= rec->tmin && root <= rec->tmax)
		return (TRUE);
	else
		return (FALSE);
}

t_cylinder_calc	calculate_cylinder_params(t_cylinder *cy, t_ray *ray)
{
	t_cylinder_calc	calc;
	t_vec3			x;

	x = vminus(ray->orig, cy->center);
	calc.a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, cy->normal), 2);
	calc.b = 2 * (vdot(ray->dir, x) - vdot(ray->dir, cy->normal) * \
										vdot(x, cy->normal));
	calc.c = vdot(x, x) - pow(vdot(x, cy->normal), 2) - \
				(cy->radius * cy->radius);
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	return (calc);
}

void	update_cylinder_roots_and_m(t_cylinder_calc *calc, \
								t_cylinder *cy, t_ray *ray)
{
	t_vec3	x;

	x = vminus(ray->orig, cy->center);
	calc->sqrtd = sqrt(calc->discriminant);
	calc->root = (-calc->b - calc->sqrtd) / (2 * calc->a);
	calc->root1 = (-calc->b + calc->sqrtd) / (2 * calc->a);
	calc->m = vdot(ray->dir, vmult(cy->normal, calc->root)) + \
				vdot(x, cy->normal);
	calc->m1 = vdot(ray->dir, vmult(cy->normal, calc->root1)) + \
				vdot(x, cy->normal);
}
