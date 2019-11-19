# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bscussel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 17:45:27 by bscussel          #+#    #+#              #
#    Updated: 2019/11/16 18:46:09 by bscussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework Appkit

HEADER = ./src/fdf.h

CFILES = ./src/main.c \
			./src/ini.c \
			./src/map_read.c \
			./src/draw.c \
			./src/rotation.c \
			./src/input_and_help.c \
			./src/input_func.c \
			./src/color.c \

LIBFT = libft.a

MLIBX = minilibx/libmlx.a

LCFILES = ./libft/*.c

LOFILES = *.o

OBJ_DIR = obj

LHEADER = libft/libft.h

all: $(NAME)

$(NAME): $(LOFILES)
	ar rc $(LIBFT) $(OBJ_DIR)/$(LOFILES)
	ranlib $(LIBFT)
	ranlib $(MLIBX)
	$(CC) $(CFLAGS) -I=$(HEADER) -o $(NAME) $(CFILES) $(LIBFT) \
		-I minilibx -L minilibx $(MLXFLAGS)

$(LOFILES): $(LCFILES)
	mkdir $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -I=$(LHEADER) $(LCFILES)
	mv *.o $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(NAME) $(LIBFT) $(LOFILES) $(OBJ_DIR)

re: fclean all 

.PHONY: clean fclean all re
