# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 14:46:06 by phakakos          #+#    #+#              #
#    Updated: 2019/12/04 14:47:21 by phakakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c map.c
OBJECTS = main.o map.o
INC = get_next_line.h

all: $(NAME)
	
$(NAME):
	gcc -c -Wextra -Werror -Wall $(SRC) -I $(INC)
	gcc -Wall -Wextra -Werror $(OBJECTS) -o $(NAME) -L ../libft/ -lft

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

fclean : clean
#		
ofiles :
		$(BIGO)

re : fclean all
