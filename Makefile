# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 17:01:28 by phakakos          #+#    #+#              #
#    Updated: 2019/12/04 12:53:16 by phakakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME="fillit"
LIBFT="./libft"
FILLIT="./fillit_src"
FLAGS="-Wall -Wextra -Werror"
BIGO := $(shell make -C $(FILLIT) ofiles)


all : $(NAME)

$(NAME) :
	make -C $(LIBFT) re
	make -C $(FILLIT) re
	gcc $(FLAGS) -o $(NAME) $(BIGO) -L libft -I $(LIBFT) -lft
	#compile lib with the /fillit files

clean :
	make -C $(LIBFT) clean
	make -C $(FILLIT) clean

fclean : clean
	rm $(NAME)
	make -C $(LIBFT) fclean

re : fclean all
