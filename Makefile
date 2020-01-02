# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malasalm <malasalm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/01 14:57:04 by tlouekar          #+#    #+#              #
#    Updated: 2020/01/01 15:06:12 by malasalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	fillitsrcs/main.c \
		fillitsrcs/validate.c \
		fillitsrcs/solve.c \
		fillitsrcs/scan_save_tetramino.c \
		fillitsrcs/print_grid.c \

OBJS = 	validate.o \
		solve.o \
		scan_save_tetramino.o \
		print_grid.o \
		main.o \

INCL = -I ./fillitsrcs -I ./libft/includes/

CFLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(CFLAGS) -c $(SRCS) $(INCS)
	gcc $(CFLAGS) $(INCS) $(OBJS) $(LIB) -o $(NAME)

.PHONY: clean fclean re exe debug all

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: clean all
