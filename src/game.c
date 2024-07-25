/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:24:52 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/07/25 10:40:00 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Exit the program in event of failure
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// ---- HOOKS ----

// close window on pressing ESCAPE key
static void my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE )
		exit(1);
}

void printhex(mlx_image_t *img)
{
	int side = 200;
	int va = sqrt(pow(side, 2) - pow(side/2, 2));
	int i = 0;
	int offset = 300;
	// A[100, 100], B[100 - side/2, 100 + va], C[100 + side/2, 100 + va]
	int Ax = side/2 + offset;
	int Ay = offset;
	while (i <= side)
	{
		mlx_put_pixel(img, Ax - side/2 + i, Ay - va, 0xFF0000FF);
		mlx_put_pixel(img, Ax + i/2, Ay + ((i * va) / side), 0xFF0000FF);
		mlx_put_pixel(img, Ax - i/2, Ay + ((i * va) / side), 0xFF0000FF);

		mlx_put_pixel(img, Ax - side/2 + i, Ay + va, 0x33cc33FF);
		mlx_put_pixel(img, Ax + i/2, Ay - ((i * va) / side), 0x33cc33FF);
		mlx_put_pixel(img, Ax - i/2, Ay - ((i * va) / side), 0x33cc33FF);

		mlx_put_pixel(img, Ax - side + 2*i, Ay, 0x33cc33FF);
		i++;
	}
}

int32_t	main(void)
{
	// MLX allows you to define its core behaviour before startup.
	//mlx_set_setting(MLX_MAXIMIZED, true);

	mlx_t* window;

	// 1. init creates and stores information about created window
	window = mlx_init(WIDTH, HEIGHT, "MLX Game", true);
	if (!window)
		ft_error();

	// 2. Create and display the image.
	mlx_image_t* img = mlx_new_image(window, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(window, img, 0, 0) < 0))
		ft_error();

	// 3. do what you need - display things
	render_pollock(img);

	// 4. Register hooks and pass our window as param --> do this before calling mlx_loop!
	mlx_key_hook(window, &my_keyhook, NULL);
	// 5. once mlx_loop is running, program is listening to events as mouse/keyboard clicks and can only be closed at request etc. hook for escape key
	mlx_loop(window);
	// 6. proper memory management
	mlx_delete_image(window, img);
	mlx_terminate(window);
	return (EXIT_SUCCESS);
}
