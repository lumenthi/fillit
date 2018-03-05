# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtheo <dtheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 09:52:31 by dtheo             #+#    #+#              #
#    Updated: 2017/12/08 10:53:23 by dtheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIBFT = ./libft
CFLAGS = -Werror -Wextra -Wall

NAME = fillit

YELLOW = '\033[33m'
BLUE = '\033[34m'
BLANK = '\033[0m'
CYAN = '\033[36m'

OBJS = main.o fillit_reader.o fillit_check.o fillit_place.o \
	   fillit_check_place.o fillit_resolve.o

.PHONY : all clean fclean re

all: $(NAME)

%.o : %.c
	@ printf "\n ~ Compiling %b%b%b..." $(YELLOW) $@ $(BLANK)
	@ $(CC) $(CFLAGS) -I $(LIBFT)/libft.h -c $<

$(NAME) : $(OBJS)
	@ printf "\n"
	@ make -C $(LIBFT)
	@ $(CC) $(OBJS) $(LIBFT)/libft.a -o $(NAME)
	@ printf "\n ~ %b%b%b compiled !\n" \
	$(BLUE) $(NAME) $(BLANK)

clean :
	@ printf " ~ Cleaning %bobject files%b...\n" $(BLUE) $(BLANK)
	@ rm -rf $(OBJS)
	@ make -C $(LIBFT) clean

fclean : clean
	@ printf " ~ Cleaning %b%b%b...\n" $(BLUE) $(NAME) $(BLANK)
	@ rm -rf $(NAME)
	@ make -C $(LIBFT) fclean

re : fclean all
