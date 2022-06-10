# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/10 10:25:59 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################OS#################################
OS = $(shell uname -s)
ifeq ($(OS),Linux)
	LFLAGS=-lXext -lX11 -lm -lz 
else
	LFLAGS=-lmlx -framework OpenGL -framework AppKit
endif
# ################COMMANDS###########################
RM = rm -rf
CC = gcc -g
CFLAG = -Wall -Wextra -Werror
# ################SRCS_Objs##########################
SRC = gnl/get_next_line.c gnl/get_next_line_utils.c \
	main.c link_list.c check_line_ber.c parse.c ft_free.c \
	check_wall.c draw_image.c init.c exit_game.c \
	key_handler.c

	
OBJ = $(addprefix obj/, $(SRC:.c=.o))
# ################LIBRARY############################
LIBRARY = libft/library/libft.a

ifeq ($(OS),Linux)
	DEFINE = -D LINUX=1
	MINILIBX = ../minilibx/libmlx_Linux.a
else
	DEFINE = -D MAC=1
	MINILIBX =
endif

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
RED='\033[0;31m'
# ###############executable##########################

NAME = ../so_long
# ###################################################

all : $(NAME)

$(NAME): library $(OBJ) 
	@ $(CC) $(OBJ) $(LIBRARY) $(DEFINE) $(MINILIBX) $(LFLAGS) $(CFLAG) -o$(NAME)

obj/%.o : src/%.c
	@ mkdir -p obj
	@ $(CC) $(CFLAG) $(DEFINE) -c $< -o $@
	@ echo ${RE}"Making the $(notdir $@)"${NC}

obj/gnl/%.o: gnl/%.c 
	@ mkdir -p obj/gnl
	@ $(CC) $(CFLAG) $(DEFINE) -c $< -o $@
	@ echo ${RE}"Making the $(notdir $@)"${NC}

library :
	@ make -C libft

clean :
	@ make clean -C libft 
	@ $(RM) $(OBJ)

fclean : clean
	@ make fclean -C libft 
	@ $(RM) $(NAME)

re : fclean all
	# ./main