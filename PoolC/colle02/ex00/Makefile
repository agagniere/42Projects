#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 17:24:39 by angagnie          #+#    #+#              #
#    Updated: 2015/07/27 18:50:47 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# === For debugging ===
DBPATH=debug_
REPATH=ft_
# == Just (Un)comment =
CURPATH=$(DBPATH)
#CURPATH=$(REPATH)
# =====================

# === Editable ===
NAME=colle-2
# Just put a ']' and the file's name or [ for debug/release.
SRCLIST=]main.c ]ft_putstr.c ]ft_read_stdin.c [print.c ]ft_check_form.c \
	]ft_strdup.c ]gooo.c \
	]forms/colle_00_0.c ]forms/colle_00_1.c ]forms/colle_00_2.c \
	]forms/colle_00_3.c ]forms/colle_00_4.c ]forms/rectangle.c \
	]forms/triangle_a.c ]forms/triangle_b.c ]forms/triangle_c.c \
	]forms/triangle_d.c \
	]lists/ft_create_elem.c ]lists/ft_list_clear.c ]lists/ft_list_push_back.c \
	]lists/ft_list_push_front.c ]lists/ft_list_merge.c ]lists/ft_list_size.c \
	]lists/ft_list_reverse.c
# Headers' names, again with a ']' This may actually be useless.
HDRLIST=]super.h ]ft_list.h ]form.h ]colors.h ]formtab.h
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

# === Colors ===
# was "\033[1;37m Hello \033[0;0m"
# then "$(WHITE) Hello $(END)"
WHITE="\033[1;37m"
RED="\033[1;31m"
GREEN="\033[1;32m"
BLACK="\033[1;30m"
END="\033[0;0m"
# ==============

# == First Rule : what to to by default ==
all:
ifeq ($(CURPATH),$(DBPATH))
	@echo $(RED) "\t\t/!\\ Debug Mode /!\\" $(END)
endif
	@echo $(GREEN) "\t - Make All -" $(END)
	@make $(NAME)
	@echo $(GREEN) "\t - Success! -" $(END)
ifeq ($(CURPATH),$(DBPATH))
	@echo $(RED) "\t\t/!\\ Debug Mode /!\\" $(END)
endif

# == Rule that compile the final file ==
$(NAME): $(CDR) $(OBJ)
	@echo "\033[1;35m - Compiling $@" $(RED)
	@$(CC) $(FULCFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[0;32m - Done!" $(END)

# == Rule that compile source files into object files ==
$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHPATH)
	@echo " - Compiling $< into $@"
	@$(CC) $(FULCFLAGS) -c $< -o $@

# == Rule called only if a source file is missing ==
$(SRCPATH)%.c:
	@echo $(RED) " /!\\ Missing file : $@ /!\\" $(BLACK)

# == Rule called only if a header file is missing ==
$(HDRPATH)%.h:
	@echo $(RED) " /!\\ Missing file : $@ /!\\" $(BLACK)

# == Rule that compile header files ==
$(CCHPATH)%.h.gch: $(HDRPATH)%.h $(CCHPATH)
	@echo "\033[0;36m - Compiling $< into $@"
	@$(CC) $(CFLAGS) -o $@ -c $<

# == Rule called if the cache folder doesn't exist yet ==
$(CCHPATH):
	@echo "\033[0;33m - cache not yet existing\033[1;37m"
	@mkdir $(CCHPATH) $(CCHPATH)/lists $(CCHPATH)/forms

# == Rule deleting compiled files : The cache folder ==
clean:
	@echo "\033[1;33m - Cleaning...\n\t{"
	@rm -vrf $(CCHPATH)
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
