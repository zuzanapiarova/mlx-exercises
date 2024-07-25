/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:12:29 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/07/25 17:48:19 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//EXPERIMENTING WITH FUNCTIONS TO PRINT DIFFERENT THINGS

///////////////////////////////////////     experimenting with lines and shapes     /////////////////////////////////////////////////////////////////

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

void printparabola(mlx_image_t *img)
{
	int x = -10;
	int offset = 200;
	while (x <= 10)
	{
		mlx_put_pixel(img, x + offset, (pow(x, 2)) + offset * 2, 0x33cc33FF); // sine line
		x += 0.1;
	}
}

void render_rect(mlx_image_t *img)
{
    int	offset = 100;
    int width = 400;
    int height = 200;
    int color = 0x33cc33FF;

    int	i;
    int j;

    i = offset;
    while (i < offset + height)
    {
        j = offset;
        while (j < offset + width)
            mlx_put_pixel(img, j++, i, color);
        ++i;
	}
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

///////////////////////////////////////     experimenting with blocks     /////////////////////////////////////////////////////////////////

// coloring all pixels of window white - set a defined length of pixels with memset
void setwhite(mlx_image_t *img)
{
	memset(img->pixels, 255, ((img->width) * (img->height)) * sizeof(int32_t));
	memset(img->pixels, 0, ((img->width - 200) * (img->height - 200)) * sizeof(int32_t));
}

// color all pixels of a set rectangle with random color
void render_pollock(mlx_image_t *img)
{
    int	offset = 100;
    int width = 400;
    int height = 200;

    int	i;
    int j;

    i = offset;
    while (i < offset + height)
    {
        j = offset;
        while (j < offset + width)
            mlx_put_pixel(img, j++, i, rand() % 100000000);
        ++i;
	}
}

///////////////////////////////////////     experimenting with colors     /////////////////////////////////////////////////////////////////

// a. setting up color by hex value that we get from elsewhere:

// b. creating integer from its red, green, and blue values
int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    return (red << 16 | green << 8 | blue);
}
