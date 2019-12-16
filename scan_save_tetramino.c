#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

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
			while (chunk[k] != '\0')
			{
				if (chunk[k] == '#')
				{
					tet[l] = k;
					printf("%d ", tet[l]);
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