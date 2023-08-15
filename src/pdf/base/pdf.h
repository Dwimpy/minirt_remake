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

typedef struct s_pdf
{
	void		*data;
	t_tuple		(*sample)(void *pdf_data);
}				t_pdf;

t_pdf	pdf_new_cuboid(t_tuple dimension);

#endif