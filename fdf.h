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
	int	start_x;
	int	start_y;
	int	start_z;
	int	end_x;
	int	end_y;
	int	end_z;
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
void	ft_init_line(t_line *line);
void	ft_init(t_map *map, t_cam *cam);

#endif
