# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshapran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 18:55:28 by vshapran          #+#    #+#              #
#    Updated: 2017/03/24 18:55:32 by vshapran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker

G = gcc
FLAGS = -Wall -Wextra -Werror

SRC_NAME_P =    manipulations.c \
			   	file1.c \
				file2.c \
				file3.c \
				file4.c \
				file5.c \
				file6.c \
				file7.c \
				file8.c \
				file9.c \
				cmds_optimizer.c \
				cmds_optimizer1.c \
				cmds_optimizer2.c
OBJ_NAME_P = $(SRC_NAME_P:.c=.o)
SRC_P = $(SRC_NAME_P)
OBJ_P = $(OBJ_NAME_P)
GCFLAGS_P = -I -I./libft/

SRC_NAME_C =   	checker.c \
				checker1.c \
				checker2.c \
				checker3.c
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
SRC_C = $(SRC_NAME_C)
OBJ_C = $(OBJ_NAME_C)
GCFLAGS_C = -I -I./libft/

LIBFT = libft/libft.a

all: $(NAME_P) $(NAME_C)

$(NAME_P): $(OBJ_P)
	@make -C libft/
	$(G) $(FLAGS) $(GCFLAGS_P) -o $@ $(OBJ_P) $(LIBFT)

$(NAME_C): $(OBJ_C)
	$(G) $(FLAGS) $(GCFLAGS_C) -o $@ $(OBJ_C) $(LIBFT)

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	$(G) $(FLAGS) $(GCFLAGS_P) -o $@ -c $<

$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	$(G) $(FLAGS) $(GCFLAGS_C) -o $@ -c $<

clean:
	@make -C libft/ clean
	rm -f $(OBJ_P)
	rm -f $(OBJ_C)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME_P) $(NAME_C)

re: fclean all
	@make -C libft/ re

rmsh:
		rm *~
		rm \#*
		rm *.out
