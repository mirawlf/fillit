# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wstygg <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 11:40:46 by wstygg            #+#    #+#              #
#    Updated: 2019/07/09 12:39:26 by wstygg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= ./src/map.c ./src/list.c ./src/fillit.c ./src/is_normal.c ./src/settle.c

OBJ= $(SRC:.c=.o)

INCLUDE = ./includes

CC= gcc

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
