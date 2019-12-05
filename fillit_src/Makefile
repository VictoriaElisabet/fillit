# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 10:52:00 by vgrankul          #+#    #+#              #
#    Updated: 2019/12/05 15:08:44 by phakakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c helpers.c map.c
OBJECTS = main.o helpers.o map.o
INC = ../libft/libft.h

all: $(NAME)
	
$(NAME):
	gcc -c -Wextra -Werror -Wall $(SRC) -I $(INC)
	gcc -Wall -Wextra -Werror $(OBJECTS) -o $(NAME) -L ../libft/ -lft

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
