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

SRCS=ft_printf.c

BONUS_SRCS=ft_printf.c

OBJECTS=ft_printf.o

BONUS_OBJECTS=ft_printf.o

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) printf.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS) $(BONUS_SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus: $(BONUS_OBJECTS)
	@ar rc $(NAME) $(BONUS_OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY all bonus clean fclean re
