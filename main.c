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

#include "image.h"
#include "onb.h"
#include "rng.h"
#include "vec3.h"
#include "window.h"
#include "vector.h"
#include <stdlib.h>

void	run_tests()
{
	vec3_test();
	onb_tests();
}

int main(void) {
	t_window window;
	t_image canvas;
	t_vector			vector;
	t_vector_iterator	it;
	t_vector_iterator	end;
	vector = vector_init(5, sizeof(int));
	int a = 125;
	int b = 225;
	int c = 33;
	int d = 1;
	int e = 5;
	int f = 7;
	int g = 9;

	vector_pushback(&vector, &a);
	vector_pushback(&vector, &b);
	vector_pushback(&vector, &c);
	vector_pushback(&vector, &d);
	vector_pushback(&vector, &e);
	vector_pushback(&vector, &f);
	vector_pushback(&vector, &g);

	vector_iterator_begin(&it, &vector);
	while (!it.end(&it))
	{
		printf("%d\n", *(int *)it.get(&it));
		it.next(&it);
	}
//	run_tests();
	srand48(time(NULL));
	vec3_print(random_in_unit_sphere());
//	window_create(&window, 1024, 1024);
//	window_add_image(window.mlx, &canvas);
//	window_draw_loop(window.mlx);
	return (0);
}