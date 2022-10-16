# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabid <moabid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 01:52:39 by moabid            #+#    #+#              #
#    Updated: 2022/10/16 01:32:53 by moabid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

SOURCES 	= $(shell find . -name "*.c" -type f -not -path '*/lib/*')

HEADERS 	= $(shell find . -name "*.h")

OBJECTS 	= $(patsubst %.c, %.o, $(SOURCES))
DEPENDS 	= $(patsubst %.c, %.d, $(SOURCES))

CFLAGS 		= -g
LINK_FLAGS 	= -lmlx -lm -L$(LIBX) -framework OpenGL -framework AppKit

LIBX  		= ./lib/mlx

MINILIBX	= ./lib/mlx/libmlx.a
LIBFT 		= ./lib/libft/libft.a


all: $(NAME)

%.o: %.c
	@$(CC) -Iincludes $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "Dependencies Compiled !"
	@make -C ./lib/libft --silent
	@make -C ./lib/mlx --silent
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJECTS) $(LIBFT) $(LINK_FLAGS) $(MINILIBX)
	@echo "Compiled !"

clean:
	-@make fclean -C ./lib/libft --silent
	-@make clean -C ./lib/mlx --silent
	-@$(RM) $(OBJECTS) $(DEPENDS)
	@echo "Everything is Cleaned !"

fclean: clean
	-@$(RM) $(NAME)

re: clean all

.PHONY: re run fclean clean all

-include $(DEPENDS)