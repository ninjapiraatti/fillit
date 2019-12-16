#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

int		fit_piece(char *grid, int gridsize)
{
	int			i;
	int			offset;
	int			pos;
	t_list		*pieces;
	int			piece1[4] = {0, 1, 4, 5};
	int			piece2[4] = {0, 1, 2, 4};
	int			piece3[4] = {1, 4, 5, 8};
	int			*temp;
	char		tletter;

	pieces = ft_lstnew(piece1, 16);
	ft_lstadd(&pieces, ft_lstnew(piece2, 16));
	ft_lstadd(&pieces, ft_lstnew(piece3, 16));
	i = 0;
	pos = 0;
	offset = 0;
	tletter = 'A';
	temp = pieces->content;
	//printf("Inside the node: %d, %d, %d, %d\n", &pieces->next->content[0], &pieces->next->content[1], &pieces->next->content[2], &pieces->next->content[3]);
	//printf("Inside the node: %d, %d, %d, %d\n", temp[0], temp[1], temp[2], temp[3]);
	while (pieces != NULL)
	{
		temp = pieces->content;
		while (i < 4 && pos < 169)
		{
			offset = ((temp[i] / 4) * 10);
			if((grid[temp[i] + offset + pos] - 48) == 0)
			{
				// printf("Piece fits.\n");
				i++;
			}
			else
			{
				// printf("Piece don't fit.\n");
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
			// printf("temp[i], offset, pos: %d, %d, %d\n", temp[i], offset, pos);
			grid[temp[i] + offset + pos] = tletter;
			i++;
		}
		i = 0;
		pieces = pieces->next;
		tletter++;
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
