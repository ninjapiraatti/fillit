#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"

int		solve(char *raw)
{
	char	*grid;
	int		i;
	int		piece1[5] = {0, 1, 4, 5};
	int		piece2[5] = {0, 1, 2, 4};
	int		piece3[5] = {1, 4, 5, 8};

	i = 0;
	raw = ft_strnew(0);
	grid = ft_strdup("0011111111111001111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	

	while (i < 4)
	{
		printf("block values at piecex[%d] in pieces: %d, %d, %d.", i, piece1[i], piece2[i], piece3[i]);
		i++;
	}
	return (0);
}