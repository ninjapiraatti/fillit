#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

char	*topleft(char *grid)
{
	int i;
	int j;
	char *tet;

	tet = ft_memalloc(16);
	i = 0;
	j = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == 'X')
		{
			tet[j] = i;
			printf("%d ", tet[j]);
			j++;
			i++;
		}
		else 
			i++;
		if (grid[0] == 'X' || grid[1] == 'X' || grid[2] == 'X' || grid[3] == 'X')
		{
			while (grid[0] != 'X' && grid[4] != 'X' && grid[8] != 'X' && grid[12] != 'X')
			{
				tet[j] = i - 1;
				j++;
			}
		}
		while (grid[0] != 'X' && grid[1] != 'X' && grid[2] != 'X' && grid[3] != 'X')
		{
			tet[j] = i - 4;
			j++;
		}
	}
	return (tet);
}

t_list *make_list(int *tet)
{
	t_list *lst;
	
	lst = NULL;
	if (lst == NULL)
	{
		lst = ft_lstnew(tet, 4);
		//printf("lst:\n");
		//printf("%s\n", lst->content);
	}
	else
	{
		if (lst)
		{
			while (lst->next)
				lst = lst->next;
				// printf("next lst:\n");
				// printf("%s\n", lst->content);
			lst->next = ft_lstnew(tet, 4);
		}
		else
			return (lst);
	}
	// printf("final lst:\n");
	// printf("%s\n", lst->content);
	return(lst);
}

void scan_save_tetramino(char *raw)
{
	int tet[4] = {0, 0, 0, 0};
	char *chunk;
	int tetnum;
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	tetnum = (ft_strlen(raw) / 16);
	// printf("tetnum:\n");
	// printf("%d\n", tetnum);
	while (raw[i] != '\0')
	{
		while (j < tetnum)
		{
			chunk = ft_strsub(raw, (j * 16), 16);
			// printf("chunk:\n");
			// printf("%s\n", chunk);
			// printf("tet:\n");
			chunk = topleft(chunk);
			while (chunk[k] != '\0')
			{
				if (chunk[k] == '#')
				{
					tet[l] = k;
					//printf("%d ", tet[l]);
					l++;
					k++;
				}
				else 
					k++;
			}
			// printf("\n");
			k = 0;
			make_list(tet);
			l = 0;
		j++;
		// printf("\n");
		}
	i++;
	}
}