#include "libft/includes/libft.h"
#include "fillit.h"
#include <stdio.h>

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

int		*left(int *tet)
{
	int j;

	j = 0;
	while (tet[j] % 4 != 0)
	{
		if (tet[0] == 0 || tet[1] == 4 || tet[2] == 4 || tet[2] == 8)
			break ;
		ft_foreach(tet, 4);
		j++;
	}
	return (tet);
}

int		*top(char *chunk)
{
	int i;
	int j;
	int *tet;
	int top;

	tet = ft_memalloc(16);
	i = 0;
	j = 0;
	top = 0;
	while (chunk[i++] != '\0')
	{
		if (chunk[i] == '#')
		{
			top = i / 4;
			break ;
		}
	}
	i = 0;
	while (chunk[i++] != '\0')
	{
		if (chunk[i] == '#')
			tet[j++] = i - top * 4;
	}
	j = 0;
	return (left(tet));
}

t_list	*make_list(t_list *first, t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!first)
		first = *alst;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
	return (*alst);
}

t_list	*scan_save_tetramino(char *raw, t_list *pieces)
{
	char	*chunk;
	int		tetnum;
	int		i;
	int		j;
	t_list	*first;

	i = 0;
	j = 0;
	first = NULL;
	tetnum = (ft_strlen(raw) / 16);
	while (raw[i] != '\0')
	{
		while (j < tetnum)
		{
			chunk = ft_strsub(raw, (j * 16), 16);
			pieces = make_list(first, &pieces, ft_lstnew(top(chunk), 16));
			j++;
		}
		i++;
	}
	return (pieces);
}
