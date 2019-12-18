#include <stdio.h> // REMOVE IT YOU DUMBASS
#include <fcntl.h>
#include "libft/includes/libft.h"
#include "fillit.h"

int	asciicheck(char *raw)
{
	int i;
	int temp;
	char *period;
	char *hashtag;

	i = 0;
	temp = 0;
 	period = ft_strchr(raw, '.');
	hashtag = ft_strchr(raw, '#');
	if (!hashtag && !period)
	{
		//printf("file is not valid: characters other than '.' and '#'\n");
		return (1);
	}
	while (raw[i] != '\0')
	{	
		temp = temp + raw[i];
		i++;
	}

	if (temp % 692 == 0)
	{
		//printf("success! total sum of ascii values:\n");
		//printf("%d\n", temp);
	}
	else 
	{
		//printf("not a success: sum of ascii values is not divisible by 692\n");
		return (1);
	}
	return (0);
}
