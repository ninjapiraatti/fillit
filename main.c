/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:06:34 by tlouekar          #+#    #+#             */
/*   Updated: 2019/12/09 15:35:52 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>


int		main(int argc, char **argv)
{
	char	*raw;
	int		fd;
	int		bt;
	char	buf[21];

	fd = 0;
	bt = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit <filename>.\n");
		return (0);
	}
	raw = ft_strnew(0);
	fd = open(argv[1], O_RDONLY);
	while ((bt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		raw = ft_strjoin(raw, buf);
	}
	printf("%s", raw);
	/*
	if (validate(argv) == 1)
		ft_putstr("A valid file.");
	else
		ft_putstr("An invalid file.");
	printf("argc: %d\n", argc);
	*/
	return (0);
}