#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

int		recursion(t_list *pieces, int pos, char tletter, char *grid, int gridsize)
{
	int			i;
	int			offset;
	int			*temp;

	i = 0;
	offset = 0;
	if (pieces != NULL)
	{
		temp = pieces->content;
		while (i < 4 && pos < 169)
		{
			offset = ((temp[i] / 4) * 10);
			if((grid[temp[i] + offset + pos] - 48) == 0)
			{
				//printf("Piece fits.\n");
				printf("Grid: \n%s\n", grid);
				i++;
			}
			else
			{
				//printf("Piece don't fit.\n");
				i = 0;
				pos++;
				if (pos > (offset + gridsize))
					pos += gridsize - offset;
			}
		}
		if (pos > 169)
		{
			printf("Failed to fit the piece");
			return (0);
		}
		i = 0;
		while (i < 4)
		{
			offset = ((temp[i] / 4) * 10);
			//printf("temp[i], offset, pos: %d, %d, %d\n", temp[i], offset, pos);
			grid[temp[i] + offset + pos] = tletter;
			i++;
		}
		pieces = pieces->next;
		return (1);
	}
	//recursion(pieces, pos++, tletter, grid, gridsize);
	return (0);
}

int		fit_piece(char *grid, int gridsize)
{
	
	int			pos;
	t_list		*pieces;
	int			piece1[4] = {0, 1, 4, 5};
	int			piece2[4] = {0, 1, 2, 4};
	int			piece3[4] = {1, 4, 5, 8};
	int			piece4[4] = {0, 1, 4, 5};
	int			piece5[4] = {0, 1, 2, 4};
	int			piece6[4] = {0, 1, 4, 5};
	char		tletter;
	int			i;

	i = 0;
	pieces = ft_lstnew(piece1, 16);
	ft_lstadd(&pieces, ft_lstnew(piece2, 16));
	ft_lstadd(&pieces, ft_lstnew(piece3, 16));
	ft_lstadd(&pieces, ft_lstnew(piece4, 16));
	ft_lstadd(&pieces, ft_lstnew(piece5, 16));
	ft_lstadd(&pieces, ft_lstnew(piece6, 16));
	pos = 0;
	tletter = 'A';
	while (grid[i] != '\0')
	{
		if (recursion(pieces, pos, tletter, grid, gridsize) == 1)
		{
			tletter++;
			//pieces = pieces->next;
			recursion(pieces, pos, tletter, grid, gridsize);
		}
		else
		{
			
		}
	}
	//printf("Inside the node: %d, %d, %d, %d\n", &pieces->next->content[0], &pieces->next->content[1], &pieces->next->content[2], &pieces->next->content[3]);
	//printf("Inside the node: %d, %d, %d, %d\n", temp[0], temp[1], temp[2], temp[3]);
	
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
