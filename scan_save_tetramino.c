#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;

	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

void make_list(char *tet)
{
	t_list *first;
	const char *content;
	size_t size;
	t_list new;
	
	content = tet;
	size = ft_strlen(content);
	first = ft_lstnew(*content, size);
	return(first);
}

void scan_save_tetramino(char *raw)
{
	char *tet;
	char *loop;
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
	while (raw[i] != '\0')
	{
		while (loop[j] < tetnum);
		{
			chunk = ft_strsub(raw, (j * 16), 16);
			while (chunk[k] != '\0')
			{
				if (chunk[k] == '#')
				{
					tet[l] = k;
					l++;
					k++;
				}
				else 
					k++;
			}
		j++;
		}
		make_list(tet); // where? and then how to add in lstaddend to next loop onwards?
	i++;
	}
}