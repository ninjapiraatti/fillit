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
				i++;
			}
			else
			{
				i = 0;
				pos++;
			}
		}
		//printf("Origpos: %d, Pos: %d\nGrid: \n%s\n", origpos, pos, grid);
		//getchar();
		if (pos > 169)
			return (0);
		i = 0;
		pos = origpos;
		while (i < 4)
		{
			offset = ((temp[i] / 4) * 10);
			grid[temp[i] + offset + pos] = tletter;
			i++;
		}
		if (recursion(pieces->next, 0, ++tletter, grid, gridsize) == 0)
		{
			i = 0;
			while (i < 4)
			{
				offset = ((temp[i] / 4) * 10);
				grid[temp[i] + offset + pos] = '0';
				i++;
			}
			i = 0;
			pos++;
			tletter--;
		}
		else
		{
			//printf("Next piece did fit. Current piece: %d\n", temp[3]);
			return (1);
		}
	}
	//printf("Out of pieces.\n");
	return (1);
}

int		fit_piece(char *grid, int gridsize)
{

	int			pos;
	t_list		*pieces;
	int			piece1[4] = {2, 4, 5, 6};
	int			piece2[4] = {0, 1, 2, 4};
	int			piece3[4] = {0, 4, 8, 12};
	int			piece4[4] = {0, 1, 4, 5};
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
	while (gridsize < 14)
	{
		if (recursion(pieces, pos, tletter, grid, gridsize) == 1)
			printf("RETURN 1. Grid: \n%s\n", grid);
		gridsize++;
	}
	printf("RETURN 0. Grid: \n%s\n", grid);
	return (1);
}

int		solve(char *raw)
{
	char	*grid;
	int		gridsize;

	gridsize = 1;
	raw = ft_strnew(0);
	grid = ft_strdup("0000011111111\n0000011111111\n0000011111111\n0000011111111\n0000011111111\n");
	fit_piece(grid, gridsize);
	return (0);
}
