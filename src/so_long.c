/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:34:26 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/06 12:34:27 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	ft_check_args(argc, argv);
	ft_read_check_map(&game, argv[1]);
	ft_start_game(&game);
}
