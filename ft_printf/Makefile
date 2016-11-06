#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by angagnie          #+#    #+#              #
#    Updated: 2016/11/06 01:09:34 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME:=libftprintf.a
FILES:=ft_vasprintf ft_printf ft_vprintf db_printf ft_convert \
	ft_convert_1

# ----- Libft ------
LFTDIR:=../Libft
# ==================

# ------------------
COMPILER:=clang
LINKER:=ar rc
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=cache/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra $(IFLAGS)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) "\tCompiling $@" $(RED)
	@$(LINKER) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN)"OK"$(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) "\tCompiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

test: $(NAME)
	@echo "Files :" $(FILES)
	@$(COMPILER) $(CFLAGS) src/main.c -L ./ $(LFLAGS) -lftprintf

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
