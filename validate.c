#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"

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

int		validate_nbrs(char *raw)
{
	int		i;
	int		ncount;

	i = 0;
	ncount = 0;
	while (raw[i] != '\0')
	{
		if (raw[i] == '\n')
			i++;
		i++;
	}
	printf("Testpiece: %s\n", raw);
	return (0);
}

int		validate(char *raw)
{
	if (validate_nbrs(raw) == 0)
		return (0);
	return (1);
}