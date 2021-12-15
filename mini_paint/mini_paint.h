#ifndef MINI_PAINT_H
#define MINI_PAINT_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct s_draw_zone
{
	int		width;
	int		height;
	char	background;
	int		matrice[300][300];
}	t_draw_zone;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	symbol;
} t_circle;

int	mini_paint(t_draw_zone *draw_zone, FILE *file);

#endif