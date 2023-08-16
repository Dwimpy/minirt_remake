/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:02:54 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 23:02:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PDF_H
# define PDF_H
# include "tuple.h"
# include "onb.h"

typedef struct s_pdf_cuboid	t_pdf_cuboid;

typedef enum e_cuboid_face
{
	FRONT_FACE,
	BACK_FACE,
	LOWER_FACE,
	UPPER_FACE,
	RIGHT_FACE,
	LEFT_FACE
}			t_cuboid_face;

typedef enum s_pdf_type
{
	CUBOID,

}			t_pdf_type;

typedef struct s_pdf
{
	void		*data;
	t_tuple		(*sample)(t_pdf_cuboid * pdf, t_pdf_type type, t_onb onb);
}				t_pdf;

t_pdf	pdf_new_cuboid(t_tuple dimension);
t_tuple	pdf_sample_cuboid(t_pdf_cuboid *pdf, t_pdf_type type, t_onb onb);

#endif