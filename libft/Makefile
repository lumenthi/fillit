# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtheo <dtheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:23:08 by dtheo             #+#    #+#              #
#    Updated: 2017/12/07 10:56:28 by dtheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
INCLUDE = libft.h
CFLAGS = -Werror -Wall -Wextra -Ilibft.h -c

NAME = libft.a

GREEN = '\033[32m'
MAGENTA = '\033[35m'
BLANK = '\033[0m'
CYAN = '\033[36m'

COUNT = 0

OBJS = ft_abs.o ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_strsplit.o \
	ft_isascii.o ft_isdigit.o ft_islower.o ft_isprint.o ft_isspace.o \
	ft_isupper.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
	ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o \
	ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o \
	ft_putstr.o ft_putstr_fd.o ft_strclr.o ft_strcmp.o ft_strcpy.o \
	ft_strdel.o ft_strdup.o ft_striter.o ft_striteri.o ft_strlen.o \
	ft_strncpy.o ft_strnew.o ft_strtrim.o ft_tolower.o ft_toupper.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_memrchr.o \
	ft_strrchr.o ft_strncmp.o ft_strstr.o ft_strnstr.o ft_strequ.o \
	ft_strnequ.o ft_strmap.o ft_strmapi.o ft_strsub.o ft_strjoin.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstpush.o \
	ft_lstiter.o ft_lstmap.o ft_factorial.o ft_pow.o ft_stralloc.o \
	ft_lstlen.o

.PHONY : all clean fclean re

all : $(NAME)

%.o : %.c
	@ $(eval COUNT = $(shell echo $$(($(COUNT)+1))))
	@ printf "\n ~ Compiling %b%b%b..." $(GREEN) $@ $(BLANK)
	@ $(CC) $(CFLAGS) $<

$(NAME) : $(OBJS)
	@ ar -rcs $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ printf "\n\n ~ %b%b%b compiled ! %b(%b files)%b\n" \
	$(MAGENTA) $(NAME) $(BLANK) $(CYAN) $(COUNT) $(BLANK)

clean :
	@ printf " ~ Cleaning %bobject files%b...\n" $(MAGENTA) $(BLANK)
	@ rm -f $(OBJS)

fclean : clean
	@ printf " ~ Cleaning %b%b%b...\n" $(MAGENTA) $(NAME) $(BLANK)
	@ rm -f $(NAME)

re : fclean all
