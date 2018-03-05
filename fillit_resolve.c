/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtheo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:04:37 by dtheo             #+#    #+#             */
/*   Updated: 2017/12/08 10:37:33 by dtheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fillit_move(int *blocks, const int xoff, const int yoff)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		*(blocks + i++) += xoff;
		*(blocks + i++) += yoff;
	}
}

static int	fillit_sqrt(int n)
{
	int		r;

	r = 1;
	while (r * r < n)
		r++;
	return (r);
}

static int	fillit_check_overline(t_list *lst, int size)
{
	int		*blocks;
	int		i;

	if (lst == NULL)
		return (1);
	blocks = (int *)(lst->content);
	i = 1;
	while (i < 8)
	{
		if (*(blocks + i) >= size - 1)
			return (0);
		i += 2;
	}
	return (fillit_check_overline(lst->next, size));
}

int			fillit_resolve(t_list *lst)
{
	int		size;

	size = fillit_sqrt((ft_lstlen(lst) * 4) + 1);
	while (!fillit_place(lst, size))
		size++;
	if (fillit_check_overline(lst, size))
	{
		ft_lstiter(lst, &fillit_repos);
		size--;
		while (!fillit_place(lst, size))
			size++;
	}
	return (size);
}
