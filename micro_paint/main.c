#include "micro_paint.h"

int	init(FILE *file, t_draw_zone *draw_zone)
{
	memset(draw_zone->matrice, 0, sizeof(draw_zone->matrice));
	if (fscanf(file, "%d %d %c\n", &draw_zone->width, &draw_zone->height, &draw_zone->background) != 3)
		return (1);
	if (draw_zone->width < 1 || draw_zone->width > 300 || draw_zone->height < 1 || draw_zone->height > 300)
		return (1);
	for (int i = 0; i < draw_zone->height; i++)
		for (int j = 0; j < draw_zone->width; j++)
			draw_zone->matrice[i][j] = draw_zone->background;
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE		*file;
	t_draw_zone	draw_zone;

	if (argc != 2)
	{
		write(1, "Error: argument", 16);
		return (1);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (init(file, &draw_zone) == 1)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (micro_paint(file, &draw_zone) == 1)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	for (int i = 0; i < draw_zone.height; i++) {
		for (int j = 0; j < draw_zone.width; j++)
			write(1, &draw_zone.matrice[i][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}
