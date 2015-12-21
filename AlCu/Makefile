# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/30 01:29:56 by yaitalla          #+#    #+#              #
#    Updated: 2015/12/21 01:19:48 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Alum1
CFLAGS=-Werror -Wextra -Wall -Ilibft/includes
LFLAGS=-Llibft -lft
SRC= main.c setup.c game.c input.c output.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LFLAGS)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

lib:
	make -C libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean lib all
