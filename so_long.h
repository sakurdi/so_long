/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:53:34 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/26 11:29:24 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include	<stdlib.h>
# include	<mlx.h>
# include	<unistd.h>
# include	"gnl/get_next_line.h"

# define ESC_KEY 	65307
# define UP 		119
# define RIGHT		100
# define DOWN		115
# define LEFT		97

typedef struct s_sprite
{
	void	*floor;
	void	*item;
	void	*wall;
	void	*exit;
	void	*player;
	int		floor_w;
	int		floor_h;
	int		wall_w;
	int		wall_h;
	int		exit_w;
	int		exit_h;
	int		player_w;
	int		item_h;
	int		player_h;
	int		item_w;
}			t_sprites;

typedef struct s_game_data
{
	t_sprites	*textures;
	char		**map;
	void		*init_ptr;
	void		*window_ptr;
	void		*img;	
	int			items;
	int			window_h;
	int			window_l;
	int			pos_i;
	int			pos_j;
	int			step_count;
}				t_game_data;

int		ft_printf(const char *format, ...);
int		render(t_game_data *st);
int		draw_walls(t_game_data *st);
int		draw_floor(t_game_data *st);
int		draw_exit(t_game_data *st);
int		draw_player(t_game_data *st);
int		draw_item(t_game_data *st);
int		get_items(t_game_data *st);
int		move_handler(int keycode, t_game_data *st);
void	move_up(t_game_data *st);
void	move_right(t_game_data *st);
void	move_down(t_game_data *st);
void	move_left(t_game_data *st);
int		ondestroy_event(t_game_data *st);
int		close_window(int keycode, t_game_data *st);
void	get_player_pos(t_game_data *st);
void	free_images(t_game_data *st);
void	exit_game(t_game_data *st);

char	**parse_map_content(char *av, int fd, int height);
char	*ft_strdup(char *s);
char	*ft_strrchr(char *s, int c);
int		get_map_height(int fd);
int		new_fd(char *file, int prev_fd);
int		check_outer_walls(char **map, int height);
int		is_map_rectangular(char **map);
int		map_min_req(char **map);
int		is_map_filled(char **map);
int		get_row_len(char **map);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_extension(char *s);
int		check_sprites(t_game_data *st);
int		is_map_valid(t_game_data *st, int height);
int		check_players(char **map);
void	init_handler(t_game_data *st, int ac, char **av);
void	sprite_handler(t_game_data *st, int fd);
void	load_sprites(t_game_data *st);
void	struct_init(t_game_data *st, int height);
void	free_map(t_game_data *st);
void	free_sprites(t_game_data *st);

#endif