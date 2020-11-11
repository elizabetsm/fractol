__kernel void	julia(__global int *img, float step_x, float step_y, int depth,
                float radius, float left_board, float top_board, int win_w, int color, char fractol,
                float koef_x, float koef_y)
{
	int		i = -1;
	int     gid = get_global_id(0);
	float	x, y;
	float	new_comp_x;

	float x_0 = koef_x;
    float y_0 = koef_y;
	x = left_board + step_x * (gid % win_w);
	y = top_board + step_y * (gid / win_w);

	while (++i < depth && x * x + y * y < radius)
	{
		new_comp_x = x * x - y * y + x_0;
		y = 2 * x * y + koef_y + y_0;
		x = new_comp_x;
	}
	if (i < depth)
		img[gid] = color * i;
	else
		img[gid] = 0;
}
