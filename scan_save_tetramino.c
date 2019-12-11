#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"#include
#include "fillit.h"

/* scan raw until the first #.
store the place number of the first # in new string.
store the remainder of raw in a temp.
scan temp until the next #.
store the place number of the next # in new string.
continue scanning temp until 16 characters have been scanned.
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