/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtheo <dtheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:39:01 by dtheo             #+#    #+#             */
/*   Updated: 2017/12/13 17:15:23 by dtheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fillit_strfill(int *pos, char *str, char c, int size)
{
	int		i;

	i = 0;
	if (*(pos + 8) == 0)
		return ;
	while (i < 8)
	{
		*(str + *(pos + i) + *(pos + i + 1) * (size + 1)) = c;
		i += 2;
	}
}

static void	fillit_del(void *content, size_t size)
{
	ft_memdel(&content);
	(void)size;
}

char		*fillit_tostr(t_list *lst, int size)
{
	char	*str;
	char	letter;
	int		i;

	if (!(str = ft_strnew(size * size + size)))
		return (NULL);
	ft_memset(str, '.', size * size + size);
	letter = 'A';
	while (lst && letter <= 'Z')
	{
		fillit_strfill((int *)(lst->content), str, letter, size);
		letter++;
		lst = lst->next;
	}
	i = 0;
	while (i < size)
		*(str + (size + 1) * ((i++) + 1) - 1) = '\n';
	return (str);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		size;
	t_list	*tetris;

	if (argc != 2)
	{
		ft_putendl("usage: fillit sample_file");
		return (0);
	}
	fd = open(*(argv + 1), O_RDONLY);
	if (!(tetris = fillit_reader(fd)) || ft_lstlen(tetris) > 26)
	{
		if (tetris != NULL)
			ft_lstdel(&tetris, &fillit_del);
		ft_putendl("error");
		return (0);
	}
	close(fd);
	ft_lstiter(tetris, &fillit_repos);
	size = fillit_resolve(tetris);
	ft_putstr(fillit_tostr(tetris, size));
	ft_lstdel(&tetris, &fillit_del);
	return (0);
}
