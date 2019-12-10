#include <stdio.h> // REMOVE IT YOU DUMBASS
#include <fcntl.h>
#include "libft/includes/libft.h"
#include "fillit.h"

int	asciicheck(char *raw)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	
	while (raw[i] != '\0')
	{	
		temp = temp + ft_atoi((const char*)raw);
		i++;
	}

	if (temp != 742)
		return (1);
	else
		printf("%d", temp);
	return (0);
}