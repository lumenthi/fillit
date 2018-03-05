/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtheo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:36:39 by dtheo             #+#    #+#             */
/*   Updated: 2017/12/12 13:58:13 by dtheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit_width(const int *blocks)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 99999;
	max = 0;
	while (i < 8)
	{
		if (*(blocks + i) > max)
			max = *(blocks + i);
		if (*(blocks + i) < min)
			min = *(blocks + i);
		i += 2;
	}
	return (max - min + 1);
}

int			fillit_height(const int *blocks)
{
	int	i;
	int	min;
	int	max;

	i = 1;
	min = 99999;
	max = 0;
	while (i < 9)
	{
		if (*(blocks + i) > max)
			max = *(blocks + i);
		if (*(blocks + i) < min)
			min = *(blocks + i);
		i += 2;
	}
	return (max - min + 1);
}

void		fillit_repos(t_list *lst)
{
	int first_x;
	int first_y;
	int	i;
	int	*blocks;

	first_x = 3;
	first_y = 3;
	i = 0;
	blocks = (int *)(lst->content);
	while (i < 8)
	{
		if (*(blocks + i) < first_x)
			first_x = *(blocks + i);
		if (*(blocks + i + 1) < first_y)
			first_y = *(blocks + i + 1);
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		*(blocks + i++) -= first_x;
		*(blocks + i++) -= first_y;
	}
	*(blocks + 8) = 0;
}

static void	fillit_blocks_fill(int *blocks, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(str + i))
	{
		if (*(str + i) == '#')
		{
			*(blocks + j) = i % 5;
			*(blocks + j + 1) = i / 5;
			j += 2;
		}
		i++;
	}
	ft_strclr(str);
}

t_list		*fillit_reader(int fd)
{
	t_list	*lst;
	char	*buffer;
	int		*blocks;

	lst = NULL;
	if (!(buffer = ft_strnew(BUF_SIZE)))
		return (NULL);
	while (read(fd, buffer, BUF_SIZE))
	{
		if (!fillit_check_blocks(buffer) || !fillit_check_links(buffer) ||
				!fillit_check_shape(buffer) ||
				!(blocks = (int *)ft_memalloc(sizeof(int) * 9)))
			return (NULL);
		fillit_blocks_fill(blocks, buffer);
		read(fd, buffer, 1);
		if (lst)
			ft_lstpush(lst, ft_lstnew(blocks, sizeof(int) * 9));
		else
			lst = ft_lstnew(blocks, sizeof(int) * 9);
	}
	if (*buffer != '\0' || !lst)
		return (NULL);
	ft_strdel(&buffer);
	ft_memdel((void **)(&blocks));
	return (lst);
}
