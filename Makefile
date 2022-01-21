# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:14:16 by spuustin          #+#    #+#              #
#    Updated: 2022/01/21 01:16:23 by linuxlite        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
CFILES = printf.c
FLAGS = -Wall -Wextra -Werror
INCL = -I ./libft/
LIB = -L ./libft -lft

all: $(NAME)

$(NAME):
	make -C ./libft re
	gcc $(FLAGS) $(INCL) $(CFILES) $(LIB) -o $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -f *.o
	
fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
re: fclean all