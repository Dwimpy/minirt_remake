/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:34:47 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 21:34:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "MLX42.h"
# include "MLX42_Input.h"
# include "renderer.h"

void	key_hooks(mlx_key_data_t key_data, void *param);

#endif
