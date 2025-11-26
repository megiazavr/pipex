NAME := pipex
CC := cc
CFLAGS := -Wall -Werror -Wextra

SRC := main.c helpers.c parsing.c

OBJ := $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o %.cc
	$(CC) $(CFLAGS) -c $< -o $@

all:

clean:
	rm -f $(OBJ)
	@echo "cleaned"

flean: clean
	rm -rf $(OBJ)
	@echo "clean cleaned"

re: fclean $(NAME) 

.PHONY: all clean fclean re 