#include "fdf.h"

void	ft_srch_width(t_map *map, char **map_char)
{
	int		len;
	char	**tmp;

	len = 0;
	tmp = ft_strsplit(map_char[0], ' ');
	while (tmp[len])
		len++;
	map->width = len;
}

void	ft_crt_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->map = (int**)malloc(sizeof(int*) * map->hight);
//	map->x_map = (int**)malloc(sizeof(int*) * map->hight);
//	map->y_map = (int**)malloc(sizeof(int*) * map->hight);
//	map->z_map = (int**)malloc(sizeof(int*) * map->hight);
	while (++i < map->hight)
	{
		map->map[i] = (int*)malloc(sizeof(int) * map->width);
//		map->x_map[i] = (int*)malloc(sizeof(int) * map->width);
//		map->y_map[i] = (int*)malloc(sizeof(int) * map->width);
//		map->z_map[i] = (int*)malloc(sizeof(int) * map->width);
		j = -1;
		while (++j < map->width)
        {
			map->map[i][j] = 0;
//			map->x_map[i][j] = 0;
//			map->y_map[i][j] = 0;
//			map->z_map[i][j] = 0;
        }
	}
}

void	ft_wrt_map(t_map *map, char **map_char)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	while (++i < map->hight)
	{
		j = -1;
		tmp = ft_strsplit(map_char[i], ' ');
		while (++j < map->width)
        {
			map->map[i][j] = ft_atoi(tmp[j]);
        //    map->x_map[i][j] = j;
          //  map->y_map[i][j] = i;
            //map->z_map[i][j] = ft_atoi(tmp[j]);
        }
	}
}

void	ft_read_map(t_map *map)
{
	char	*line;
	char	*tmp;
	char	**map_char;

	tmp = ft_strdup("");
	while (1)
	{
		if (ft_get_next_line(0, &line) == 0)
			break ;
		map->hight++;
		tmp = ft_strjoin_right(tmp, "|");
		tmp = ft_strjoin_left(tmp, line);
	}
	map_char = ft_strsplit(tmp, '|');
//	free(tmp);
	ft_srch_width(map, map_char);
	ft_crt_map(map);
	ft_wrt_map(map, map_char);
}
