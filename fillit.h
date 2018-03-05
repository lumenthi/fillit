/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumenthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:35:34 by lumenthi          #+#    #+#             */
/*   Updated: 2017/12/12 13:13:58 by dtheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <fcntl.h>
# include "./libft/libft.h"
# define BUF_SIZE 20

int		fillit_check_blocks(const char *str);
int		fillit_check_links(const char *str);
int		fillit_check_shape(const char *str);
void	fillit_repos(t_list *lst);
int		fillit_check_place(const int *place, const int *piece, int size);
void	fillit_move(int *blocks, int xoff, int yoff);
int		fillit_place(t_list *lst, int size);
int		fillit_resolve(t_list *lst);
char	*fillit_tostr(t_list *lst, int size);
int		fillit_width(const int *blocks);
int		fillit_height(const int *blocks);
t_list	*fillit_reader(int fd);

#endif
