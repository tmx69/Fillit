# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 18:10:01 by jritchie          #+#    #+#              #
#    Updated: 2019/01/21 15:06:27 by jritchie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = $(patsubst %.c,%.o,$(SRC))

SRC = ./src/fillit.c \
./src/validator.c \
./src/list.c \
./src/widheicoord.c \
./src/tetris.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -g $(FLAGS) -o $(NAME) $^ -L libft -lft -I ./includes -I ./libft

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@ -I includes

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
