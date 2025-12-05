NAME := pipex
CC := cc
CFLAGS := -Wall -Wextra -Werror -g

SRC := \
	main.c \
	helpers.c \
	parsing.c \
	parsing2.c \
	finding_path.c \
	pipex.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "☼.☼ pipex compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re 