__kernel void	mandelbrot(__global int *img, float step_x, float step_y, int depth,
                float radius, float left_board, float top_board, int win_w)
{
	int		i = -1;
	int     gid = get_global_id(0);
	float	x, y;
	float	new_comp_x, comp_x, comp_y;

	x = left_board + step_x * (gid % win_w);
	y = top_board + step_y * (gid / win_w);
	comp_x = 0.0f;
	comp_y = 0.0f;

	while (++i < depth && comp_x * comp_x + comp_y * comp_y < radius)
	{
		new_comp_x = comp_x * comp_x - comp_y * comp_y + x;
		comp_y = 2 * comp_x * comp_y + y;
		comp_x = new_comp_x;
	}
	img[gid] = 12412345;
	if (i < depth)
		img[gid] = 10000 * i;
	else
		img[gid] = 11352;
}
