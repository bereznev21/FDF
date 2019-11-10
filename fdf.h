#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"

typedef struct	s_map
{
    int		width;
    int		hight;
    int		**map;
}				t_map;

typedef	struct s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptr;

typedef	struct s_line
{
	float	start_x;
	float	start_y;
	float	start_z;
	float	end_x;
	float	end_y;
	float	end_z;
}				t_line;

typedef	struct t_cam
{
	int		top;
	int		left;
	int		zoom;
	float	alph;
	float	gam;
	float	beta;
}				t_cam;

void	ft_read_map(t_map *map);

#endif
