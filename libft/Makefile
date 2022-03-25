# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 11:15:37 by kpolojar          #+#    #+#              #
#    Updated: 2022/03/25 23:20:01 by linuxlite        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = libft.a


CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

FTS = strlen strdup strcpy strncpy strcat strncat strlcat strchr \
    strrchr strstr strnstr strcmp strncmp isdigit atoi isalpha isalnum \
    isascii isprint toupper tolower memset bzero memcpy memccpy memmove \
    memchr memcmp memalloc memdel strnew strdel strclr striter striteri \
    strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa \
    putchar_fd putstr_fd putendl_fd putnbr_fd putchar putstr putendl \
    putnbr calloc lstnew foreach swap range count_if strlcpy lstdelone \
	lstdelone lstdel lstadd lstiter lstmap countdigits strndup realloc \
    get_next_line free_array sqrt lstrev strtoupper

FUNCS = $(patsubst %, ft_%, $(FTS))
OBJ = $(patsubst %, %.o, $(FUNCS))
SRC = $(patsubst %, %.c, $(FUNCS))

.PHONY: clean fclean re all
 
HEADER = ./libft.h

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) $(CFLAGS) -I$(HEADER)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all
