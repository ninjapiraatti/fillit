/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:13:45 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/08 17:11:43 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	ft_lstdelfuck(t_list *alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next;

	list = alst;
	while (list)
	{
		next = list->next;
		del(list->content, list->content_size);
		free(list);
		list = NULL;
		list = next;
	}
	alst = NULL;
}

void	print_grid(t_list *pieces, char *grid)
{
	int		i;

	i = 0;
	while (grid[i] != '\0')
	{
		while (grid[i] == '1')
			i++;
		if (grid[i] == '0')
			grid[i] = '.';
		if (grid[i] == '\n' && grid[i + 1] == '1')
			break ;
		ft_putchar(grid[i]);
		i++;
	}
	free(pieces);
	//free(pieces->next);
	ft_lstdelfuck(pieces, ft_bzero);
	free(grid);
}
