/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf_sample_cuboid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:03:37 by arobu             #+#    #+#             */
/*   Updated: 2023/08/16 21:11:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pdf.h"
#include "pdf_cuboid.h"
#include "rng.h"

static inline int		pdf_sample_face(t_pdf_cuboid *pdf);
static inline int		pdf_sample_specific_face(int index);
static inline t_tuple	pdf_sample_point(int face);

t_tuple	pdf_sample_cuboid(t_pdf_cuboid *pdf, t_pdf_type type, t_onb onb)
{
	int		face;
	t_tuple	point;

	face = pdf_sample_face(pdf);
	point = pdf_sample_point(face);
	return (point);
}

static inline t_tuple pdf_sample_point(int face)
{
	if (face == FRONT_FACE || face == BACK_FACE)
		return (tuple_new_vector(random_double() * 2, random_double() * 2, 0));
	else if (face == LOWER_FACE || face == UPPER_FACE)
		return (tuple_new_vector(random_double() * 2, 0, random_double() * 2));
	else
		return (tuple_new_vector(0, random_double() * 2, random_double() * 2));
}

static inline int	pdf_sample_face(t_pdf_cuboid *pdf)
{
	t_real	rnd;

	rnd = random_double();
	if (rnd < pdf->front_back_sde)
		return (pdf_sample_specific_face(FRONT_FACE));
	else if (rnd < pdf->top_bottom_side + pdf->front_back_sde)
		return (pdf_sample_specific_face(LOWER_FACE));
	else
		return (pdf_sample_specific_face(RIGHT_FACE));
}

static inline int	pdf_sample_specific_face(int index)
{
	t_real	rnd;

	rnd = random_double();
	if (rnd < 0.50)
		return (index);
	else
		return (index + 1);
}