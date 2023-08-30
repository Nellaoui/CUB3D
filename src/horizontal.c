// void	casting(t_cub3d *mlx , double ray_angle, int cloumn	,t_ray *s)
// {
// 	(void)cloumn;
// 	// ft_absolute_angle(ray_angle);
// 	float	x_inter = 0;
// 	float	y_inter = 0;
// 	float	x_step = 0;
// 	float	y_step = 0;
// 	int	right = 0;
// 	int	down = 0;
// 	int	left = 0;
// 	int	up = 0;
// 	s->hor_wall_hit_x = 0;
// 	s->hor_wall_hit_y = 0;

// 	s->horizantal_founded = false;
// 	s->distance = 0;
// 	if (ray_angle > 0 && ray_angle < M_PI)
// 		down = true;
// 	up = !down;
// 	if (ray_angle < M_PI_2 || ray_angle > (3 * M_PI_2))
// 		right = true;
// 	left = !right;
// 	if (down)
// 		y_inter = round((mlx->player->y  / TILE_SIZE) + 1) * TILE_SIZE;
// 	else if (up)
// 	{
// 		y_inter = round((mlx->player->y  / TILE_SIZE)) * TILE_SIZE;
// 		y_inter--;
// 	}
// 	x_inter = mlx->player->x + (y_inter - mlx->player->y) / tan(ray_angle);
// 	y_step = TILE_SIZE;
// 	if (up)
// 		y_step *= (-1);
// 	x_step = TILE_SIZE / tan(ray_angle);
// 	if (left && x_step > 0)
// 		x_step *= -1;
// 	if (right && x_step < 0)
// 		x_step *= -1;


// 	float nexthorzx = x_inter;
// 	float nexthorzy = y_inter;
// 	// if (up)
// 	// 	nexthorzy--;

// 	while (nexthorzx >= 0 && nexthorzx <= mlx->tile_x * mlx->colons && nexthorzy >= 0 && nexthorzy <= s->next_horzintal_y <= mlx->tile_y * mlx->rows)
// 	{
// 		// printf("--------hor-------\n");
// 		// printf("%f\n", nexthorzx);
// 		// printf("%f\n", nexthorzy);
// 		// printf("%f\n", x_step);
// 		// printf("%f\n", y_step);
// 		// printf("-------------------\n");
// 		if (ft_wall_here_a(nexthorzx, nexthorzy, mlx))
// 		{
// 			s->horizantal_founded = true;
// 			s->hor_wall_hit_x = nexthorzx;
// 			s->hor_wall_hit_y = nexthorzy;
// 			break;
// 		}
// 		else
// 		{
// 			nexthorzx += x_step;
// 			nexthorzy += y_step;
// 		}
// 	}



// if (ray_angle > 0 && ray_angle < M_PI)
// 		down = true;
// 	up = !down;
// 	if (ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI))
// 		right = true;
// 	left = !right;
// 	y_inter = round((mlx->player->y  / TILE_SIZE)) * TILE_SIZE;
// 	if (down)
// 		y_inter += TILE_SIZE;
// 	x_inter = mlx->player->x + (y_inter - mlx->player->y) / tan(ray_angle);
// 	y_step = TILE_SIZE;
// 	if (up)
// 		y_step *= (-1);
// 	x_step = TILE_SIZE / tan(ray_angle);
// 	if (left && x_step > 0)
// 		x_step *= -1;
// 	if (right && x_step < 0)
// 		x_step *= -1;
