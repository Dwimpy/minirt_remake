#include "vector.h"
#include <stdio.h>
#include <string.h>
bool vector_insert_at(t_vector *vector, int index, void *elem)
{
	void	*buf;

    if (index < 0)
        return false; // Invalid index
	if (index >= vector->size)
		return (vector_pushback(vector, elem));
    vector_resize(vector);
	buf = vector_at(vector, index);
	ft_memmove(buf + vector->item_size, buf, (vector->size - index) * vector->item_size);
    ft_memmove(buf, elem, vector->item_size);
    vector->size++; // Increment the size
    return true;
}

