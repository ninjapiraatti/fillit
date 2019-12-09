# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 11:06:50 by tlouekar          #+#    #+#              #
#    Updated: 2019/12/04 14:34:47 by tlouekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	main.c \
		validate.c \

INCS = 	libft/includes/libft.h \

CFLAGS = -Wall -Wextra -Werror

all:
	gcc $(CFLAGS) $(SRCS) -I $(INCS) -L./libft -lft

debug:
	gcc -g $(CFLAGS) $(SRCS) -I $(INCS) -L./libft -lft

.PHONY: clean

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

exe:
	gcc $(CFLAGS) -g $(NAME) $(SRCS) -I $(INCS) -L./libft -lft