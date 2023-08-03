/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:07:43 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 20:07:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#define VECTOR_IDX_OUT_OF_BOUNDS "Index being accessed is out of bounds.\n"
#define VECTOR_RESIZE_FAILED "Vector resize buffer memory allocation failed.\n"

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
//# include "vector_iterator.h"

typedef struct s_vector_iterator t_vector_iterator;

typedef struct s_vector
{
	void		*buffer;
	size_t 		size;
	size_t		item_size;
	size_t		capacity;
}				t_vector;

typedef struct s_vector_iterator
{
	void				*(*get)(t_vector_iterator *it);
	void				(*next)(t_vector_iterator *it);
	bool				(*end)(t_vector_iterator *it1);
	size_t				index;
	const t_vector		*ptr;
}				t_vector_iterator;

t_vector	vector_init(size_t capacity, size_t n_size);
void		*vector_at(t_vector *vector, size_t index);
void		*vector_front(t_vector *vector);
void		*vector_back(t_vector *vector);
bool		vector_pushback(t_vector *vector, void *data);
int			vector_resize(t_vector *vector);
void		vector_clear(t_vector *vector);
void		vector_free(t_vector *vector);


void 	vector_iterator_begin(t_vector_iterator *it, t_vector *vector);
void 	vector_iterator_end(t_vector_iterator *it, t_vector *vector);
#endif