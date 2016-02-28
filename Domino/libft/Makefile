NAME=libft.a
FLAGS=-Wall -Wextra -Werror -I includes/
CC=gcc
SRCS=ft_atoi.c ft_putendl.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_strrchr.c \
	 ft_putendl_fd.c ft_putstr_fd.c ft_strcpy.c ft_strncat.c ft_putchar.c \
	 ft_putnbr.c ft_strcat.c ft_strdup.c ft_strncmp.c ft_putchar_fd.c ft_putnbr_fd.c \
	 ft_strchr.c ft_strlcat.c ft_strncpy.c ft_strstr.c ft_strnstr.c ft_isalpha.c ft_isdigit.c \
	 ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c \
	 ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
	 ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	 ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	 ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lst_putstr.c \
	 ft_sortlist.c ft_lstsplit.c ft_strrev.c ft_ministr.c ft_factorial.c ft_power.c ft_isprime.c \
	 ft_printbits.c ft_lstpushback.c ft_strndup.c get_next_line.c
OBJS=$(SRCS:.c=.o)
SRCDIR=sources/
OBJDIR=objects/
SOURCES=$(addprefix $(SRCDIR), $(SRCS))
OBJETS=$(addprefix $(OBJDIR), $(OBJS))

CLEAR		= \033[2K
UP 			= \033[A
NOCOLOR		= \033[0m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJETS)
	@echo "$(NOCOLOR)$(YELLOW)|$(NOCOLOR)"
	@mv $(OBJS) $(OBJDIR)
	@ar rc $(NAME) $(OBJETS)
	@ranlib $(NAME)
	@echo "$(NOCOLOR)$(GREEN)libft compiled ✓$(NOCOLOR)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)libft compiling... |$(NOCOLOR)\033[43m\c"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo " \c"
	@$(CC) $(FLAGS) -c $<

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)libft objects deleted$(NOCOLOR)"

fclean: clean
	@echo "$(RED)libft.a destroyed$(NOCOLOR)"
	@rm -rf $(NAME)

re: fclean all
