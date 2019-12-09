#include <stdio.h> // REMOVE IT YOU DUMBASS
#include <fcntl.h>
#include "libft/includes/libft.h"
#include "fillit.h"

int	asciicheck(char *fd)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	
	while (fd[i] != '\0')
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

int		main(void)
{
	char *fd = "...#...#...#...#";

	asciicheck(fd);
	return (0);
}