/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struf <struf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:01:27 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 12:02:53 by struf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_game *game)
{
	int	width;
	int	height;

	game->i_floor = mlx_xpm_file_to_image(game->mlx_ptr, "textures/texture/floor.xpm", &width, &height);
	game->i_wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/texture/wall.xpm", &width, &height);
	game->i_exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/texture/exit1.xpm", &width, &height);
	game->i_player[0] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player/rato0.xpm", &width, &height);
	game->i_player[1] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player/rato1.xpm", &width, &height);
	game->i_player[2] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player/rato2.xpm", &width, &height);
	game->i_player[3] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player/rato3.xpm", &width, &height);
	game->i_player[4] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player/rato4.xpm", &width, &height);
	game->i_player[5] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player/rato5.xpm", &width, &height);
	game->i_coi[0] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin/coin0.xpm", &width, &height);
	game->i_coi[1] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin/coin1.xpm", &width, &height);
	game->i_coi[2] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin/coin2.xpm", &width, &height);
	game->i_coi[3] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin/coin3.xpm", &width, &height);
	game->i_coi[4] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin/coin4.xpm", &width, &height);
	game->i_coi[5] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin/coin5.xpm", &width, &height);
	game->i_crab[0] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/enemy/crab0.xpm", &width, &height);
	game->i_crab[1] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/enemy/crab1.xpm", &width, &height);
	game->i_crab[2] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/enemy/crab2.xpm", &width, &height);
	game->i_crab[3] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/enemy/crab3.xpm", &width, &height);
	game->i_crab[4] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/enemy/crab4.xpm", &width, &height);
	game->i_crab[5] = mlx_xpm_file_to_image(game->mlx_ptr, "textures/enemy/crab5.xpm", &width, &height);
}

void	print_img(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->i_floor, x
			* IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->i_wall, x
			* IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->i_player[game->frame_player], x * IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->i_coin[game->frame_coin], x * IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->i_exit, x
			* IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == 'B')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->i_crab[game->frame_crab], x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	print_moves(t_game *game)
{
	char	*movement_text;

	movement_text = ft_itoa(game->movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0x00FF00FF,
		movement_text);
	free(movement_text);
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

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	res;
	char			*str;

	len = ft_nblen(n);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (n < 0)
	{
		res = -n;
		str[0] = '-';
	}
	else
		res = n;
	if (res == 0)
		str[0] = '0';
	while (len && res)
	{
		len--;
		str[len] = res % 10 + '0';
		res = res / 10;
	}
	return (str);
}
