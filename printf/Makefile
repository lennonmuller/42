# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 10:23:02 by lmuler-f          #+#    #+#              #
#    Updated: 2025/11/14 10:23:02 by lmuler-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_A = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
AR = ar rcs


all: $(NAME)
	
$(NAME): $(OBJ) $(LIBFT_A)
	$(AR) $(NAME) $(OBJ) $(LIBFT_A)

$(LIBFT_A):
	$(MAKE) -C ./libft

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re