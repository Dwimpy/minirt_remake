# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/08/09 05:04:05 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME			= minirt

VPATH			= ./src/tuple ./src/ray ./src/color ./src/matrix ./src/window ./src/image \
				  ./src/rng ./src/ortho_basis ./src/transform ./src/vector ./src/vector/iterator \
				  ./src/objects/shape ./src/intersect ./src/material ./src/light ./src/camera \
				  ./src/quaternion ./src/objects/sphere ./src/objects/plane ./src/scene
# Includes
INCLUDE			= -I libft-printf/include/ -I MLX42/include/MLX42/
INCLUDE			+= -I ./src/tuple
INCLUDE			+= -I ./src/ray
INCLUDE			+= -I ./src/color
INCLUDE			+= -I ./src/matrix
INCLUDE			+= -I ./src/window
INCLUDE			+= -I ./src/image
INCLUDE			+= -I ./src/rng
INCLUDE			+= -I ./src/ortho_basis
INCLUDE			+= -I ./src/vector
INCLUDE			+= -I ./src/transform
INCLUDE			+= -I ./src/intersect
INCLUDE			+= -I ./src/objects/sphere
INCLUDE			+= -I ./src/material
INCLUDE			+= -I ./src/light
INCLUDE			+= -I ./src/camera
INCLUDE			+= -I ./src/quaternion
INCLUDE			+= -I ./src/objects/shape
INCLUDE			+= -I ./src/objects/plane
INCLUDE			+= -I ./src/scene

DSYM			= ./minirt.dSYM
SRC_DIR			= ./src
OBJ_DIR			= ./obj
LIBFT_FOLDER	= ./libft-printf
LIBFT_LIB		= ./libft-printf/libft.a
MAIN_FILE		= main.c
MLX_LIB			= ./MLX42/build
GLFW_LIB		= ./glfw/build/src
GLFW_BUILD		= ./glfw/build
MLX_BUILD		= ./MLX42/build
NORM_INCLUDE	= ./include

# Modules

# Compiler
CC			= cc #-Wall -Werror -Wextra
CFLAGS		=  -march=native
ASAN		= #-fsanitize=address -g3
CFLAGS		=  -Ofast# -g3 -fsanitize=address -g3 #-g3 -Wall -Werror -Wextra -g3 #
FRAMEWORK	= -framework Cocoa -framework OpenGL -framework IOKit
LDLFLAGS	= -L $(LIBFT_FOLDER) -L $(MLX_LIB) -L $(GLFW_LIB)
LIBFLAGS	= -lft -lmlx42 -lglfw3 -lm
#LIBFLAGS	= -lft -L ./libft-printf/ -lmlx42 -L ./MLX42/build -ldl -lglfw -pthread

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

# Sources
SRCS	= $(shell find ./src -name "*.c")

# Objects
OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Rules
all: libft	
	@${MAKE} $(NAME) -j
$(NAME): $(OBJ_DIR) $(OBJS) $(MAIN_FILE)
	@$(CC) $(INCLUDE) $(FRAMEWORK) $(ASAN) $(OBJS) $(MAIN_FILE) -o $@ -lm $(LDLFLAGS) $(LIBFLAGS)
	@echo "$(YELLOW)MiniRT$(DEF_COLOR) $(CYAN)done.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

deps:
	@chmod +x ./install_deps.sh
	@echo "$(YELLOW)Installing dependencies..$(DEF_COLOR)"
	@./install_deps.sh

show:
	@echo $(OBJS)

libft:
			@make all -C $(LIBFT_FOLDER) -s

 clean:
			@$(RM) -rdf $(OBJ_DIR)
			@$(RM) -rdf $(DSYM)
			@echo "$(YELLOW)MiniRT$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

fclean:		clean
#			@make fclean -C $(LIBFT_FOLDER)
#			@rm -rdf $(GLFW_BUILD)
#			@rm -rdf $(MLX_BUILD)
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)All$(DEF_COLOR) $(CYAN)objects successfully cleaned!$(DEF_COLOR)"

re:			fclean all

relibft:
			@make re -C $(LIBFT_FOLDER)

bonus:	libft	mlx	$(NAME)

.PHONY:		all mlx relibft libft clean fclean re norm
