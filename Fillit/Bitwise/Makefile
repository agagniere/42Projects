#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2016/01/21 18:45:36 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=fillit
FILES:=main input_checker solve output
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
LFLAGS:=-I $(HDRPATH)
CFLAGS:=-Wall -Wextra -Werror $(LFLAGS)
# ==================

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(LFLAGS) $(OBJ) -o $@
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(RED)
	@$(CC) $(CFLAGS) -c $< -o $@ 2>&1

%.c:
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@echo "Files :" $(FILES)

define_color:
	$(eval CFLAGS += -DCOLOR)

color: define_color all

norme:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v  Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme color define_color
