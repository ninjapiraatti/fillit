#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

void	free_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		ft_memdel((void*)&(grid->str));
		i++;
	}

}