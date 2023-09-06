#include "vector.h"

/* bool	vector_move_to(t_vector *vector, int from, int to)
{
	void	*buf_from;
	void	*vector_to;
	size_t	bytes_to_shift;

	if (vector->size < 2 || from == to)
		return (false);
	vector_resize(vector);
	if (from < to)
	{
		vector_to = vector_at(vector, to);
		buf_from = vector_at(vector, from);
		ft_memmove(vector_to, vector_to + vector->item_size, (vector->size - to) * vector->item_size);
		ft_memcpy(vector_to, buf_from, vector->item_size);
		ft_memmove(buf_from, buf_from + vector->item_size, (vector->size - from) * vector->item_size);
		
	}
	return (true);
} */

bool	vector_move_to(t_vector *vector, int from, int to)
{
	void	*element_from;
	void	*element_to;
	void	*temp;

	element_from = vector_at(vector, from);
	element_to = vector_at(vector, to);
	temp = malloc(vector->item_size);
	if (temp == NULL)
		return (false);
	if (vector->size < 2 || from == to)
		return (false);
	if (from >= 0 && from < vector->size && to >= 0 && to < vector->size)
	{
		ft_memcpy(temp, element_from, vector->item_size);
		ft_memcpy(element_from, element_to, vector->item_size);
		ft_memcpy(element_to, temp, vector->item_size);
		free(temp);
		return (true);
	}
	return (false);
}
