/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:54 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/17 11:29:02 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1000

# define IMG_WIDTH 64
# define IMG_HEIGHT 64

typedef struct s_game
{
	char	**map;
	int		map_columns;
	int		map_rows;
	int		player;
	int		exit;
	int		collectibles;
	int		player_x;
	int		player_y;
	int		crab_x;
	int		crab_y;
	int		movements;
	void	*mlx;
	void	*win_ptr;
	void	*i_player[6];
	void	*i_floor;
	void	*i_wall;
	void	*i_coin[6];
	void	*i_exit;
	void	*i_crab[6];
	int		frame_rot;
	int		frame_delay;
	int		frame_player;
	int		frame_crab;
	int		frame_coin;
}			t_game;

//Main & checks
void		ft_check_args(int argc, char **argv);
void		ft_read_check_map(t_game *game, char *map_file);
int			ft_is_rectangular(t_game *game);
int			ft_is_surrounded_by_walls(t_game *game);
int			ft_has_valid_elements(t_game *game);
void		ft_handle_error(t_game *game);
int			ft_valid_path(t_game *game);
void		ft_flood_fill(char **map_tmp, int x, int y, int *counter);
void		ft_start_game(t_game *game);
void		destroy_map(t_game *game);
void		error_msg(t_game *game, char *msg);

//Textures
void		load_texture(t_game *game);
void		print_img(t_game *game, int x, int y);
void		select_img(t_game *game);
int			render_game(t_game *game);
void		frame_rot(t_game *game);
void		print_moves(t_game *game);
void		destroy_img(void *mlx_ptr, void **image_array, int array_size);
int			valid_sprites(t_game *game);

//Hooks
int			ft_key_hook(int keycode, t_game *game);
int			valid_move(t_game *game, int new_x, int new_y);
int			close_window(t_game *game);
int			valid_key(t_game *game, int keycode, int *new_x, int *new_y);
void		handle_win_or_lose(t_game *game);

//Utils
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*get_next_line(int fd);
char		*ft_append_strs(char **s1, const char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlcat(char *dest, const char *src, size_t dest_size);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_printf(const char *type, ...);
void		ft_putdigit(long long int n, int base, int *len);
char		*ft_itoa(int n);

#endif