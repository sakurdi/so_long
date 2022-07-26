/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:06:31 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/25 10:31:22 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	main(int ac, char **av)
{
	t_game_data	game_data;
	t_sprites	sprites;

	game_data.textures = &sprites;
	game_data.init_ptr = mlx_init();
	init_handler(&game_data, ac, av);
	game_data.window_ptr = mlx_new_window(game_data.init_ptr,
			game_data.window_l * game_data.textures->wall_w,
			game_data.window_h * game_data.textures->wall_h,
			"so_long");
	mlx_hook(game_data.window_ptr, 15, (1L << 16), render, &game_data);
	mlx_hook(game_data.window_ptr, 17, (1L << 0), ondestroy_event, &game_data);
	mlx_hook(game_data.window_ptr, 2, (1L << 0), close_window, &game_data);
	mlx_key_hook(game_data.window_ptr, move_handler, &game_data);
	mlx_loop(game_data.init_ptr);
	return (0);
}
