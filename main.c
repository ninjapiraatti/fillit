#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>

/*
int		recursiontester(int i)
{
	if (i < 1)
		return (0);
	printf("I IS: %d\n", i);
	recursiontester(--i);
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
	//printf("RECURSION TEST: %d", recursiontester(4));
	/*
	if (validate(argv) == 1)
		ft_putstr("A valid file.");
	else
		ft_putstr("An invalid file.");
	printf("argc: %d\n", argc);
	*/
	return (0);
}