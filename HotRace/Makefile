#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2016/04/24 01:59:32 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=hotrace

HASH_PATH:=hashmap/
HASH_FILES:=hmap hm_memcpy

FILES:=main functions
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
CFLAGS:=-Wall -Wextra -I $(HDRPATH)
# ==================

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
FILES+=$(addprefix $(HASH_PATH),$(HASH_FILES))

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists
#MAKEFLAGS+=-j

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(PURPLE) " - Compiling $@" $(RED)
	@$(CC) -o $(NAME) $(OBJ)
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(CYAN) "  - Compiling $< into $@" $(END)
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir -p $(CCHPATH)$(HASH_PATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

test:
	@echo "Files :" $(FILES)

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norm
