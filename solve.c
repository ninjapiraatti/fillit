#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

int		find_place(int pos, char *grid, int *temp)
{
	int		offset;
	int		i;
	int		origpos;

	i = 0;
	origpos = 0;
	while (i < 4 && pos <= 169)
	{
		offset = ((temp[i] / 4) * 10);
		if ((grid[temp[i] + offset + pos] - 48) == 0)
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
	if (pos > 169)
		return (-1);
	return (origpos);
}

int		recursion(t_list *pieces, int pos, char tletter, char *grid)
{
	int			i;
	int			*temp;

	i = -1;
	while (pieces != NULL)
	{
		temp = pieces->content;
		if ((pos = find_place(pos, grid, temp)) < 0)
			return (0);
		while (++i < 4)
			grid[temp[i] + ((temp[i] / 4) * 10) + pos] = tletter;
		if (recursion(pieces->next, 0, ++tletter, grid) == 0)
		{
			i = -1;
			while (++i < 4)
				grid[temp[i] + ((temp[i] / 4) * 10) + pos] = '0';
			i = -1;
			pos++;
			tletter--;
		}
		else
			return (1);
	}
	return (1);
}

int		fit_piece(char *grid, int gridsize, t_list *pieces)
{
	char		tletter;
	int			i;
	int			j;

	i = -1;
	j = 0;
	tletter = 'A';
	while (gridsize < 13)
	{
		if (recursion(pieces, 0, tletter, grid) == 1)
			return (1);
		else
		{
			while (j++ < gridsize)
			{
				while ((++i % 14) < gridsize)
					grid[i] = '0';
				i += 13 - gridsize;
			}
			gridsize++;
			i = 0;
			j = 0;
		}
	}
	return (1);
}

char	*stringspectacular(char *chunk)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = "0011111111111\n0011111111111\n";
	str2 = "1111111111111\n";
	i = 8;
	chunk = ft_strjoin(str1, str2);
	while (chunk[i] > 0)
	{
		chunk = ft_strjoin(chunk, str2);
		i--;
	}
	return (chunk);
}

int		solve(t_list *pieces)
{
	char	*chunk;
	char	*grid;
	int		gridsize;

	chunk = NULL;
	grid = stringspectacular(chunk);
	gridsize = 2;
	fit_piece(grid, gridsize, pieces);
	print_grid(grid);
	return (0);
}
