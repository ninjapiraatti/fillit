#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	char	*raw;
	int		fd;
	t_list	*pieces;
	int		i;

	i = 0;
	pieces = NULL;
	fd = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit <filename>.\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) != 3)
		return (0);
	raw = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(line) > 5)
			return (0);
		raw = ft_strjoin(raw, line);
		i++;
		//ft_putnbr(i);
		/*
		if (validate(raw) == 0)
		{
			ft_putstr("Error somewhere.");
			return (0);
		}
		*/
		if (i % 5 == 0)
		{
			if (validate(raw) == 0)
			{
				ft_putstr("Error somewhere.");
				return (0);
			}
			i = 0;
		}
	}
	if (validate(raw) == 0)
		{
			ft_putstr("Error somewhere.");
			return (0);
		}
	solve(scan_save_tetramino(raw, pieces));
	return (0);
}
