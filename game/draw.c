/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:40:13 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 21:28:28 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	draw_floor(t_game_data *st)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st->map[i])
	{
		while (st->map[i][j])
		{
			if (st->map[i][j] == '0')
			{
				mlx_put_image_to_window(
					st->init_ptr,
					st->window_ptr,
					st->textures->floor,
					j * st->textures->wall_w,
					i * st->textures->wall_h);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	draw_walls(t_game_data *st)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st->map[i])
	{
		while (st->map[i][j])
		{
			if (st->map[i][j] == '1')
			{
				mlx_put_image_to_window(
					st->init_ptr,
					st->window_ptr,
					st->textures->wall,
					j * st->textures->wall_w,
					i * st->textures->wall_h);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	draw_player(t_game_data *st)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st->map[i])
	{
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'P')
			{
				mlx_put_image_to_window(
					st->init_ptr,
					st->window_ptr,
					st->textures->player,
					j * st->textures->wall_w,
					i * st->textures->wall_h);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	draw_exit(t_game_data *st)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st->map[i])
	{
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'E')
			{
				mlx_put_image_to_window(
					st->init_ptr,
					st->window_ptr,
					st->textures->exit,
					j * st->textures->wall_w,
					i * st->textures->wall_h);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	draw_item(t_game_data *st)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st->map[i])
	{
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'C')
			{
				mlx_put_image_to_window(
					st->init_ptr,
					st->window_ptr,
					st->textures->item,
					j * st->textures->wall_w,
					i * st->textures->wall_h);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
