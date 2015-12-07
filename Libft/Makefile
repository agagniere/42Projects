#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2015/12/07 22:18:20 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=libft.a
FILES:=ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl ft_isdigit ft_isgraph ft_islower ft_isprint ft_ispunct ft_isspace ft_isupper ft_isxdigit ft_itoa ft_itoa_base ft_memalloc ft_memccpy ft_memchr ft_memdel ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strrchr ft_strcmp ft_strcpy ft_strdup ft_strjoin ft_strlcat ft_strlen ft_strncat ft_strncmp ft_strncpy ft_strnew ft_strnstr ft_strstr ft_tolower ft_toupper ft_strdel ft_strtrim ft_strsub ft_strsplit ft_strclr ft_strequ ft_striter ft_striter ft_strmap ft_striteri ft_strmapi ft_strnequ ft_realloc\
ft_lstadd ft_lstdel ft_lstdel_rec ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_lstpush ft_lstpush_rec \
ft_dyna_alloc ft_dyna_append ft_dyna_dataclear ft_dyna_dataclearf ft_dyna_datainit ft_dyna_del ft_dyna_free ft_dyna_new ft_dyna_trim
# ==================

# ==== Standard ====
CC:=clang
CFLAGS:=-Wall -Wextra
CCHPATH:=cache
SRCPATH:=.
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
SRC:=$(addprefix $(SRCPATH)/,$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH)/,$(addsuffix .o,$(FILES)))
# ==================

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(CCHPATH)/%.o: $(SRCPATH)/%.c .cache_exists
	@echo $(PURPLE) " - Compiling $< into $@" $(RED)
	@$(CC) $(CFLAGS) -c $< -o $@

.cache_exists:
	@mkdir $(CCHPATH)
	@echo "OK" > .cache_exists

clean:
	@rm -rf $(CCHPATH)
	@rm -f .cache_exists

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
