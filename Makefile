#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/24 15:04:10 by ndauteui          #+#    #+#              #
#    Updated: 2015/12/13 17:57:17 by ndauteui         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  fillit

CC =	gcc

CFLAGS = -Wall -Wextra -Werror

LIBDIR = libft/

SRCS =	main.c \
		print.c \
		check.c \
		list.c \
		tetriminos.c \
		tetriminos2.c \
		move.c \
		parse.c \
		solve.c \
		solve2.c \
		size.c \
		up_left.c \
		element.c \
		get_next_line/get_next_line.c

OBJ =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
		make -C $(LIBDIR)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBDIR) -lft

%.o:	%.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ)
		make -C $(LIBDIR) clean

fclean:	clean
		rm -rf $(NAME)
		make -C $(LIBDIR) fclean

re:		fclean all
