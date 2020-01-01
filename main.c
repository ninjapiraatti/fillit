#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

char		*buildraw(int fd)
{
	char		buf[21];
	int			bt;
	char		*temp;
	char		*raw;
	int			i;

	bt = 0;
	i = 0;
	raw = ft_strnew(0);
	while ((bt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bt] = '\0';
		temp = ft_strjoin(raw, buf);
		free(raw);
		raw = temp;
	}
	return (raw);
}

int			main(int argc, char **argv)
{
	char	*raw;
	int		fd;
	int		i;
	t_list	*pieces;

	fd = 0;
	i = 0;
	pieces = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: fillit <filename>.\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) != 3)
		return (0);
	if ((raw = buildraw(fd)) == NULL)
		return (0);
	if (validate(raw) == 0)
	{
		ft_putstr("Error somewhere.");
		return (0);
	}
	solve(scan_save_tetramino(raw, pieces));
	return (0);
}
