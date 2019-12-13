#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

t_list *make_list(char *tet)
{
	t_list *lst; //the list
	t_list *first; // the first node
	t_list *node; // a node in the list
	const char *content; //the contents of the node in the list
	size_t size; // the size of the contents of the node in the list
	t_list *new; // a new node in the list
	
	content = tet;
	size = ft_strlen(content);
	
	if (first = NULL)
		first = ft_lstnew(*content, size);
	else
	{
		if (lst)
		{
			while (lst->next)
				lst = lst->next;
			lst->next = new;
		}
			else
				lst = new;
	}
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
		j++;
		printf("\n");
		printf("\n");
		}
	//	make_list(tet); // where? and then how to add in lstaddend to next loop onwards?
	i++;
	}
}