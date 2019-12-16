#include <stdio.h>

int	topleft(char *grid)
{
	int i;
	int j;
	int tet[4] = {0, 0, 0, 0};

	i = 0;
	j = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == 'X')
		{
			tet[j] = i;
			printf("%d ", tet[j]);
			j++;
			i++;
		}
		else 
			i++;
		if (grid[0] == 'X' || grid[1] == 'X' || grid[2] == 'X' || grid[3] == 'X')
		{
			while (grid[0] != 'X' && grid[4] != 'X' && grid[8] != 'X' && grid[12] != 'X')
			{
				tet[j - 1];
				j++;
			}
		}
		while (grid[0] != 'X' && grid[1] != 'X' && grid[2] != 'X' && grid[3] != 'X')
		{
			tet[j - 4];
			j++;
		}
	}
	return (0);
}