/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:06:31 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 19:38:49 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	map_min_req(char **map)
{
	int	i;
	int	j;
	int	collectible;
	int	start_exit_count;

	assign_min_req(&i, &j, &collectible, &start_exit_count);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				start_exit_count++;
			else if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		j = 0;
		i++;
	}
	if (start_exit_count < 2)
		return (0);
	else if (collectible < 1)
		return (0);
	return (1);
}

int	is_map_filled(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'E' &&
				map[i][j] != 'P' &&
				map[i][j] != 'C' &&
				map[i][j] != '1' &&
				map[i][j] != '0'
				)
			{
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	get_row_len(char **map)
{
	int	j;

	j = 0;
	while (map[0][j])
		j++;
	return (j);
}

int	new_fd(char *file, int prev_fd)
{
	int	fd;

	if (prev_fd)
		close(prev_fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	check_players(char **map)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			if (player_count > 1 && map[i][j] == 'P')
				map[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
