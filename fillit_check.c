/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumenthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:38:43 by lumenthi          #+#    #+#             */
/*   Updated: 2017/12/11 13:22:00 by lumenthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit_check_blocks(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}

int		fillit_check_links(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
			if (str[i - 1] == '#')
				count++;
			if (str[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		fillit_check_shape(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (!((i + 1) % 5 == 0))
				return (0);
		}
		else if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return (i == BUF_SIZE ? 1 : 0);
}
