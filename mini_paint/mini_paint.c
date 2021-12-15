#include "mini_paint.h"

int	is_in_circle(t_circle *circle, float y, float x)
{
	float	distance;

	distance = sqrtf(powf(x - circle->x, 2) + powf(y - circle->y, 2));
    if (distance <= circle->radius)
    {
        if ((circle->radius - distance) < 1.)
            return (2);
        return (1);
    }
    return (0);
}

static void	draw(t_draw_zone *draw_zone, t_circle *circle)
{
	for (int i = 0; i < draw_zone->height; i++)
	{
		for (int j = 0; j < draw_zone->width; j++)
		{
			if (circle->type == 'c' && is_in_circle(circle, (float)i, (float)j) == 2)
				draw_zone->matrice[i][j] = circle->symbol;
			if (circle->type == 'C' && is_in_circle(circle, (float)i, (float)j)) 
				draw_zone->matrice[i][j] = circle->symbol;
		}
	}
}

int	mini_paint(t_draw_zone *draw_zone, FILE *file)
{
	t_circle	circle;
	int			ret;

	ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.symbol);
	while (ret == 5)
	{
		if (circle.radius <= 0 || (circle.type != 'c' && circle.type != 'C'))
			return (1);
		draw(draw_zone, &circle);
		ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.symbol);
	}
	return (0);
}
