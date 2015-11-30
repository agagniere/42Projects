#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/28 22:45:14 by angagnie          #+#    #+#              #
#    Updated: 2015/11/30 17:18:35 by angagnie         ###   ########.fr        #
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
NAME=libft.a
# Just put the filename without the ".c".
SRCLIST=ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl \
	ft_isdigit ft_isgraph ft_islower ft_isprint ft_ispunct ft_isspace ft_isupper \
	ft_isxdigit ft_itoa ft_itoa_base ft_memalloc ft_memccpy ft_memchr ft_memdel \
	ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl \
	ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr \
	ft_strrchr ft_strcmp ft_strcpy ft_strdup ft_strjoin ft_strlcat ft_strlen ft_strncat \
	ft_strncmp ft_strncpy ft_strnew ft_strnstr ft_strstr ft_tolower ft_toupper \
	ft_strdel ft_strtrim ft_strsub ft_strsplit ft_strclr ft_strequ ft_striter \
	ft_striter ft_strmap ft_striteri ft_strmapi ft_strnequ
# Headers' names. This may actually be useless.
HDRLIST=libft
# === Standard ===
# source's directory
SRCPATH=./
# Headers' directory
HDRPATH=./
# Cache's path
CCHPATH=cache/
# ================

# === Better not to touch ===
SRC=$(addprefix $(SRCPATH),$(addsuffix .c,$(SRCLIST)))
OBJ=$(addprefix $(CCHPATH),$(addsuffix .o,$(SRCLIST)))
HDR=$(addprefix $(HDRPATH),$(addsuffix .h,$(HDRLIST)))
CC=clang
CFLAGS=-Wall -Wextra
FULCFLAGS=$(CFLAGS) -I $(HDRPATH)
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
all:
ifeq ($(CURPATH),$(DBPATH))
	@echo "\033[0;31m" "\t\t/!\\ Debug Mode /!\\"
	@norminette $(SRC) $(HDR) | grep -v Norme -B 1 || true
	@echo $(END)
endif
	@echo $(GREEN) "\t - Make All -" $(END)
	@make $(NAME)
	@echo $(GREEN) "\t - Success! -" $(END)
ifeq ($(CURPATH),$(DBPATH))
	@echo $(RED) "\t\t/!\\ Debug Mode /!\\" $(END)
endif

# == Rule that compile the final file ==
$(NAME): $(OBJ)
	@echo "\033[1;35m - Compiling $@" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;32m - Done!" $(END)

# == Rule that compile source files into object files ==
$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHPATH)
	@echo "\033[1;36m - Compiling $< into $@" $(RED)
	@$(CC) $(FULCFLAGS) -c $< -o $@

# == Rule called only if a source file is missing ==
$(SRCPATH)%.c:
	@echo $(RED) " /!\\ Missing file : $@ /!\\" $(BLACK)

# == Rule called only if a header file is missing ==
$(HDRPATH)%.h:
	@echo $(RED) " /!\\ Missing file : $@ /!\\" $(BLACK)

# == Rule that compile header files ==
$(CCHPATH)%.h.gch: $(HDRPATH)%.h $(CCHPATH)
	@echo "\033[0;36m - Compiling $< into $@" $(RED)
	@$(CC) $(CFLAGS) -o $@ -c $<

# == Rule called if the cache folder doesn't exist yet ==
$(CCHPATH):
	@echo "\033[0;33m - cache not yet existing\033[1;37m"
	@mkdir $(CCHPATH)

# == Rule deleting compiled files : The cache folder ==
clean:
	@echo "\033[1;33m - Cleaning...\n\t{"
	@rm -vrf $(CCHPATH)
	@rm -vrf stdin.txt
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

# == Rule preventing conflicts ==
.PHONY: all clean fclean re test
