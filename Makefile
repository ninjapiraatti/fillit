NAME = fillit

SRCS = 	main.c \
		validate.c \
		solve.c \
		scan_save_tetramino.c \
		print_grid.c \

INCS = 	libft/includes/libft.h \

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCS) -L./libft -lft

debug:
	gcc -g $(CFLAGS) $(SRCS) -I $(INCS) -L./libft -lft

.PHONY: clean fclean re exe debug all

clean:
	/bin/rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

exe:
	gcc $(CFLAGS) -g $(NAME) $(SRCS) -I $(INCS) -L./libft -lft