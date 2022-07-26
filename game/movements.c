/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:13:59 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/25 20:26:38 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	move_up(t_game_data *st)
{
	get_player_pos(st);
	if (st->map[st->pos_i - 1][st->pos_j] == 'E' && st->items == 0)
	{
		ft_printf("step count->%d\n", ++(st->step_count));
		exit_game(st);
	}
	else if ((st->map[st->pos_i - 1][st->pos_j] == '1'))
		return ;
	else if ((st->map[st->pos_i - 1][st->pos_j] == 'E') && st->items != 0)
		return ;
	else if ((st->map[st->pos_i - 1][st->pos_j] == 'C'))
	{
		st->items--;
		st->map[st->pos_i - 1][st->pos_j] = 'P';
		st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	else
	{
		st->map[st->pos_i - 1][st->pos_j] = 'P';
		st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	ft_printf("step count->%d\n", ++(st->step_count));
}

void	move_right(t_game_data *st)
{
	get_player_pos(st);
	if (st->map[st->pos_i][st->pos_j + 1] == 'E' && st->items == 0)
	{
		ft_printf("step count->%d\n", ++(st->step_count));
		exit_game(st);
	}
	else if ((st->map[st->pos_i][st->pos_j + 1] == '1'))
		return ;
	else if ((st->map[st->pos_i][st->pos_j + 1] == 'E') && st->items != 0)
		return ;
	else if ((st->map[st->pos_i][st->pos_j + 1] == 'C'))
	{
		st->items--;
		st->map[st->pos_i][st->pos_j + 1] = 'P';
		st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	else
	{
		st->map[st->pos_i][st->pos_j + 1] = 'P';
		st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	st->step_count++;
	ft_printf("step count->%d\n", st->step_count);
}

void	move_down(t_game_data *st)
{
	get_player_pos(st);
	if (st->map[st->pos_i + 1][st->pos_j] == 'E' && st->items == 0)
	{
		ft_printf("step count->%d\n", ++(st->step_count));
		exit_game(st);
	}
	else if ((st->map[st->pos_i + 1][st->pos_j] == '1'))
		return ;
	else if ((st->map[st->pos_i + 1][st->pos_j] == 'E') && st->items != 0)
		return ;
	else if ((st->map[st->pos_i + 1][st->pos_j] == 'C'))
	{
		st->items--;
		st->map[st->pos_i + 1][st->pos_j] = 'P';
		st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	else
	{
	st->map[st->pos_i + 1][st->pos_j] = 'P';
	st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	st->step_count++;
	ft_printf("step count->%d\n", st->step_count);
}

void	move_left(t_game_data *st)
{
	get_player_pos(st);
	if (st->map[st->pos_i][st->pos_j -1] == 'E' && st->items == 0)
	{
		ft_printf("step count->%d\n", ++(st->step_count));
		exit_game(st);
	}
	if ((st->map[st->pos_i][st->pos_j - 1] == '1'))
		return ;
	else if ((st->map[st->pos_i][st->pos_j - 1] == 'E') && st->items != 0)
		return ;
	else if ((st->map[st->pos_i][st->pos_j - 1] == 'C'))
	{
		st->items--;
		st->map[st->pos_i][st->pos_j - 1] = 'P';
		st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	else
	{
		st->map[st->pos_i][st->pos_j - 1] = 'P';
		st->map[st->pos_i][st->pos_j] = '0';
		render(st);
	}
	st->step_count++;
	ft_printf("step count->%d\n", st->step_count);
}
