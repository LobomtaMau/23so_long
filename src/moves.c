/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:46:56 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 15:55:31 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_key(t_game *game, int keycode, int *new_x, int *new_y)
{
	*new_x = game->player_x;
	*new_y = game->player_y;
	if (keycode == 119 || keycode == 65362)
		(*new_y)--;
	else if (keycode == 97 || keycode == 65361)
		(*new_x)--;
	else if (keycode == 115 || keycode == 65364)
		(*new_y)++;
	else if (keycode == 100 || keycode == 65363)
		(*new_x)++;
	else if (keycode == 65307)
	{
		close_window(game);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	valid_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectibles--;
		else if (game->map[new_y][new_x] == 'E' && game->collectibles > 0)
			return (0);
		return (1);
	}
	return (0);
}

void	handle_win_or_lose(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collectibles == 0)
	{
		ft_putstr_fd("YOU MEGA WIN!\n", 1);
	}
	else if (game->map[game->player_y][game->player_x] == 'B')
	{
		ft_putstr_fd("YOU JA FOSTE BIG L\n", 1);
	}
	close_window(game);
	exit(EXIT_SUCCESS);
}

int	ft_key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (valid_key(game, keycode, &new_x, &new_y) && valid_move(game, new_x,
			new_y))
	{
		game->movements++;
		ft_printf("Movements: %d\n", game->movements);
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		if (game->map[game->player_y][game->player_x] == 'E'
			&& game->collectibles == 0)
			handle_win_or_lose(game);
		else if (game->map[game->player_y][game->player_x] == 'B')
			handle_win_or_lose(game);
		game->map[game->player_y][game->player_x] = 'P';
		select_img(game);
	}
	return (0);
}

void	destroy_img(void *mlx_ptr, void **image_array, int array_size)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		if (image_array[i] != NULL)
		{
			mlx_destroy_image(mlx_ptr, image_array[i]);
			image_array[i] = NULL;
		}
		i++;
	}
}
