#include "mini_paint.h"

int	init(t_draw_zone *draw_zone, FILE *file)
{
	if (fscanf(file, "%d %d %c\n", &draw_zone->width, &draw_zone->height, &draw_zone->background) != 3)
		return (1);
	if (draw_zone->width <= 0 || draw_zone->width > 300 || draw_zone->height <= 0 || draw_zone->height > 300)
		return (1);
	memset(draw_zone->matrice, 0, sizeof(draw_zone->matrice));
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
		write(1, "Error: argument\n", 16);
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (init(&draw_zone, file) == 1)
		return (1);
	if (mini_paint(&draw_zone, file) == 1)
		return (1);
	for (int i = 0; i < draw_zone.height; i++) {
		for (int j = 0; j < draw_zone.width; j++)
			printf("%c", draw_zone.matrice[i][j]);
		printf("\n");
	}
	return (0);
}
