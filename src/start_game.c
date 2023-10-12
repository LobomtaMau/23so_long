/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struf <struf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:00:58 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 11:37:52 by struf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_start_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_putstr_fd("Error: MiniLibX initialization failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_columns * 64,
			game->map_rows * 64, "so_long");
	if (!game->win_ptr)
	{
		ft_putstr_fd("Error: Failed to create window.\n", 2);
		exit(EXIT_FAILURE);
	}
	load_texture(game);
	select_img(game);
	game->movements = 0;
	mlx_hook(game->win_ptr, 17, 1L << 17, close_window, game);
	mlx_key_hook(game->win_ptr, ft_key_hook, game);
	mlx_loop_hook(game->mlx_ptr, render_game, game);
	mlx_loop(game->mlx_ptr);
}

void	frame_rot(t_game *game)
{
	if (game->frame_coin < 5)
		game->frame_coin++;
	else
		game->frame_coin = 0;
	if (game->frame_player < 5)
		game->frame_player++;
	else
		game->frame_player = 0;
	if (game->frame_crab < 5)
		game->frame_crab++;
	else
		game->frame_crab = 0;
}

int	render_game(t_game *game)
{
	if (game->frame_delay < 50)
	{
		usleep(2000);
		game->frame_delay++;
		return (0);
	}
	else
		game->frame_delay = 0;
	frame_rot(game);
	select_img(game);
	return (0);
}
