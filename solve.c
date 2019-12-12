#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"

int		solve(char *raw)
{
	char	*grid;
	int		i;
	int		offset;
	int		pos;
	int		piece1[5] = {0, 1, 4, 5};
	//int		piece2[5] = {0, 1, 2, 4};
	//int		piece3[5] = {1, 4, 5, 8};

	i = 0;
	pos = 0;
	raw = ft_strnew(0);
	grid = ft_strdup("0011111111111001111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	
	while (i < 4)
	{
		offset = ((piece1[i] / 4) * 9);
		if((grid[piece1[i] + offset + pos] - 48) == 0)
			printf("Piece fits.\n");
		else
			printf("Piece don't fit.\n");
		i++;
	}
	return (0);
}