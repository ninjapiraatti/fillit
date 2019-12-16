#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"


int		fit_piece(char *grid, int gridsize)
{
	int		i;
	int		offset;
	int		pos;
	int		piece3[5] = {0, 1, 4, 5};
	int		piece2[5] = {0, 1, 2, 4};
	int		piece1[5] = {1, 4, 5, 8};
	int		*temp;

	t_list	*pieces;
	
	pieces = ft_lstnew(piece1, 4);
	ft_lstadd(&pieces, ft_lstnew(piece2, 4));
	ft_lstadd(&pieces, ft_lstnew(piece3, 4));
	i = 0;
	pos = 0;
	offset = 0;
	temp = pieces->content;
	printf("Inside the node: %d\n", temp[0]);
	while (i < 4 && (pos < 169))
	{
		offset = ((temp[i] / 4) * 10);
		if((grid[temp[i] + offset + pos] - 48) == 0)
		{
			//printf("Pieces->next->content fits.\n");
			i++;
		}
		else
		{
			//printf("Pieces->next->content don't fit.\n");
			i = 0;
			pos++;
			if (pos > (offset + gridsize))
				pos += gridsize - offset;
		}
	}
	i = 0;
	while (i < 4)
	{
		offset = ((temp[i] / 4) * 10);
		grid[temp[i] + offset + pos] = 'X';
		i++;
	}
	printf("Grid: \n%s\n", grid);
	// printf("Offet: \n%d\n", offset);
	printf("Gridsize: \n%d\n", gridsize);
	return (1);
}

int		solve(char *raw)
{
	char	*grid;
	int		gridsize;

	gridsize = 5;
	raw = ft_strnew(0);
	grid = ft_strdup("0000011111111\n0000011111111\n0000011111111\n0000011111111\n0000011111111\n");
	

	fit_piece(grid, gridsize);
	return (0);
}
