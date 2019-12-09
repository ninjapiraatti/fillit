/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asciicheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasalm <malasalm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:06:34 by tlouekar          #+#    #+#             */
/*   Updated: 2019/12/09 10:53:44 by malasalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // REMOVE IT YOU DUMBASS
#include <fcntl.h>
#include "libft/includes/libft.h"
#include "fillit.h"

int	asciicheck(int fd)
{
	int i;
	char	*fds[fd];
	int temp;

	i = 0;
	temp = 0;
	while (fds[fd][i] != '\0')
	{
		temp = temp + i;
		i++;
	}
	if (temp != 742)
		return (1);
	else
		printf("%d", temp);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

	asciicheck(fd = open(argv[1], O_RDONLY));
	return (0);
}