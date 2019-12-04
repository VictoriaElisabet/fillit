# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 14:46:06 by phakakos          #+#    #+#              #
#    Updated: 2019/12/04 17:48:34 by phakakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c map.c helpers.c
OBJECTS = main.o map.o helpers.o
INC = ../libft

all: $(NAME)
	
$(NAME):
	gcc -c -Wextra -Werror -Wall $(SRC) -I $(INC)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

fclean : clean
#		
ofiles :
		$(OBJECTS)

re : fclean all
