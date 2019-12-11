#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"#include
#include "fillit.h"

/* scan raw until the first #.
store the place number of the first # in tetramino string.
scan the remainder of raw until the next #.
store the place number of the next # in tetramino string.
continue until raw reaches the null terminator.
*/

void scan_save_tetramino(char *raw)

{
	char *tetramino;
	int i;
	int j;
	int hashplace;

	i = 0;
	j = 0;
	while (raw[i] != '\0')
	{
		if (raw[i] == '#')
		{
			tetramino[j] = i;
			j++;
			i++;
		}
		else
			i++;
	}
	ft_strdup(tetramino);
}