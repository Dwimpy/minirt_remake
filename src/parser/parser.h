/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:25:40 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/03 21:02:56 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

# define LINEBUFFER_MAX 4096


int		line_is_empty(const char *str);
void	test_parser(void);
#endif