/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:49:52 by tlouekar          #+#    #+#             */
/*   Updated: 2019/12/09 15:34:44 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"

char	*validate_ascii(char *piece)
{
	int		count;

	count = 0;
	return (piece);
}

int		validate_nbrs(char *raw)
{
	int		i;
	int		ncount;

	i = 0;
	ncount = 0;
	while (raw[i] != '\0')
	{
		if (raw[i] == '\n')
			i++;
		i++;
	}
	printf("Testpiece: %s\n", raw);
	return (0);
}

int		validate(char *raw)
{
	if (validate_nbrs(raw) == 0)
		return (0);
	return (1);
}