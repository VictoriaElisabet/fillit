# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 12:30:30 by phakakos          #+#    #+#              #
#    Updated: 2019/12/04 13:10:18 by phakakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
INC = -I ../libft 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c map.c 
BIGO = main.o map.o 

all : $(NAME)

$(NAME) :
		gcc $(FLAGS) $(INC) $(SRCS) -c
#		gcc $(FLAGS) -o $(NAME) $(BIGO)

clean :
		rm -f $(BIGO)

fclean : clean
#		
ofiles :
		$(BIGO)

re : fclean all
