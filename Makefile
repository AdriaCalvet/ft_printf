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

# <-- Library's Name --> #
NAME = libftprintf.a

# <-- Compilation Command --> #
CC = gcc

# <-- Compilation Flags --> #
CFLAGS = -Wall -Werror -Wextra

# <-- Remove Command -->#
RM = rm -f

# <-- HEADER --> #
HEADER = ft_printf.h

# <-- MAKEFILE --> #
MAKEFILE = Makefile

# <-- AR --> #
AR = ar -rcs

# <-- Files --> #
SRC_FILES = ft_printf.c utils.c ft_hex.c ft_printnbr.c ft_porcentaje.c ft_print_unsigned.c ft_pointer_hex.c

# <-- Objects --> #
OBJS = $(SRC_FILES:.c=.o)

# <-- Main Target --> #
all: $(NAME)

# <--Library Creation--> #
$(NAME): $(OBJS)
	@echo "✅ 🚀 0bjects created successfully!"
	@$(AR) $@ $(OBJS)
	@echo "✅ 🛰  $(NAME) created successfully!"

# <-- Objects Creation --> #
%.o: %.c $(HEADER) $(MAKEFILE)
	@echo "🧩 ☁️  Compiling... $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 🦔 $@ created!"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJS)
	@echo "🗑️  🚀 Objects destroyed successfully!"

# <-- Clean Execution + libft.a Destruction --> #
fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  🛰  $(NAME) destroyed successfully!"

# <-- Fclean Execution -->
re: fclean all

# <-- Targets Declaration --> #
.PHONY : all clean fclean re