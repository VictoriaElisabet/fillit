# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 10:52:00 by vgrankul          #+#    #+#              #
#    Updated: 2019/12/06 16:42:03 by phakakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c helpers.c map.c create_list.c coordinates.c
OBJECTS = main.o helpers.o map.o create_list.o coordinates.o
INC = ../libft/libft.h

all: $(NAME)
	
$(NAME):
	gcc -c -Wextra -Werror -Wall $(SRC) -I $(INC)

comp:
	make -C ../libft re
	gcc -Wall -Wextra -Werror $(OBJECTS) -o $(NAME) -L ../libft/ -lft

clean:
	rm -f $(OBJECTS)

ofiles: 
	$(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all comp
