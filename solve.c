#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"

int		fit_piece(int *piece, char *grid, char piecesign)
{
	int		i;
	int		offset;
	int		pos;
	
	i = 0;
	pos = 0;
	while (i < 4 && pos < 169)
	{
		offset = ((piece[i] / 4) * 10);
		if((grid[piece[i] + offset + pos] - 48) == 0)
		{
			//printf("Piece fits.\n");
			i++;
		}
		else
		{
			//printf("Piece don't fit.\n");
			i = 0;
			pos++;
		}
	}
	i = 0;
	while (i < 4)
	{
		offset = ((piece[i] / 4) * 10);
		grid[piece[i] + offset + pos] = piecesign;
		i++;
	}
	printf("Grid: \n%s\n", grid);
	return (1);
}

int		solve(char *raw)
{
	char	*grid;
	
	int		piece3[5] = {0, 1, 4, 5};
	int		piece2[5] = {0, 1, 2, 4};
	int		piece1[5] = {1, 4, 5, 8};
	char	piecesign;

	raw = ft_strnew(0);
	grid = ft_strdup("0000011111111\n0000011111111\n0000011111111\n0000011111111\n0000011111111\n");
	
	piecesign = 'A';
	fit_piece(piece1, grid, piecesign);
	piecesign = 'B';
	fit_piece(piece2, grid, piecesign);
	piecesign = 'C';
	fit_piece(piece3, grid, piecesign);
	return (0);
}