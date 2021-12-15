#ifndef MICRO_PAINT_H
#define MICRO_PAINT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_draw_zone
{
	int		width;
	int		height;
	char	background;
	int		matrice[300][300];
}	t_draw_zone;

typedef struct s_rectangle
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	symbol;
}	t_rectangle;

int	micro_paint(FILE *file, t_draw_zone *draw_zone);

#endif