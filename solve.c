#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

int		recursion(t_list *pieces, int pos, char tletter, char *grid, int gridsize)
{
	int			i;
	int			offset;
	int			*temp;
	int			origpos;

	i = 0;
	offset = 0;
	while (pieces != NULL)
	{
		temp = pieces->content;
		while (i < 4 && pos <= 169)
		{
			offset = ((temp[i] / 4) * 10);
			if((grid[temp[i] + offset + pos] - 48) == 0)
			{
				if (i == 0)
					origpos = pos;
				//printf("Piece fits.\n");
				//printf("Grid: \n%s\n", grid);
				i++;
			}
			else
			{
				//printf("Piece don't fit.\n");
				i = 0;
				pos++;
				// if (pos > (offset + gridsize))
				// 	pos += gridsize - offset;
			}
			//printf("Pos: \n%d\n", pos);
		}
		printf("Origpos: %d, Pos: %d\nGrid: \n%s\n", origpos, pos, grid);
		getchar();
		if (pos > 169)
		{	
			printf("Failed to fit the piece %d\n", temp[3]);
			return (0);
		}
		i = 0;
		pos = origpos;
		while (i < 4)
		{
			offset = ((temp[i] / 4) * 10);
			//printf("Writing");
			//printf("temp[i], offset, pos: %d, %d, %d\n", temp[i], offset, pos);
			grid[temp[i] + offset + pos] = tletter;
			i++;
		}
		if (recursion(pieces->next, 0, ++tletter, grid, gridsize) == 0)
		{
			//printf("Grid: \n%s\n", grid);
			i = 0;
			while (i < 4)
			{
				offset = ((temp[i] / 4) * 10);
				//printf("temp[i], offset, pos: %d, %d, %d\n", temp[i], offset, pos);
				//printf("Erasing");
				grid[temp[i] + offset + pos] = '0';
				i++;
			}
			i = 0;
			pos++;
			tletter--;
			//recursion(pieces, ++origpos, --tletter, grid, gridsize);
		}
		
		else
		{
			printf("Next piece did fit. Current piece: %d\n", temp[3]);
			return (1);
		}
		//printf("Returning 0 but why. Current piece: %d\n", temp[3]);
		//return (0); // What is this.
	}
	printf("Out of pieces.\n");
	return (1);
}

int		fit_piece(char *grid, int gridsize)
{

	int			pos;
	t_list		*pieces;
	int			piece1[4] = {2, 4, 5, 6};
	int			piece2[4] = {0, 1, 2, 4};
	int			piece3[4] = {0, 4, 8, 12};
	int			piece4[4] = {1, 2, 4, 5};
	int			piece5[4] = {0, 1, 4, 5};
	int			piece6[4] = {0, 1, 2, 3};
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
	if (recursion(pieces, pos, tletter, grid, gridsize) == 1)
	{
		//pieces = pieces->next;
		//tletter++;
		printf("Return 1. Grid: \n%s\n", grid);
		//recursion(pieces->next, pos, tletter++, grid, gridsize);
	}
	else
	{
		printf("Return 0. Grid: \n%s\n", grid);
		// reset the board, start over from pos+1?
		pos++;
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
