# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 01:17:05 by arobu             #+#    #+#              #
#    Updated: 2023/04/14 14:30:19 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= libft.a
INCLUDE			= ./include/

FT_PRINTF_SDIR	= ./src/ft_printf
FT_STDLIB_SDIR	= ./src/ft_stdlib

OBJ_DIR			= ./obj/
FT_PRINTF_OBJ	= ./obj/ft_printf
FT_STDLIB_OBJ	= ./obj/ft_stdlib

FT_STDLIB_LIB	= ft_stdlib.a
FT_PRINTF_LIB	= ft_printf.a
LIBFT_LIB		= libft.a
# Compiler

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I

#Archive and Remove

RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

STDLIB_SRCS	=	ft_atof.c ft_atoi.c ft_bzero.c  \
				ft_calloc.c ft_concat.c ft_contains.c ft_isalnum.c  \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c  \
				ft_isspace3.c ft_itoa.c ft_itoa_pbase.c ft_itoa_ubase.c  \
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c  \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c  \
				ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c  \
				ft_memmove.c ft_memset.c ft_min.c ft_putchar_fd.c  \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c  \
				ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c  \
				ft_strjoin_four.c ft_strjoin_three.c ft_strlcat.c ft_strlcpy.c  \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnew_zeros.c  \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c  \
				ft_tolower.c ft_toupper.c ft_uitoa.c ft_atoi_long.c ft_isnumber.c \
				ft_strcpy.c ft_strcat.c ft_strncpy.c ft_strncat.c
STDLIB_OBJS	= 	$(patsubst %.c, $(FT_STDLIB_OBJ)/%.o, $(STDLIB_SRCS))

PRINTF_SRCS	=	ft_add_width_c.c ft_count_digits.c ft_create_precision.c ft_create_string.c  \
				ft_create_string_di.c ft_create_string_p.c ft_create_string_percent.c ft_create_string_s.c  \
				ft_create_string_u.c ft_create_string_x.c ft_create_width.c ft_get_flags.c  \
				ft_get_precision.c ft_get_specifier.c ft_get_width.c ft_handle_options.c  \
				ft_handle_specifier.c ft_handle_specifier_di.c ft_handle_specifier_p.c ft_handle_specifier_percent.c  \
				ft_handle_specifier_s.c ft_handle_specifier_u.c ft_handle_specifier_x.c ft_init_field.c  \
				ft_printf.c ft_strdup_spec_s.c ft_strnew.c ft_validate_specifier_di.c  \
				ft_validate_specifier_p.c ft_validate_specifier_percent.c ft_validate_specifier_s.c ft_validate_specifier_u.c  \
				ft_validate_specifier_x.c
PRINTF_OBJS	= 	$(patsubst %.c, $(FT_PRINTF_OBJ)/%.o, $(PRINTF_SRCS))


all: libft printf 
	${MAKE} $(NAME) -j

$(NAME):
					@echo "$(CYAN) Creating $(YELLOW)libft$(DEF_COLOR) library.$(DEF_COLOR)"
					@ar rcs libft.a $(STDLIB_OBJS) $(PRINTF_OBJS)
					@echo "$(CYAN) Created$(DEF_COLOR) $(YELLOW)libft$(DEF_COLOR) $(CYAN)successfully.$(DEF_COLOR)" 

libft:		
	${MAKE} $(FT_STDLIB_LIB) -j

$(FT_STDLIB_LIB):	$(STDLIB_OBJS)

$(FT_STDLIB_OBJ)%.o:	$(FT_STDLIB_SDIR)%.c | $(FT_STDLIB_OBJ)
						@echo "$(MAGENTA) Compiling:$(DEF_COLOR) $(notdir $<)"
						@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(FT_STDLIB_OBJ): | $(OBJ_DIR)
					@mkdir -p $(FT_STDLIB_OBJ)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

printf:		
	${MAKE} $(FT_PRINTF_LIB) -j

$(FT_PRINTF_LIB):	$(PRINTF_OBJS)

$(FT_PRINTF_OBJ)%.o:	$(FT_PRINTF_SDIR)%.c | $(FT_PRINTF_OBJ)
						@echo "$(MAGENTA) Compiling:$(DEF_COLOR) $(notdir $<)"
						@ $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(FT_PRINTF_OBJ): | $(OBJ_DIR)
					@mkdir -p $(FT_PRINTF_OBJ)

clean:
			@$(RM) -rdf $(OBJ_DIR) 
			@echo "$(YELLOW)Object$(DEF_COLOR) $(CYAN)files successfullly cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(FT_STDLIB_LIB) 
			@$(RM) $(FT_PRINTF_LIB) 
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)Libraries$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

bonus: 	$(NAME)  

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true
		
.PHONY:		all clean fclean re norm
