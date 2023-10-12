/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:01:27 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 12:16:15 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_game *game)
{
	int	w;
	int	h;

	game->i_floor = mlx_xpm_file_to_image(game->mlx, "t/floor.xpm", &w, &h);
	game->i_wall = mlx_xpm_file_to_image(game->mlx, "t/wall.xpm", &w, &h);
	game->i_exit = mlx_xpm_file_to_image(game->mlx, "t/exit1.xpm", &w, &h);
	game->i_player[0] = mlx_xpm_file_to_image(game->mlx, "t/rato0.xpm", &w, &h);
	game->i_player[1] = mlx_xpm_file_to_image(game->mlx, "t/rato1.xpm", &w, &h);
	game->i_player[2] = mlx_xpm_file_to_image(game->mlx, "t/rato2.xpm", &w, &h);
	game->i_player[3] = mlx_xpm_file_to_image(game->mlx, "t/rato3.xpm", &w, &h);
	game->i_player[4] = mlx_xpm_file_to_image(game->mlx, "t/rato4.xpm", &w, &h);
	game->i_player[5] = mlx_xpm_file_to_image(game->mlx, "t/rato5.xpm", &w, &h);
	game->i_coin[0] = mlx_xpm_file_to_image(game->mlx, "t/coin0.xpm", &w, &h);
	game->i_coin[1] = mlx_xpm_file_to_image(game->mlx, "t/coin1.xpm", &w, &h);
	game->i_coin[2] = mlx_xpm_file_to_image(game->mlx, "t/coin2.xpm", &w, &h);
	game->i_coin[3] = mlx_xpm_file_to_image(game->mlx, "t/coin3.xpm", &w, &h);
	game->i_coin[4] = mlx_xpm_file_to_image(game->mlx, "t/coin4.xpm", &w, &h);
	game->i_coin[5] = mlx_xpm_file_to_image(game->mlx, "t/coin5.xpm", &w, &h);
	game->i_crab[0] = mlx_xpm_file_to_image(game->mlx, "t/crab0.xpm", &w, &h);
	game->i_crab[1] = mlx_xpm_file_to_image(game->mlx, "t/crab1.xpm", &w, &h);
	game->i_crab[2] = mlx_xpm_file_to_image(game->mlx, "t/crab2.xpm", &w, &h);
	game->i_crab[3] = mlx_xpm_file_to_image(game->mlx, "t/crab3.xpm", &w, &h);
	game->i_crab[4] = mlx_xpm_file_to_image(game->mlx, "t/crab4.xpm", &w, &h);
	game->i_crab[5] = mlx_xpm_file_to_image(game->mlx, "t/crab5.xpm", &w, &h);
}

void	print_img(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win_ptr, game->i_floor, x
			* IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win_ptr, game->i_wall, x
			* IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win_ptr,
			game->i_player[game->frame_player], x * IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win_ptr,
			game->i_coin[game->frame_coin], x * IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win_ptr, game->i_exit, x
			* IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'B')
		mlx_put_image_to_window(game->mlx, game->win_ptr,
			game->i_crab[game->frame_crab], x * IMG_WIDTH, y * IMG_HEIGHT);
}


void	print_moves(t_game *game)
{
	char	*movement_t;

	movement_t = ft_itoa(game->movements);
	mlx_string_put(game->mlx, game->win_ptr, 10, 10, 0x00FF00FF,
		movement_t);
	free(movement_t);
}

void	select_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			print_img(game, x, y);
			x++;
		}
		y++;
	}
	print_moves(game);
}

// int dif_sprite(t_game *game)
// {
// 	int i;

// 	i = 0;
// 	while (i < 6)
// 	{
// 		if(!game->i_player[i])
// 			return (0);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 6)
// 	{
// 		if(!game->i_coin[i])
// 			return (0);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 6)
// 	{
// 		if(!game->i_crab[i])
// 			return (0);
// 		i++;
// 	}
// 	if((!game->i_floor) || (!game->i_exit) || (!game->i_wall))
// 		return (0);
// 	return (1);
// }