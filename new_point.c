#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"

/* sets a new point on the grid */

t_point *new_point(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return(point);
}