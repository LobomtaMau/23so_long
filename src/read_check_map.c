/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:00:27 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/17 11:28:48 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_error(t_game *game)
{
	if (!ft_is_rectangular(game))
		error_msg(game, "Error: Map is not rectangular.\n");
	if (!ft_has_valid_elements(game))
		error_msg(game, "Error: Map does not have valid elements.\n");
	if (!ft_is_surrounded_by_walls(game))
		error_msg(game, "Error: Map is not surrounded by walls.\n");
	if (!ft_valid_path(game))
		error_msg(game, "Error: Map does not have valid path\n");
	if (!valid_sprites(game))
		error_msg(game, "Error: Map does not have valid cell\n");
}

void	ft_read_check_map(t_game *game, char *map_file)
{
	char	*line;
	int		map_fd;
	char	*map_tmp;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
	{
		ft_putstr_fd("Error: Unable to open map file.\n", 2);
		exit(EXIT_FAILURE);
	}
	map_tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		map_tmp = ft_append_strs(&map_tmp, line);
		game->map_rows++;
		free(line);
	}
	close(map_fd);
	game->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	ft_handle_error(game);
}

int	ft_is_rectangular(t_game *game)
{
	size_t	expected_len;
	int		i;

	i = 0;
	expected_len = ft_strlen(game->map[0]);
	while (i < game->map_rows)
	{
		if (ft_strlen(game->map[i]) != expected_len)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_surrounded_by_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		i++;
		game->map_columns++;
	}
	i = 0;
	while (i < game->map_columns)
	{
		if (game->map[0][i] != '1' || game->map[game->map_rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_columns
			- 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_has_valid_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	return (game->player == 1 && game->collectibles > 0 && game->exit == 1);
}
