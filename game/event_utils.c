/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:29:29 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/25 11:30:50 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	free_images(t_game_data *st)
{
	mlx_destroy_image(st->init_ptr, st->textures->floor);
	mlx_destroy_image(st->init_ptr, st->textures->wall);
	mlx_destroy_image(st->init_ptr, st->textures->player);
	mlx_destroy_image(st->init_ptr, st->textures->exit);
	mlx_destroy_image(st->init_ptr, st->textures->item);
}

void	exit_game(t_game_data *st)
{
	free_images(st);
	free_map(st);
	mlx_destroy_window(st->init_ptr, st->window_ptr);
	mlx_destroy_display(st->init_ptr);
	free(st->init_ptr);
	exit(EXIT_SUCCESS);
}

int	ondestroy_event(t_game_data *st)
{
	free_images(st);
	free_map(st);
	mlx_destroy_window(st->init_ptr, st->window_ptr);
	mlx_destroy_display(st->init_ptr);
	free(st->init_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	close_window(int keycode, t_game_data *st)
{
	if (keycode == ESC_KEY)
	{
		free_images(st);
		free_map(st);
		mlx_destroy_window(st->init_ptr, st->window_ptr);
		mlx_destroy_display(st->init_ptr);
		free(st->init_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
