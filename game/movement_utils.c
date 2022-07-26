/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:00:30 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 22:01:49 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	get_items(t_game_data *st)
{
	int	i;
	int	j;
	int	item;

	i = 0;
	j = 0;
	item = 0;
	while (st->map[i])
	{
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'C')
				item++;
			j++;
		}
		j = 0;
		i++;
	}
	return (item);
}

void	get_player_pos(t_game_data *st)
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
				st->pos_i = i;
				st->pos_j = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	move_handler(int keycode, t_game_data *st)
{
	if (keycode == UP)
		move_up(st);
	else if (keycode == RIGHT)
		move_right(st);
	else if (keycode == DOWN)
		move_down(st);
	else if (keycode == LEFT)
		move_left(st);
	return (1);
}
