#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

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
		ft_putchar(grid[i]);
		i++;
	}
}

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
			printf("grid: %s\n", grid);
		}
		else
			return (1);
	}
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
			return (1);
		else
		{
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
	}
	return (1);
}

char	*stringspectacular(char *chunk)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = "0011111111111\n";
	str2 = "1111111111111\n";
	i = 9;
	chunk = ft_strjoin(str1, str1);
	chunk = ft_strjoin(chunk, str2);
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
