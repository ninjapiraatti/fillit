#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

void make_list(char *tet)
{
	t_list *first;
	const char *content;
	size_t size;
	
	content = tet;
	size = ft_strlen(content);
	first = ft_lstnew(*content, size);
