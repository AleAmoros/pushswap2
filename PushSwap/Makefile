NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SOURCES := checks.c\
errors.c\
init.c\
push_swap.c\
push.c\
reverse.c\
rotate.c\
sort_big.c\
sort_simple.c\
splitt.c\
swap.c\
utils_list.c\
utils_min_max.c\
utils_split.c

OBJECTS := $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) 

clean:
	rm -f $(OBJECTS)
	@$(MAKE) -C clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C fclean

re: fclean all

.PHONY: all clean fclean re