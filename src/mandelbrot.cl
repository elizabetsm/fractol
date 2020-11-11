__kernel void	mandelbrot(__global int *img, float step_x, float step_y, int depth,
                float radius, float left_board, float top_board, int win_w, int color, char fractol)
{
	int		i = -1;
	int     gid = get_global_id(0);
	float	x, y;
	float	new_comp_x;

	x = 0;
    y = 0;
	float x_0 = left_board + step_x * (gid % win_w);
	float y_0 = top_board + step_y * (gid / win_w);

	while (++i < depth && x * x + y * y < radius)
	{
		new_comp_x = x * x - y * y + x_0;
		y = 2 * x * y + y_0;
		x = new_comp_x;
	}
	if (i < depth)
		img[gid] = color * i;
	else
		img[gid] = 0;
}
