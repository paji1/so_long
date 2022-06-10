# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 06:37:38 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/10 10:33:03 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all : 
	@ make -C mandatory
bonus : 
	@ make -C f_bonus

clean :
	@ make clean -C mandatory
	@ make clean -C f_bonus

fclean : 
	@ make fclean -C f_bonus
	@ make fclean -C mandatory
re : fclean all