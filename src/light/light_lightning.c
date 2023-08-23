/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_lightning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:10:26 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 14:31:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "light.h"

static bool	initialize_phong_params(\
	t_phong_params *p, t_computations *comps, t_light *light);
static void	compute_phong_model(\
	t_phong_params *p, t_computations *comps, t_light *light);

t_color	light_lightning(t_computations *comps, t_light *light)
{
	t_phong_params	p;

	if (initialize_phong_params(&p, comps, light))
		return (p.ambient);
	compute_phong_model(&p, comps, light);
	return (color_add(color_add(p.ambient, p.diffuse), p.specular));
}

static void	compute_phong_model(\
	t_phong_params *p, t_computations *comps, t_light *light)
{
	if (p->light_dot_normal < 0.0)
	{
		p->diffuse = p->black;
		p->specular = p->black;
	}
	else
	{
		p->diffuse = color_multiply_s(p->eff_color, \
			comps->shape->material.diffuse * \
			p->light_dot_normal * \
			comps->frac_intensity);
		p->reflect = tuple_reflect(tuple_negate(p->light_dir), comps->normal);
		p->reflect_dot_eye = tuple_dot(p->reflect, comps->eye);
		if (p->reflect_dot_eye <= 0.0)
			p->specular = p->black;
		else
		{
			p->factor = pow(p->reflect_dot_eye, \
				comps->shape->material.shininess);
			p->specular = color_multiply_s(light->intensity, \
			comps->shape->material.specular * \
				p->factor * comps->frac_intensity);
		}
	}
}

static bool	initialize_phong_params(\
	t_phong_params *p, t_computations *comps, t_light *light)
{
	p->eff_color = color_multiply(\
		comps->shape->material.color, light->intensity);
	p->light_dir = tuple_normalize(\
		tuple_subtract(light->origin, comps->over_point));
	p->ambient = color_multiply_s(p->eff_color, comps->shape->material.ambient);
	p->light_dot_normal = tuple_dot(p->light_dir, comps->normal);
	p->reflect_dot_eye = 0.0;
	p->black = color_new(0.0, 0.0, 0.0);
	p->specular = p->black;
	p->diffuse = p->black;
	if (is_approx_equal(comps->frac_intensity, 0, M_EPSILON))
		return (true);
	return (false);
}
