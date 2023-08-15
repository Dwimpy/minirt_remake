/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf_cuboid_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:26:44 by arobu             #+#    #+#             */
/*   Updated: 2023/08/15 22:26:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pdf.h"
#include "pdf_cuboid.h"

t_pdf	pdf_new_cuboid(t_tuple pdf_data)
{
	t_pdf			pdf;
	t_pdf_cuboid	*pdf_cuboid;
	t_real			total_surface_area;

	pdf_cuboid = ft_calloc(1, sizeof(t_pdf_cuboid));
	if (!pdf_cuboid)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	pdf_cuboid->front_back_sde = pdf_data.x * pdf_data.y;
	pdf_cuboid->left_right_side = pdf_data.y * pdf_data.z;
	pdf_cuboid->top_bottom_side = pdf_data.z * pdf_data.x;
	total_surface_area = pdf_cuboid->front_back_sde + pdf_cuboid->top_bottom_side + pdf_cuboid->left_right_side;
	pdf_cuboid->front_back_sde = pdf_cuboid->front_back_sde / total_surface_area;
	pdf_cuboid->top_bottom_side = pdf_cuboid->top_bottom_side / total_surface_area;
	pdf_cuboid->left_right_side = pdf_cuboid->left_right_side / total_surface_area;
	pdf.data = pdf_cuboid;
	return (pdf);
}