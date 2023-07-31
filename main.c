/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:09 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 17:15:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "matrix.h"

int	main(void)
{
	t_matrix	mat;
	t_matrix	mat2;
	t_matrix 	mult;

	mat = matrix_init(4);
	mat2 = matrix_init(4);

	vec3_test();
	matrix_set_element_at(mat, 1, 1, 1);
	matrix_set_element_at(mat, 1, 2, 2);
	matrix_set_element_at(mat, 1, 3, 3);
	matrix_set_element_at(mat, 1, 4, 4);
	matrix_set_element_at(mat, 2, 1, 5);
	matrix_set_element_at(mat, 2, 2, 6);
	matrix_set_element_at(mat, 2, 3, 7);
	matrix_set_element_at(mat, 2, 4, 8);
	matrix_set_element_at(mat, 3, 1, 9);
	matrix_set_element_at(mat, 3, 2, 8);
	matrix_set_element_at(mat, 3, 3, 7);
	matrix_set_element_at(mat, 3, 4, 6);
	matrix_set_element_at(mat, 4, 1, 5);
	matrix_set_element_at(mat, 4, 2, 4);
	matrix_set_element_at(mat, 4, 3, 3);
	matrix_set_element_at(mat, 4, 4, 2);

	matrix_set_element_at(mat2, 1, 1, -2);
	matrix_set_element_at(mat2, 1, 2, 1);
	matrix_set_element_at(mat2, 1, 3, 2);
	matrix_set_element_at(mat2, 1, 4, 3);
	matrix_set_element_at(mat2, 2, 1, 3);
	matrix_set_element_at(mat2, 2, 2, 2);
	matrix_set_element_at(mat2, 2, 3, 1);
	matrix_set_element_at(mat2, 2, 4, -1);
	matrix_set_element_at(mat2, 3, 1, 4);
	matrix_set_element_at(mat2, 3, 2, 3);
	matrix_set_element_at(mat2, 3, 3, 6);
	matrix_set_element_at(mat2, 3, 4, 5);
	matrix_set_element_at(mat2, 4, 1, 1);
	matrix_set_element_at(mat2, 4, 2, 2);
	matrix_set_element_at(mat2, 4, 3, 7);
	matrix_set_element_at(mat2, 4, 4, 8);

	mult = matrix_multiply(mat, mat2);
	int i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			printf("%f ", mult.matrix[i * mult.dimension + j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("Equal: %d\n", matrix_equal(mat, mat2));
	return (0);
}
