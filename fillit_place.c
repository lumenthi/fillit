/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtheo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:34:38 by dtheo             #+#    #+#             */
/*   Updated: 2017/12/12 14:01:15 by dtheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	fillit_check_place_all(t_list *lst, const int *pos, int size)
{
	if (!lst || !fillit_check_place(pos, (int *)(lst->content), size))
		return (0);
	if (lst->next)
		return (fillit_check_place_all(lst->next, pos, size));
	return (1);
}

static void	fillit_move_in(int *blocks, int *dx, int *dy, int size)
{
	fillit_move(blocks, 1, 0);
	(*dx)++;
	if (*dx > size - fillit_width(blocks))
	{
		fillit_move(blocks, -(*dx), 1);
		*dx = 0;
		(*dy)++;
	}
}

static int	fillit_place_next(t_list *lst, int *pos, int size)
{
	*(pos + 8) = 1;
	if (fillit_place(lst, size))
		return (1);
	*(pos + 8) = 0;
	return (0);
}

static int	fillit_all_placed(t_list *lst)
{
	if (!lst || *((int *)(lst->content) + 8) == 0)
		return (0);
	if (lst->next)
		return (fillit_all_placed(lst->next));
	return (1);
}

int			fillit_place(t_list *lst, int size)
{
	int		dx;
	int		dy;
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		dx = 0;
		dy = 0;
		if (*((int *)(curr->content) + 8) == 0)
		{
			while (dy <= size - fillit_height((int *)(curr->content)))
			{
				if (fillit_check_place_all(lst, (int *)(curr->content), size) &&
					fillit_place_next(lst, (int *)(curr->content), size))
					return (1);
				fillit_move_in((int *)(curr->content), &dx, &dy, size);
			}
			fillit_move((int *)(curr->content), -dx, -dy);
		}
		else if (curr->next == NULL && fillit_all_placed(lst))
			return (1);
		curr = curr->next;
	}
	return (0);
}
