/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struf <struf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:34:26 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/17 11:22:42 by struf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	ft_check_args(argc, argv);
	ft_read_check_map(&game, argv[1]);
	ft_start_game(&game);
}

void	error_msg(t_game *game, char *msg)
{
	ft_putstr_fd(msg, 2);
	destroy_map(game);
	exit(EXIT_FAILURE);
}

int	valid_sprites(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != 'P' && game->map[y][x] != '0'
				&& game->map[y][x] != '1' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'B')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
