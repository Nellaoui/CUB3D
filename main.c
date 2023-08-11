#include "cub3d.h"

int main()
{
	mlx_t* mlx = mlx_init(500, 500, "znn", true);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
