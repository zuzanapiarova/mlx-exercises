/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:18:45 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/07/25 17:44:30 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
# define EXAMPLE_H

#include "../MLX42/include/MLX42/MLX42.h" //minilibx
#include <stdlib.h> // malloc free
#include <unistd.h> // write
#include <stdio.h> // printf
#include <string.h> // memset
#include <math.h> // math functions

# define ERROR_MESSAGE = "Not valid input"
# define HEIGHT 800
# define WIDTH 800

// structs used

typedef struct s_data
{
    void	*win_ptr;
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

// utils
static void ft_error(void);

// experiment functions
void printlines(mlx_image_t* img);
void printsquare(mlx_image_t* img);
void printcircle(mlx_image_t *img);
void printtriangle(mlx_image_t* img);
void printfullsquare(mlx_image_t* img);
void setwhite(mlx_image_t *img);
void printsine(mlx_image_t *img);
void printparabola(mlx_image_t *img);

void render_rect(mlx_image_t *img);
void render_pollock(mlx_image_t *img);

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue);

#endif
