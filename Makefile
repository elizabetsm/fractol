NAME = fractol

CC = gcc

FLAGS = -Wall -Werror -Wextra

MLX_PATH = -L /usr/local/lib/ -lmlx -framework OpenGL -framework OpenCL -framework AppKit

SRC_DIR			= 		./src
INC_DIR			= 		./includes
OBJ_DIR			=		./objs
SRC				=		main.c \
						utils.c \
						mouse_events.c \
						key_events.c \
						setupkernels.c

SRCS			=		$(addprefix $(SRC_DIR)/, $(SRC))
OBJ				= 		$(SRC:.c=.o)
OBJS			=		$(addprefix $(OBJ_DIR)/, $(OBJ))
INCLUDES		=		includes/fractol.h

FT = libft/libft.a
CL = libcl/libcl.a

FT_INC_DIR = libft/
LIBFT = libft/

CL_INC_DIR = libcl/include
LIBCL = libcl/

all: libs $(NAME)

$(NAME): $(INCLUDES) $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -I $(INCLUDES) $(FT) $(CL) $(MLX_PATH) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(FLAGS)  -I $(INC_DIR) -I $(FT_INC_DIR) -I $(CL_INC_DIR) -o $@ -c $<

libs:
	@make -C $(LIBFT)
	@make -C $(LIBCL)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)
	make clean -C $(LIBCL)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(LIBCL)

re: fclean all
