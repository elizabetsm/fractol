# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2020/11/08 08:28:14 by efleta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libcl.a

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./include

FT_DIR		=	../libft
FT_INC_DIR	=	../libft/includes

SRC			=	cl_create_program.c	\
				cl_init.c			\
				cl_kernels.c		\
				cl_setup.c			\
				cl_utilits.c

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCS		=	-I$(INC_DIR) -I$(FT_INC_DIR)
LIBS		=	-L$(FT_DIR) -lft

CC 			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
