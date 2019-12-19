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

int		fit_piece(char *grid, int gridsize, t_list *pieces)
{

	int			pos;
	char		tletter;
	int			i;
	int			j;

	i = 0;
	j = 0;
	pos = 0;
	tletter = 'A';
	while (gridsize < 13)
	{
		if (recursion(pieces, pos, tletter, grid, gridsize) == 1)
		{
			printf("RETURN 1. Grid: \n%s\n", grid);
			return (1);
		}
		else {
			while (i < (gridsize * gridsize))
			{
				while (j < gridsize)
				{
					grid[pos] = '0';
					j++;
					pos++;
					i++;
				}
				j = 0;
				pos += 14 - gridsize;
			}
			gridsize++;
			i = 0;
			j = 0;
			pos = 0;
		}
		//printf("nGrid: \n%s\n", grid);	
	}	
	printf("RETURN 0. Grid: \n%s\n", grid);
	return (1);
}

int		solve(t_list *pieces)
{
	char	*grid;
	int		gridsize;

	gridsize = 2;
	grid = ft_strdup("0011111111111\n0011111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n1111111111111\n");
	fit_piece(grid, gridsize, pieces);
	return (0);
}
