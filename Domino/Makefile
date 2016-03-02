#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/28 06:40:32 by angagnie          #+#    #+#              #
#    Updated: 2016/03/02 20:17:38 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=IAhyperforte
FLAGS=-g -Wall -Wextra -Werror -I includes/
LIBFT=libft/libft.a
LIBFLAGS=-lft -L libft
SRCSF=main.c input.c input2.c play.c play2.c board.c
OBJSF=$(SRCSF:.c=.o)
SRCDIR=srcs/
OBJDIR=objs/
SRCS=$(addprefix srcs/, $(SRCSF))
OBJS=$(addprefix objs/, $(OBJSF))

all: $(LIBFT) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo " \c"
	@gcc $(FLAGS) -c $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "\033[1;35m$(NAME) compiling... |\033[0m\033[45m\c"

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJDIR) $(OBJS)
	@echo "\033[0m\033[1;35m|\033[0m"
	@mv $(OBJSF) $(OBJDIR)
	@gcc $(LIBFLAGS) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;32m$(NAME) ready ✓\033[0m"

clean:
	@rm -rf objs/
	@echo "\033[1;31m$(NAME) objects deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31m$(NAME) binary file deleted\033[0m"
#	@make -C libft/ fclean

re: clean all

.PHONY: all clean fclean re
