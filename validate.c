#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"

int		validate_tetrimino(int start, char *raw)
{
	int		i;
	int		ncount;

	i = 0;
	ncount = 0;
	while (i < 16)
	{
		if ((raw[start + i] == '#') && ((start + i + 1) % 16 != 0))
		{
			if ((raw[start + i + 4] == '#') && ((start + i + 1) % 16 < 13))
			{
				//printf("i and modulo: %d, %d\n", i, ((i + 1) % 16));
				ncount += 2;
			}
			if (raw[start + i + 1] == '#')
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
		}
		i++;
	}
	if (ncount == 6 || ncount == 8)
	{
		printf("VALID at ncount: %d\n", ncount);
		return (1);
	}
	printf("INVALID at ncount: %d\n", ncount);
	return (0);
}

int		validate_nbrs(char *raw)
{
	int		i;
	int		j;
	int		ncount;
	int		sharps;

	i = 0;
	j = 0;
	ncount = 0;
	sharps = 0;
	while (raw[i] != '\0')
	{
		while ((j < 16) && (raw[i + j] != '\0'))
		{
			if (raw[i + j] == '#')
				sharps++;
			j++;
		}
		if (sharps != 4)
		{
			printf("Wrong number of sharps");
			return (0);
		}
		else if (validate_tetrimino(i, raw) == 0)
		{
			return (0);
		}
		sharps = 0;
		i += j;
		j = 0;
	}
	return (1);
}

int		validate(char *raw)
{
	if (validate_nbrs(raw) == 0)
		return (0);
	return (1);
}