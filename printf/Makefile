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

NAME = libftprintf.a
LIBFT_A = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
SRC = ft_printf.c srcs/print_string.c srcs/print_int.c srcs/print_char.c \
	srcs/ft_putnbr_base.c srcs/print_pointer.c srcs/print_unsigned.c \
	srcs/print_hex.c
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