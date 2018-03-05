/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_check_place.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumenthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:36:13 by lumenthi          #+#    #+#             */
/*   Updated: 2017/12/12 14:31:51 by dtheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	fillit_check_border(const int *blocks, int size)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (blocks[i] >= size || blocks[i + 1] >= size)
			return (1);
		i += 2;
	}
	return (0);
}

static int	fillit_check_inter(const int *place, const int *piece)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (piece[j] == place[i] && piece[j + 1] == place[i + 1])
				return (1);
			j += 2;
		}
		i += 2;
	}
	return (0);
}

int			fillit_check_place(const int *place, const int *piece, int size)
{
	if (piece[8] == 1 && fillit_check_inter(place, piece))
		return (0);
	if (fillit_check_border(place, size))
		return (0);
	return (1);
}
