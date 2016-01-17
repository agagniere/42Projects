#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/28 22:45:14 by angagnie          #+#    #+#              #
#    Updated: 2015/12/09 15:26:04 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# === Editable ===
NAME:=alum1
LIBFT:=~/Desktop/42Projects/Libft/
LIBFT_HDR:=~/Desktop/42Projects/Libft/include/
# Just put the filename without the ".c".
SRCLIST:=main game input output setup
# === Standard ===
# source's directory
SRCPATH:=src/
# Headers' directory
HDRPATH:=./
# Cache's path
CCHPATH:=cache/
# ================

# === Better not to touch ===
SRC:=$(addprefix $(SRCPATH),$(addsuffix .cpp,$(SRCLIST)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(SRCLIST)))
HDR:=$(addprefix $(HDRPATH),$(addsuffix .h,$(HDRLIST)))
CC:=clang
CFLAGS:=-Wall -Wextra
DEFLAG=
FULCFLAGS=$(CFLAGS) -I $(HDRPATH) -I $(LIBFT_HDR) $(DEFLAG)
LDFLAG:=-L $(LIBFT) -lft
# ===========================

# === Colors ===
# was "\033[1;37m Hello \033[0;0m"
# then $(WHITE) "Hello" $(END)
WHITE:="\033[1;37m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
BLACK:="\033[1;30m"
END:="\033[0;0m"
# ==============

# == First Rule : what is done by default ==
all: print_1 print_2

print_1:
	@echo $(GREEN) "\t - Make All -" $(END)

print_2: $(NAME)
	@echo $(GREEN) "\t - Success! -" $(END)

# == Rule that compile the final file ==
$(NAME): $(OBJ)
	@echo "\033[1;35m - Compiling $@" $(RED)
	@$(CC) $(LDFLAG) $(OBJ) -o $(NAME)
	@echo "\033[0;32m - Done!" $(END)

# == Rule that compile source files into object files ==
$(CCHPATH)%.o: $(SRCPATH)%.c .cache_exists
	@echo "\033[1;36m - Compiling $< into $@" $(RED)
	@$(CC) $(FULCFLAGS) -c $< -o $@

# == Rule called only if a source file is missing ==
$(SRCPATH)%.c:
	@echo $(RED) " /!\\ Missing file : $@ /!\\" $(BLACK)

# == Rule called only if a header file is missing ==
$(HDRPATH)%.h:
	@echo $(RED) " /!\\ Missing file : $@ /!\\" $(BLACK)

# == Rule called if the cache folder doesn't exist yet ==
.cache_exists:
	@echo "\033[0;33m - cache not yet existing\033[1;37m"
	@mkdir $(CCHPATH)
	@touch .cache_exists

# == Rule deleting compiled files : The cache folder ==
clean:
	@echo "\033[1;33m - Cleaning...\n\t{"
	@rm -vrf $(CCHPATH)
	@rm -f .cache_exists
	@echo "\t} Done"

# == Rule calling clean and deleting the final file ==
fclean: clean
	@echo " - Deleting $(NAME)" $(END)
	@rm -f $(NAME)

# == Rule used to force the compilation of every single file ==
re:	fclean all
	@echo $(GREEN) " - Resetting : Done !" $(END)

# == Rule originally used to debug this very file. Now just 4fun ==
test:
	@echo "\033[0;30mName : \033[1;30m $(NAME)"
	@echo "\033[0;31mCompiling with : \033[1;31m $(CC) $(FULCFLAGS)"
	@echo "\033[0;32mSources : \033[1;32m $(SRC)"
	@echo "\033[0;33mObjects : \033[1;33m $(OBJ)"
	@echo "\033[0;34mHeaders : \033[1;34m $(HDR)"
	@echo "\033[0;35mCompiled Headers : \033[1;35m $(CDR)"
	@echo "\033[0;36mThis file was written by : \033[1;36m angagnie"

set_detailed:
	$(eval DEFLAG = -DDETAILED)

detailed: set_detailed all

lib:
	@echo $(GREEN) " - Compiling the libft" $(END)
	@make -C $(LIBFT)

norme:
	@norminette $(SRC) $(HDR) | grep -v  Norme -B1 || true
	@echo $(END)

# == Rule preventing conflicts ==
.PHONY: all clean fclean re test print_1 print_2 set_detailed detailed lib
