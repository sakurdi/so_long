/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:03:59 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 22:08:56 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	render(t_game_data *st)
{
	draw_walls(st);
	draw_floor(st);
	draw_item(st);
	draw_exit(st);
	draw_player(st);
	return (1);
}

void	load_sprites(t_game_data *st)
{
	st->textures->floor = mlx_xpm_file_to_image(st->init_ptr,
			"assets/floor.xpm",
			&st->textures->floor_w,
			&st->textures->floor_h);
	st->textures->wall = mlx_xpm_file_to_image(st->init_ptr,
			"assets/wall.xpm",
			&st->textures->wall_w,
			&st->textures->wall_h);
	st->textures->player = mlx_xpm_file_to_image(st->init_ptr,
			"assets/player.xpm",
			&st->textures->player_w,
			&st->textures->player_h);
	st->textures->exit = mlx_xpm_file_to_image(st->init_ptr,
			"assets/sortie.xpm",
			&st->textures->exit_w,
			&st->textures->exit_h);
	st->textures->item = mlx_xpm_file_to_image(st->init_ptr,
			"assets/item.xpm",
			&st->textures->item_w,
			&st->textures->item_h);
}

void	free_sprites(t_game_data *st)
{
	if (st->textures->floor != NULL)
		mlx_destroy_image(st->init_ptr, st->textures->floor);
	if (st->textures->wall != NULL)
		mlx_destroy_image(st->init_ptr, st->textures->wall);
	if (st->textures->exit != NULL)
		mlx_destroy_image(st->init_ptr, st->textures->exit);
	if (st->textures->item != NULL)
		mlx_destroy_image(st->init_ptr, st->textures->item);
	if (st->textures->player != NULL)
		mlx_destroy_image(st->init_ptr, st->textures->player);
}

int	check_sprites(t_game_data *st)
{
	if (!st->textures->floor)
		return (0);
	else if (!st->textures->wall)
		return (0);
	else if (!st->textures->exit)
		return (0);
	else if (!st->textures->item)
		return (0);
	else if (!st->textures->player)
		return (0);
	return (1);
}
