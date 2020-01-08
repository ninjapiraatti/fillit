/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:55:35 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/08 17:02:42 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

int				validate(char *raw);
int				solve(t_list *pieces);
t_list			*scan_save_tetramino(char *raw, t_list *pieces);
void			print_grid(t_list *pieces, char *grid);

# define BUFF_SIZE 21

#endif
