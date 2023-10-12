/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struf <struf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:33:38 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 11:48:23 by struf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv)
{
	char		*map_file;
	int			map_file_len;
	const char	*extension;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Incorrect number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	map_file = argv[1];
	map_file_len = ft_strlen(map_file);
	extension = ".ber";
	if (map_file_len <= 4 || ft_strcmp(map_file + map_file_len - 4,
			extension) != 0)
	{
		ft_putstr_fd("Error: Invalid map file extension.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_valid_path(t_game *game)
{
	char	**map_tmp;
	int		i;
	int		counter;

	i = 0;
	map_tmp = (char **)malloc(sizeof(char *) * (game->map_rows + 1));
	while (game->map[i])
	{
		map_tmp[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_tmp[i] = NULL;
	counter = 0;
	ft_flood_fill(map_tmp, game->player_x, game->player_y, &counter);
	i = 0;
	while (map_tmp[i])
	{
		free(map_tmp[i]);
		i++;
	}
	free(map_tmp);
	return (counter == (game->collectibles + 1));
}

void	ft_flood_fill(char **map_tmp, int x, int y, int *counter)
{
	if (map_tmp[y][x] == 'E' || map_tmp[y][x] == 'C')
		(*counter)++;
	if (map_tmp[y][x] == 'E')
		map_tmp[y][x] = 'F';
	if (map_tmp[y][x] == '1' || map_tmp[y][x] == 'F')
		return ;
	map_tmp[y][x] = 'F';
	ft_flood_fill(map_tmp, x + 1, y, counter);
	ft_flood_fill(map_tmp, x - 1, y, counter);
	ft_flood_fill(map_tmp, x, y + 1, counter);
	ft_flood_fill(map_tmp, x, y - 1, counter);
}

int	close_window(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx_ptr, game->i_floor);
	mlx_destroy_image(game->mlx_ptr, game->i_wall);
	mlx_destroy_image(game->mlx_ptr, game->i_exit);
	destroy_image_array(game->mlx_ptr, game->i_player, 6);
	destroy_image_array(game->mlx_ptr, game->i_coin, 6);
	destroy_image_array(game->mlx_ptr, game->i_crab, 6);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
