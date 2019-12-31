NAME = fillit

SRCS = 	main.c \
		validate.c \
		solve.c \
		scan_save_tetramino.c \
		print_grid.c \

OBJS = 	validate.o \
		solve.o \
		scan_save_tetramino.o \
		print_grid.o \

INCS = 	libft/includes/

CFLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCS) $(LIB)

debug:
	gcc -g $(CFLAGS) $(SRCS) -I $(INCS) $(LIB)

.PHONY: clean fclean re exe debug all

clean:
	/bin/rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

exe:
	gcc $(CFLAGS) -g $(NAME) $(SRCS) -I $(INCS) $(LIB)