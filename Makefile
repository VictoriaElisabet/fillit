# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 17:01:28 by phakakos          #+#    #+#              #
#    Updated: 2019/11/29 17:06:27 by phakakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME="fillit"
LIBFT="./libft"
FILLIT="./fillit"
FLAGS="-Wall -Wextra -Werror"


all : $(NAME)

$(NAME) :
	make -C $(LIBFT) re
	#compile lib with the /fillit files

clean :
	make -C $(LIBFT) clean
	make -C $(FILLIT) clean

fclean : clean
	rm $(NAME)
	make -C $(LIBFT) fclean

re : fclean all
