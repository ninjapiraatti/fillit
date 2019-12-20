#include "libft/includes/libft.h"

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
				ncount += 2;
			if (raw[start + i + 1] == '#')
				ncount += 2;
		}
		i++;
	}
	if (ncount == 6 || ncount == 8)
		return (1);
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
			return (0);
		else if (validate_tetrimino(i, raw) == 0)
			return (0);
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
	if (asciicheck(raw) == 0)
		return (0);
	return (1);
}
