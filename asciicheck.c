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
		temp = temp + raw[i];
		i++;
	}

	if (temp % 692 == 0)
		printf("%d\n", temp);
	else 
	{
		printf("shit works but number not bueno\n");
		return (1);
	}
	return (0);
}
