
NAME = fillit

SRCS = 	main.c \
		validate.c \
		asciicheck.c \
		solve.c \
		scan_save_tetramino.c \

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