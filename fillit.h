#ifndef FILLIT_H
# define FILLIT_H

#include "libft/includes/libft.h"
#include <fcntl.h>

/*
typedef struct		s_tetrapak // used in scan_save_tetramino.c
{
	int				*tetramino;

}					t_tetrapak;
*/

typedef struct		s_grid
{
	char			*grid;
	int				size;
	char			*str;

}					t_grid;

int		validate(char *raw);
int		asciicheck(char *raw);
int		solve(t_list *pieces);
t_list 	*scan_save_tetramino(char *raw, t_list *pieces);

# define BUFF_SIZE 21

#endif