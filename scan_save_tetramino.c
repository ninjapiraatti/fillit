#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"#include
#include "fillit.h"

/* scan raw until the first #.
store the place number of the first # in tetcpy string.
scan the remainder of raw until the next #.
store the place number of the next # in tetcpy string.
continue until raw reaches the null terminator.
*/

void scan_save_tetramino(char *raw)

{
	tetrapak tetramino;
	char *tetcpy;
	int i;
	int j;
	int hashplace;

	i = 0;
	j = 0;
	while (raw[i] != '\0')
	{
		if (raw[i] == '#')
		{
			tetcpy[j] = i;
			j++;
			i++;
		}
		else
			i++;
	}
	tetramino.tetramino = ft_strdup(tetcpy);
}