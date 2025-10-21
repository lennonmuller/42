CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

.PHONY: all clean fclan re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclan all
