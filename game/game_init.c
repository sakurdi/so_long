/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:30:13 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 21:30:37 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	struct_init(t_game_data *st, int height)
{
	st->step_count = 0;
	st->items = get_items(st);
	st->window_h = height;
	st->window_l = get_row_len(st->map);
}

void	free_map(t_game_data *st)
{
	int	i;

	i = 0;
	while (st->map[i])
	{
		free(st->map[i]);
		i++;
	}
	free(st->map);
}
