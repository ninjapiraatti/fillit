#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

int		*topleft(char *chunk)
{
	int i;
	int j;
	int *tet;
	int left;
	int top;

	tet = ft_memalloc(16);
	i = 0;
	j = 0;
	left = 0;
	top = 0;
	while (chunk[i] != '\0')
	{
		if (chunk[i] == '#')
		{
			top = i / 4;
			// printf("\nkkkk%d", top);
			break ;
		}
		i++;
	}
	i = 0;
	while (chunk[i] != '\0')
	{
		if (chunk[i] == '#')
		{
			tet[j] = i - top * 4;
			j++;
		}
		i++;
	}
	printf("\ntet after move to top:\n");
	printf("%d %d %d %d\n", tet[0], tet[1], tet[2], tet[3]);
	i = 0;
	j = 0;
	while ((chunk[0] != '#' || chunk[4] != '#' || chunk[8] != '#' || chunk[12] != '#') && (j < 4 && i < 15))
	{
		if (chunk[i] == '#')
		{
			tet[j] = tet[j] - 1;
			j++;
		}
		i++;
	}
	printf("\ntet after move to left:\n");
	printf("%d %d %d %d\n", tet[0], tet[1], tet[2], tet[3]);
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
	int	*intchunk;
	int tetnum;
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	intchunk = ft_memalloc(16);
	tetnum = (ft_strlen(raw) / 16);
	printf("tetnum:\n");
	printf("%d\n", tetnum);
	while (raw[i] != '\0')
	{
		while (j < tetnum)
		{
			chunk = ft_strsub(raw, (j * 16), 16);
			printf("chunk:\n");
			printf("%s\n", chunk);
			printf("tet:\n");
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
			if ((chunk[0] != '#' && chunk[1] != '#' && chunk[2] != '#' && chunk[3] != '#') || 
			(chunk[0] != '#' && chunk[4] != '#' && chunk[8] != '#' && chunk[12] != '#'))
				intchunk = topleft(chunk);
			printf("\n");
			printf("INTCHUNKNKNK: %d %d %d %d \n", intchunk[0], intchunk[1], intchunk[2], intchunk[3]);
			k = 0;
			make_list(tet);
			l = 0;
		j++;
		printf("\n");
		}
	i++;
	}
}