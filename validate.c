#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"

/*
char	*validate_ascii(char *piece)
{
	int i;
	char	*fds[fd];
	int temp;

	i = 0;
	temp = 0;
	while (fds[fd][i] != '\0')
	{
		temp = temp + i;
		i++;
	}
	if (temp != 742)
		return (1);
	else
		printf("%d", temp);
	return (0);
}
*/

int		validate_nbrs(char *raw)
{
	int		i;
	int		j;
	int		ncount;
	int		sharps;

	i = 0;
	j = 0;
	ncount = 0;
	while (raw[i] != '\0')
	{
		while (j < 16)
		{
			if (raw[i + j] == '#')
				sharps++;
			j++;
		}
		if (sharps > 4)
		{
			printf("Too many sharps");
			return (0);
		}
		sharps = 0;
		j = 0;
		i += 16;
	}
	i = 0;
	while (raw[i] != '\0')
	{
		if ((raw[i] == '#') && ((i + 1) % 16 != 0))
		{
			if ((raw[i + 4] == '#') && ((i + 1) % 16 < 13))
			{
				//printf("i and modulo: %d, %d\n", i, ((i + 1) % 16));
				ncount += 2;
			}
			if (raw[i + 1] == '#')
			{
				ncount += 2;
				//printf("i: %d\n", i);
			}
			/*
			if ((raw[i + 1] == '#') && (raw[i - 1] == '#') && 
			(raw[i + 4] == '#') && (i % 16 != 0))
			{
				ncount -= 2;
				printf("i: %d\n", i);
			}
			*/
			printf("i and ncount: %d, %d\n", i + 1, ncount);
		}
		i++;
	}
	return (0);
}

int		validate(char *raw)
{
	if (validate_nbrs(raw) == 0)
		return (0);
	return (1);
}