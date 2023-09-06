#include "vector.h"

bool	vector_move_to(t_vector *vector, int from, int to)
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
}