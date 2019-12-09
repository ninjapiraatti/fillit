#include <stdio.h> // REMOVE IT YOU DUMBASS
#include <fcntl.h>
#include "libft/includes/libft.h"
#include "fillit.h"

int	asciicheck(int *fd)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	
	while (fd[i])
	{
		while (fd[i][j] != '\0')
		{
			temp = temp + j;
			j++;
		}
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
	int fd[4][4] = {{., ., ., #}, {., ., ., #}, {., ., ., #}, {., ., ., #}, {., ., ., #}};

	asciicheck(fd);
	return (0);
}