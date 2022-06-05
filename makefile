# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 06:37:38 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/05 07:16:30 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all : 
	make -C mandatory
bonus : 
	make -C f_bonus

fclean : 
	make fclean -C f_bonus
	make fclean -C mandatory
re : fclean all