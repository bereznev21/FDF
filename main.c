/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:10:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/10 22:13:57 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

int		deal_key(int key, void *param)
{
	(void)key;
	(void)param;
	//ft_putchar('X');
	if (key == 53)
		exit (0);
	//int d = 4;
	//mlx_pixel_put(mlx_ptr, win_ptr, ++d, ++d, 0xFFFFFF);
	return (0);
}

void	ft_print_sin (void *mlx_ptr, void *win_ptr)
{
	float	i;

	i = 0;
	while (i < 50)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i * 50, 250 + 50 * sin(i), 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, i * 50, 250 + 50 * cos(i), 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, i * 50, 250 + 50 * tan(i), 0xd98b00);
		mlx_pixel_put(mlx_ptr, win_ptr, i * 50, 250 + 50 * 1 / tan(i), 0xd98b90);
		i += 0.01;
	}
}
/*
void	ft_print_line(void *mlx_ptr, void *win_ptr)
{
	float	x;

	x = 0;
	while (x < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 200 + x, 300 - 2 * x, 0xFFFFFF);
		x += 0.05;
	}
}
*/
void	ft_print_map(int **map, void *mlx_ptr, void *win_ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		//printf("%s", map[i]);
		while (map[i][j])
		{
			//printf("%c", map[i][j]);
			if (map[i][j] > 0)
			{
				//printf("%d %d\n", i, j);
				mlx_pixel_put(mlx_ptr, win_ptr, j * 5 + 50, i * 5 + 50, 0xd98b90);
			}
			else
				mlx_pixel_put(mlx_ptr, win_ptr, j * 5 + 50, i * 5 + 50, 0xFFFFFF);
			j++;
		}
		j = 0;
		i++;
		//printf("\n");
	}
}

void	ft_add_line(char **map, int i, int j)
{
	(void)i;
	(void)j;
	(void)map;
	//if (i > 0)
	//	printf("")
}

void	ft_print_vertical_line(void *mlx_ptr, void *win_ptr, float i, float j, t_cam *cam)
{
	float	k;
	float	x;
	float	y;
	float	index;

	k = i;
	index = 0;
	while (index < 1)
	{
		x = j * cam->zoom;
		y = k * cam->zoom;
		mlx_pixel_put(mlx_ptr, win_ptr,
				x * cos(cam->alph) + y * sin(cam->alph) + cam->left,
				x * sin(cam->alph) + y * cos(cam->alph) + cam->top,
				0xFFFFFF);
		k += 0.01;
		index += 0.01;
	}
}

void	ft_print_gorizontal_line(void *mlx_ptr, void *win_ptr, float i, float j, t_cam *cam)
{
	float	k;
	float	x;
	float	y;
	float	index;

	k = j;
	index = 0;
	while (index < 1)
	{
		x = k * cam->zoom;
		y = i * cam->zoom;
		mlx_pixel_put(mlx_ptr, win_ptr,
				x * cos(cam->alph) + y * sin(cam->alph)+ cam->left,
				x * sin(cam->alph) + y * cos(cam->alph) + cam->top,
				0xFFFFFF);
		k += 0.01;
		index += 0.01;
	}
}

void	ft_print_line(void *mlx_ptr, void *win_ptr, t_cam *cam, t_line line_t)
{
	(void)mlx_ptr;
	(void)win_ptr;
	(void)line_t;
	(void)cam;
	float	new_x;
	float	new_y;
	float	new_z;
	
	new_x = line_t.start_x;
	new_y = line_t.start_y;
	while (new_y != line_t.end_z)
	{
		new_y = 
	}
}

void	ft_print_grid(t_map *map, void *mlx_ptr, void *win_ptr, t_cam *cam)
{
	t_line	line_t;

	ft_init_line(&line_t);
	while (++line_t.start_y < map->hight - 1)
	{
		line_t.start_x = -1;
		while (++line_t.start_x < map->width - 1)
		{
			//printf("%d %d\n", i, j);
			//ft_print_vertical_line(mlx_ptr, win_ptr, i, j, cam);
			//ft_print_gorizontal_line(mlx_ptr, win_ptr, line_t.start_y, line_t.start_x, cam);
			line_t.start_z = map->map[line_t.start_y][line_t.start_x];
			line_t.end_x = line_t.start_x + 1;
			line_t.end_y = line_t.start_y;
			line_t.end_z = map->map[line_t.end_y][line_t.end_x];
			ft_print_line(mlx_ptr, win_ptr, cam, line_t);
			line_t.end_x = line_t.start_x;
			line_t.end_y = line_t.start_y + 1;
			line_t.end_z = map->map[line_t.end_y][line_t.end_x];
			ft_print_line(mlx_ptr, win_ptr, cam, line_t);
		}
	}
	/*
	while (j < map->width)
	{
		ft_print_vertical_line(map, mlx_ptr, win_ptr, j, cam);
		j++;
	}
	while (i < map->hight)
	{
		ft_print_gorizontal_line(map, mlx_ptr, win_ptr, i, cam);
		i++;
	}
	*/
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_cam	cam;
	//t_ptr	*ptr;

	//ptr = (t_ptr*)malloc(sizeof(t_ptr));
	ft_init(&map, &cam);
	ft_read_map(&map);
	printf("%d %d\n", map.hight, map.width);
	//fd = open("test_map", O_RDON)
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	ft_print_grid(&map, mlx_ptr, win_ptr, &cam);
//	ft_print_map(map.map, mlx_ptr, win_ptr);
	//ft_print_sin(mlx_ptr, win_ptr);
	//ft_print_line(mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
