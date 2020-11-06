all:
	gcc src/main.c -I includes/fractol.h -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o fractol
	./fractol