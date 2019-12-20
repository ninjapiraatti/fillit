#include "libft/includes/libft.h"

void	print_grid(char *grid)
{
	int		i;

	i = 0;
	while (grid[i] != '\0')
	{
		while (grid[i] == '1')
			i++;
		if (grid[i] == '0')
			grid[i] = '.';
		if (grid[i] == '\n' && grid[i + 1] == '1')
			break ;
		ft_putchar(grid[i]);
		i++;
	}
	ft_putchar(grid[i]);
}
