/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:12:29 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/07/23 12:52:59 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//EXPERIMENTING WITH FUNCTIONS TO PRINT DIFFERENT THINGS

// a. print line - set each point ny its coordinates
void printlines(mlx_image_t* img)
{
	int a = 90;
	int b = 180;

	while (a <= b)
	{
		// blue diagonal
		mlx_put_pixel(img, a, a, 0x0000FFFF);
		// red horizontal line
		mlx_put_pixel(img, a, b, 0xFF0000FF);
		// green vertical line
		mlx_put_pixel(img, b, a, 0x00FF00FF);
		a++;
	}
}
// b. print square
void printsquare(mlx_image_t* img)
{
	int a = 90;
	int start = 90;
	int end = 180;

	while (a <= end)
	{
		mlx_put_pixel(img, a, start, 0x33cc33FF); //top line
		mlx_put_pixel(img, start, a, 0x33cc33FF); //left side
		mlx_put_pixel(img, end, a, 0x33cc33FF); // right side
		mlx_put_pixel(img, a, end, 0x33cc33FF); //bottom line
		a++;
	}
}

void printcircle(mlx_image_t *img)
{
	double angle = 0;
	int r = 100;
	while (angle <= M_PI * 2)
	{
		double x = cos(angle) * r + 200;
		double y = sin(angle)* r + 200;
		mlx_put_pixel(img, x, y, 0x33cc33FF);
		angle += 0.01;
	}
}

void printtriangle(mlx_image_t *img)
{
	int side = 600;
	int va = 100; //sqrt(pow(side, 2) - pow(side/2, 2));
	int i = 0;
	// A[100, 100], B[100 - side/2, 100 + va], C[100 + side/2, 100 + va]
	int Ax = side/2 + 100;
	int Ay = 100;
	while (i <= side)
	{
		mlx_put_pixel(img, Ax - side/2 + i, Ay + va, 0x33cc33FF);
		mlx_put_pixel(img, Ax + i/2, Ay + ((i * va) / side), 0x33cc33FF);
		mlx_put_pixel(img, Ax - i/2, Ay + ((i * va) / side), 0x33cc33FF);
		i++;
	}
}

void printsine(mlx_image_t *img)
{
	double angle = 0;
	int r = 100;
	int topoffset = 200;
	while (angle <= M_PI * 2)
	{
		double x = angle * r;
		double y = sin(-angle)* r + topoffset;
		mlx_put_pixel(img, x, 0 + topoffset, 0xFF0000FF); // horizontal line at y = 0
		mlx_put_pixel(img, x, y, 0x33cc33FF); // sine line
		angle += 0.001;
	}
}

void printfullsquare(mlx_image_t* img)
{
	int a = 90;
	int start = 90;
	int end = 180;

	while (a <= end)
	{
		mlx_put_pixel(img, a, end, 0x33cc33FF); //top line
		mlx_put_pixel(img, start, a, 0x33cc33FF); //left side
		a++;
	}
}

// c. coloring all pixels of window white - set a defined length of pixels with memset
void setwhite(mlx_image_t *img)
{
	memset(img->pixels, 255, ((img->width) * (img->height)) * sizeof(int32_t));
}
