#include "libft/includes/libft.h"
#include "fillit.h"

int	asciicheck(char *raw)
{
	int		i;
	int		temp;
	char	*dot;
	char	*hashtag;

	i = 0;
	temp = 0;
	dot = ft_strchr(raw, '.');
	hashtag = ft_strchr(raw, '#');
	if (!hashtag && !dot)
		return (0);
	while (raw[i] != '\0')
	{
		temp = temp + raw[i];
		i++;
	}
	if (temp % 692 == 0)
		return (1);
	else
		return (0);
	return (0);
}
