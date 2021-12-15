#include "micro_paint.h"

int	is_in_rect(t_rectangle *rect, float y, float x)
{
	if (((x >= rect->x && x <= (rect->x + rect->width) && (y == rect->y || y == (rect->y + rect->height))))
		|| (y >= rect->y && y <= (rect->y + rect->height) && (x == rect->x || x == (rect->x + rect->width))))
		return (2);
	if (x >= rect->x && x <= (rect->x + rect->width) && y >= rect->y && y <= (rect->y + rect->height))
		return (1);
	return (0);
}

int	draw(t_draw_zone *draw_zone, t_rectangle *rect)
{
	for (int i = 0; i < draw_zone->height; i++)
	{
		for (int j = 0; j < draw_zone->width; j++)
		{
			if (rect->type == 'r' && is_in_rect(rect, (float)i, (float)j) == 2)
				draw_zone->matrice[i][j] = rect->symbol;
			if (rect->type == 'R' && is_in_rect(rect, (float)i, (float)j) != 0)
				draw_zone->matrice[i][j] = rect->symbol;
		}
	}
	return (0);
}

int	micro_paint(FILE *file, t_draw_zone *draw_zone)
{
	t_rectangle	rect;
	int			ret;

	ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.symbol);
	while (ret == 6)
	{
		if (rect.width <= 0.0f || rect.height <= 0.0 || (rect.type != 'r' && rect.type != 'R'))
			return (1);
		draw(draw_zone, &rect);
		ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.symbol);
	}
	if (ret == EOF)
		return (0);
	return (1);
}
