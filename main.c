#include <stdio.h> // REMOVE IT YOU DUMBASS
#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>

/*
int		recursiontester(int i)
{
	if (i < 1)
		return (0);
	printf("I IS: %d\n", i);
	recursiontester(--i);
	return(0);
}
*/

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;

	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

int		main(int argc, char **argv)
{
	char	*line;
	char	*raw;
	int		fd;
	t_list	*test;
	t_list	*test2;
	t_list	*test3;
	t_list	*test4;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit <filename>.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	raw = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		raw = ft_strjoin(raw, line);
	}
	asciicheck(raw);
	validate(raw);
	solve(raw);
	test = ft_lstnew(ft_strdup("koiro"), 5);
	test2 = ft_lstnew(ft_strdup("kisse"), 5);
	test3 = ft_lstnew(ft_strdup("vales"), 5);
	test4 = ft_lstnew(ft_strdup("kylpynalle"), 11);
	ft_lstaddend(&test, test2);
	ft_lstaddend(&test, test3);
	ft_lstaddend(&test, test4);
	printf("content of 1st node of test%s", test->next->content);
	printf("content of 1st node of test%s", test->next->next->content);
	printf("content of 1st node of test%s", test->next->next->next->content);
	//printf("RECURSION TEST: %d", recursiontester(4));
	/*
	if (validate(argv) == 1)
		ft_putstr("A valid file.");
	else
		ft_putstr("An invalid file.");
	printf("argc: %d\n", argc);
	*/
	return (0);
}