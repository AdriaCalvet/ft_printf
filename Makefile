# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 18:18:21 by acalvet           #+#    #+#              #
#    Updated: 2024/01/29 18:24:59 by acalvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=ft_printf.c utils.c ft_hex.c ft_printnbr.c ft_porcentaje.c ft_print_unsigned.c

OBJECTS=ft_printf.o utils.o ft_hex.o ft_printnbr.o ft_porcentaje.o ft_print_unsigned.o

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

# .PHONY all clean fclean re
