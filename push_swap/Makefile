CHECKER:=checker
PUSH_SWAP:=push_swap

FILES=read_args instructions execute_instruction
SOURCES_FOLDER=src
OBJECTS_FOLDER=cache
HEADERS_FOLDER=include

SOURCES=$(addprefix $(SOURCES_FOLDER)/,$(addsuffix .c,$(FILES)))
OBJECTS=$(addprefix $(OBJECTS_FOLDER)/,$(addsuffix .o,$(FILES)))

LIBFT_PATH=~/Desktop/Libft
LIBFT=$(LIBFT_PATH)/libft.a

INCLUDE_FOLDERS=$(HEADERS_FOLDER) $(LIBFT_PATH)/include

I_FLAGS=$(addprefix -I ,$(INCLUDE_FOLDERS))
C_FLAGS=-Wall -Wextra -ansi $(I_FLAGS)
L_FLAGS=-L $(LIBFT_PATH) -lft

COMPILER=clang

MAKEFLAGS+=-j

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJECTS_FOLDER)/checker.o $(OBJECTS) | $(LIBFT)
	$(COMPILER) $(L_FLAGS) -o $@ $^

$(PUSH_SWAP): $(OBJECTS_FOLDER)/push_swap.o $(OBJECTS)
	$(COMPILER) $(L_FLAGS) -o $@ $^

$(OBJECTS_FOLDER)/%.o: $(SOURCES_FOLDER)/%.c | $(OBJECTS_FOLDER)
	$(COMPILER) $(C_FLAGS) -o $@ -c $<

$(OBJECTS_FOLDER):
	mkdir $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(CHECKER) $(PUSH_SWAP)

re: fclean all

.PHONY: all clean fclean re
