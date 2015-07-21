#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 17:24:39 by angagnie          #+#    #+#              #
#    Updated: 2015/07/21 21:39:48 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# === For debugging ===
# == Just (Un)comment =
#CURPATH=debug_
#CURPATH=release_
# =====================

# === Editable ===
NAME=do-op
# Just put a ']' and the file's name or [ for debug/release.
SRCLIST=]ft_putchar.c ]ft_putstr.c ]ft_atoi.c ]main.c ]ft_putnbr.c ]compute.c ]operations.c
# Headers' names, again with a ']' This may actually be useless.
HDRLIST=]super.h
# === Standard ===
# source's directory
SRCPATH=srcs/
# Headers' directory
HDRPATH=includes/
# Cache's path
CCHPATH=cache/
# ================

# === Better not to touch ===
OBJLIST=$(SRCLIST:.c=.o)
CDRLIST=$(HDRLIST:.h=.h.gch)
SRC=$(subst [,$(SRCPATH)$(CURPATH),$(subst ],$(SRCPATH),$(SRCLIST)))
OBJ=$(subst [,$(CCHPATH)$(CURPATH),$(subst ],$(CCHPATH),$(OBJLIST)))
HDR=$(subst ],$(HDRPATH),$(HDRLIST))
CDR=$(subst ],$(CCHPATH),$(CDRLIST))
CC=gcc
CFLAGS=-Wall -Wextra -Werror
FULCFLAGS=$(CFLAGS) -I $(HDRPATH)
# ===========================

# to use white : "\033[1;37m"

# == First Rule : what to to by default ==
all:
	@echo "\033[1;32m\t - Make All -\033[1;37m"
	@make $(NAME)
	@echo "\033[1;32m\t - Success! -\033[0;37m"

# == Rule that compile the final file ==
$(NAME): $(CDR) $(OBJ)
	@echo "\033[1;35m - Compiling $@\033[1;31m"
	@$(CC) $(FULCFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[0;32m - Done!\033[0;37m"

# == Rule that compile source files into object files ==
$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHPATH)
	@echo "\033[1;36m - Compiling $< into $@\033[1;31m"
	@$(CC) $(FULCFLAGS) -c $< -o $@

# == Rule called only if a source file is missing ==
$(SRCPATH)%.c:
	@echo "\033[1;31m /!\\ Missing file : $@ /!\\ \033[1;30m"

# == Rule called only if a header file is missing ==
$(HDRPATH)%.h:
	@echo "\033[1;31m /!\\ Missing file : $@ /!\\ \033[1;30m"

# == Rule that compile header files ==
$(CCHPATH)%.h.gch: $(HDRPATH)%.h $(CCHPATH)
	@echo "\033[0;36m - Compiling $< into $@\033[1;31m"
	@$(CC) $(CFLAGS) -o $@ -c $<

# == Rule called if the cache folder doesn't exist yet ==
$(CCHPATH):
	@echo "\033[0;33m - cache not yet existing\033[1;37m"
	@mkdir $(CCHPATH)

# == Rule deleting compiled files : The cache folder ==
clean:
	@echo "\033[1;33m - Cleaning...\n\t{"
#@rm -vf $(OBJ)
#@rm -vf $(CDR)
	@rm -vrf $(CCHPATH)
	@echo "\t} Done"

# == Rule calling clean and deleting the final file ==
fclean: clean
	@echo " - Deleting $(NAME)\033[1;37m"
	@rm -f $(NAME)

# == Rule used to force the compilation of every single file ==
re:	fclean all
	@echo "\033[0;32m - Resetting : Done !\033[1;37m"

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
