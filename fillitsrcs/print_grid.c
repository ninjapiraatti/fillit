/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:13:45 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/08 22:18:29 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdio.h>

void	ft_lstdelfuck(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next;
	int		i;

	i = 0;
	list = *alst;
	while (list)
	{
		i++;
		next = list->next;
		del(list->content, list->content_size);
		free(list);
		list = NULL;
		list = next;
		ft_putnbr(i);
	}
	*alst = NULL;
}

void	ft_lstdelfuck2(t_list *pieces)
{
	t_list	*list;
	t_list	*next;
	int		i;

	i = 0;
	list = pieces;
	while (list)
	{
		i++;
		next = list->next;
		free(list);
		list = NULL;
		list = next;
	}
	pieces = NULL;
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
	/*
	while (pieces)
	{

	}
	*/
	//free(pieces);
	//free(pieces->next);
	//free(pieces->next->next);
	//ft_lstdelfuck(&pieces, ft_bzero);
	ft_lstdelfuck2(pieces);
	free(grid);
}
