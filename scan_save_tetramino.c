#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

/* scan raw until the first #.
store the place number of the first # in tetcpy string.
scan the remainder of raw until the next #.
store the place number of the next # in tetcpy string.
continue until raw reaches the null terminator.
*/

void scan_save_tetramino(char *raw)
{
	char *tet; // string stored in tetpack
	int i; // raw index
	int j; // tet index
	int k; // chunk of raw index

	i = 0;
	j = 0;
	k = 0;
	while (k < 16) // takes 16 chars from raw then ...
	{
		while (raw[i] != '\0')
		{
			if (raw[i] == '#') //if there's a #, set the value of tet's char to it's number on the grid.
			{
				tet[j] = i;
				j++;
				i++;
			}
			else // otherwise just keep scanning the chunk until a # is found or the chunk ends
				i++;
		}
		k++;
	}
	make_list(tet);

	k = 0;
	
}