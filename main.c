#include <stdio.h> // REMOVE IT YOU DUMBASS
#include <stdlib.h>
#include <time.h>
#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	char	*raw;
	int		fd;
	t_list	*pieces;

	pieces = NULL;
	fd = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit <filename>.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	raw = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		raw = ft_strjoin(raw, line);
	}
	if (asciicheck(raw) == 0)
	{
		printf("Not valid ascii.");
		return (0);
	}
	if (validate(raw) == 0)
	{
		printf("Error in tetriminos.");
		return (0);
	}
	solve(scan_save_tetramino(raw, pieces));
	/*
	if (validate(argv) == 1)
		ft_putstr("A valid file.");
	else
		ft_putstr("An invalid file.");
	printf("argc: %d\n", argc);
	*/
	return (0);
}