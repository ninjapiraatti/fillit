#ifndef FILLIT_H
# define FILLIT_H

#include "libft/includes/libft.h"
#include <fcntl.h>

typedef struct		s_tetrapak
{
	int			*tetramino;
}					t_tetrapak;

typedef	struct		s_list //taken from libft.h just so we can get a good overview in one place. Remove for submission.
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_grid
{
	// where we store the grid!
}					t_grid;

int		validate(char *raw);
int		asciicheck(char *raw);
int		solve(char *raw);
void 	scan_save_tetramino(char *raw);

# define BUFF_SIZE 21

#endif