#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/28 22:45:14 by angagnie          #+#    #+#              #
#    Updated: 2015/12/08 17:12:00 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# === For debugging ===
DBPATH=db_
REPATH=ft_
# == Just (Un)comment =
#CURPATH=$(DBPATH)
CURPATH=$(REPATH)
# =====================

# === Editable ===
NAME=libft_tester
LIBFT=~/Documents/42Projects/Libft/
# Just put the filename without the ".c".
SRCLIST=main test_atoi test_bzero\
	test_strlen test_putnbr test_allchar test_memset strcln \
	test_putstr test_putchar_fd test_strcpy make_buf test_memcpy \
	test_memchr test_strlcat test_memcmp test_memmove test_dyna \
	test_strcat
# Headers' names. This may actually be useless.
HDRLIST=testlibft macroes ../../libft
# === Standard ===
# source's directory
SRCPATH=src/
# Headers' directory
HDRPATH=hdr/
# Cache's path
CCHPATH=cache/
# ================

# === Better not to touch ===
SRC:=$(addprefix $(SRCPATH),$(addsuffix .cpp,$(SRCLIST)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(SRCLIST)))
HDR:=$(addprefix $(HDRPATH),$(addsuffix .h,$(HDRLIST)))
CC:=clang++
CFLAGS:=-Wall -Wextra -std=c++14
DEFLAG=
FULCFLAGS=$(CFLAGS) -I $(HDRPATH) -I $(LIBFT) $(DEFLAG)
LDFLAG:=-L $(LIBFT) -lft
# ===========================

# === Colors ===
# was "\033[1;37m Hello \033[0;0m"
# then $(WHITE) "Hello" $(END)
WHITE="\033[1;37m"
RED="\033[1;31m"
GREEN="\033[1;32m"
BLACK="\033[1;30m"
END="\033[0;0m"
# ==============

# == First Rule : what is done by default ==
all: print_1 print_2

print_1:
ifeq ($(CURPATH),$(DBPATH))
	@echo "\033[0;31m" "\t\t/!\\ Debug Mode /!\\"
	@norminette $(SRC) $(HDR) | grep -v  Norme -B 1 || true
	@echo $(END)
endif
	@echo $(GREEN) "\t - Make All -" $(END)

print_2: $(NAME)
	@echo $(GREEN) "\t - Success! -" $(END)
ifeq ($(CURPATH),$(DBPATH))
	@echo $(RED) "\t\t/!\\ Debug Mode /!\\" $(END)
endif

# == Rule that compile the final file ==
$(NAME): $(OBJ)
	@echo "\033[1;35m - Compiling $@" $(RED)
	@$(CC) $(LDFLAG) $(OBJ) -o $(NAME)
	@echo "\033[0;32m - Done!" $(END)

# == Rule that compile source files into object files ==
$(CCHPATH)%.o: $(SRCPATH)%.cpp .cache_exists
	@echo "\033[1;36m - Compiling $< into $@" $(RED)
	@$(CC) $(FULCFLAGS) -c $< -o $@

# == Rule called only if a source file is missing ==
$(SRCPATH)%.cpp:
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
	@echo $(DEFLAG)

detailed: set_detailed all

# == Rule preventing conflicts ==
.PHONY: all clean fclean re test print_1 print_2 set_detailed detailed
