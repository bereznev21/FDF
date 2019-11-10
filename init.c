#include "fdf.h"

void	ft_init(t_map *map, t_cam *cam)
{
	map = (t_map *)malloc(sizeof(t_map));
	map->map = NULL;
	map->hight = 0;
	map->width = 0;
	cam->top = 150;
	cam->left = 100;
	//cam->alph = 0;
	cam->alph = 50;
	//cam->alph = 140;
	cam->beta = 0;
	cam->gam = 0;
	cam->zoom = 20;
}

void	ft_init_line(t_line *line)
{
	line->start_x = -1;
	line->start_y = -1;
	line->start_z = -1;
	line->end_x = 0;
	line->end_y = 0;
	line->end_z = 0;
}
