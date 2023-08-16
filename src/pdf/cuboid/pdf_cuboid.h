/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf_cuboid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:19:16 by arobu             #+#    #+#             */
/*   Updated: 2023/08/15 22:19:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PDF_CUBOID_H
# define PDF_CUBOID_H
#include "cube.h"
# include "pdf.h"
# include "tuple.h"

typedef struct s_pdf_cuboid
{
	t_real		front_back_sde;
	t_real		top_bottom_side;
	t_real		left_right_side;
}				t_pdf_cuboid;



#endif