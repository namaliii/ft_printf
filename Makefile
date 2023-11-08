# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 17:14:12 by anamieta          #+#    #+#              #
#    Updated: 2023/11/08 17:59:41 by anamieta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_put.c ft_puthextype.c
OBJS = $(SRC:%.c=%.o)
all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f libftprintf.a

re: fclean all

.PHONY: all clean fclean re