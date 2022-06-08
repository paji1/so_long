# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/08 09:25:50 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################OS#################################
OS = $(shell uname -s)
ifeq ($(OS),Linux)
	# -I/usr/local/include -Imlx_linux -O3
	CFLAGS=-lXext -lX11 -lm -lz 
else
	CFLAGS=
endif
# ################COMMANDS###########################
RM = rm -rf
CC = gcc -g
# ################SRCS_Objs##########################

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c \
	link_list_bonus.c check_line_ber_bonus.c parse_bonus.c ft_free_bonus.c \
	check_wall_bonus.c draw_image_bonus.c init_bonus.c exit_game_bonus.c \
	key_handler_bonus.c so_long_bonus.c mobs_bonus.c  enemy_bonus.c
	
OBJ = $(addprefix obj/, $(SRC:.c=.o))
# ################LIBRARY############################

LIBRARY = libft/library/libft.a

ifeq ($(OS),Linux)
	DEFINE = -D LINUX=4
	MINILIBX = ../minilibx/libmlx_Linux.a
else
	DEFINE = -D MAC=1
	MINILIBX = ../minilibx/libmlx.a
endif
# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
RED='\033[0;31m'

# ###############executable##########################

NAME = ../so_long_bonus

# ###################################################

all : $(NAME)

$(NAME): $(LIBRARY) $(OBJ) 
	@ $(CC) $(OBJ) $(LIBRARY) $(DEFINE) $(MINILIBX) $(CFLAGS) -o $(NAME)

obj/%.o : src/%.c
	@ mkdir -p obj
	@ $(CC) $(DEFINE) -c $< -o $@
	@ echo ${RE}"Making the $(notdir $@)"${NC}

obj/gnl/%.o: gnl/%.c $(LIBRARY)
	@ mkdir -p obj/gnl
	@ $(CC)  $(DEFINE) -c $< -o $@
	@ echo ${RE}"Making the $(notdir $@)"${NC}

$(LIBRARY) :
	@ make -C libft

clean :
	@ make clean -C libft 
	@ $(RM) $(OBJ)
	
fclean : clean
	@ make fclean -C libft 
	@ $(RM) $(NAME)

re : fclean all
	# ./main