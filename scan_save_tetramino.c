#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

void	ft_foreach(int *tab, int length)
{
	int i;

	i = 0;
	while (length > i)
	{
		tab[i]--;
		i++;
	}
}
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
	//printf("\ntet after move to top:\n");
	printf("%d %d %d %d\n", tet[0], tet[1], tet[2], tet[3]);
	j = 0;
	while (tet[j] % 4 != 0)
	{
		if (tet[0] == 0)
			break ;
		ft_foreach(tet, 4);
		j++;
	}
	//printf("\ntet after move to left:\n");
	//printf("%d %d %d %d\n", tet[0], tet[1], tet[2], tet[3]);
	return (tet);
}

void	ft_lstaddfront(t_list **alst, t_list *new)
{
	(*alst)->next = new;
}

void scan_save_tetramino(char *raw, t_list *pieces)
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
	//printf("tetnum:\n");
	//printf("%d\n", tetnum);
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
					//printf("%d ", tet[l]);
					l++;
					k++;
				}
				else 
					k++;
			}	
			if ((chunk[0] != '#' && chunk[1] != '#' && chunk[2] != '#' && chunk[3] != '#') || 
			(chunk[0] != '#' && chunk[4] != '#' && chunk[8] != '#' && chunk[12] != '#'))
				{
				intchunk = topleft(chunk);
				//printf("\ntet after top left %d %d %d %d \n", intchunk[0], intchunk[1], intchunk[2], intchunk[3]);
				}
			k = 0;
			ft_lstaddfront(&pieces, ft_lstnew(tet, 16));
			l = 0;
		j++;
		//printf("\n");
		}
	i++;
	}
}