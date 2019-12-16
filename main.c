#include <stdio.h> // REMOVE IT YOU DUMBASS
#include <stdlib.h>
#include <time.h>
#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>
/*
int		recursiontester(int j)
{
	int 	num;

	srand(time(0));
	num = (rand() % (100 - 0 + 1)) + 0;
	if (num < 50)
		j++;
	else
		j--;
	printf("%d ", j);
	if (j < 1)
	{
		printf("went to zero.");
		return (0);
	}
	else if (j > 15)
	{
		printf("went to hero.");
		return (1);
	}
	getchar();
	srand(time(0));
	num = (rand() % (100 - 0 + 1)) + 0;
	recursiontester(j);
	return(0);
}
*/

int		main(int argc, char **argv)
{
	char	*line;
	char	*raw;
	int		fd;

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
	asciicheck(raw);
	validate(raw);
	solve(raw);
	scan_save_tetramino(raw);
	//printf("RECURSION TEST: %d", recursiontester(8));
	/*
	if (validate(argv) == 1)
		ft_putstr("A valid file.");
	else
		ft_putstr("An invalid file.");
	printf("argc: %d\n", argc);
	*/
	return (0);
}