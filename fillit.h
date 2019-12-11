#ifndef FILLIT_H
# define FILLIT_H

#include "libft/includes/libft.h"
#include <fcntl.h>

typedef struct		tetrapak
{
	int			*tetramino;
	int			piece;
}					tetrapak;

int		validate(char *raw);
int		asciicheck(char *raw);
int		solve(char *raw);
void 	scan_save_tetramino(char *raw);

# define BUFF_SIZE 21

#endif