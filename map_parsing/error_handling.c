/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:38:56 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/25 21:25:05 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	is_map_valid(t_game_data *st, int height)
{
	int	valid;

	valid = 0;
	if (!st->map)
	{
		ft_printf("Error\nmap allocation failed\n");
		exit(EXIT_SUCCESS);
	}
	if (check_outer_walls(st->map, height))
		if (is_map_rectangular(st->map))
			if (map_min_req(st->map))
				if (is_map_filled(st->map))
					if (check_players(st->map))
						valid = 1;
	if (!valid)
	{
		free_map(st);
		ft_printf("Error\ninvalid map format\n");
		exit(EXIT_SUCCESS);
	}
	return (1);
}

void	basic_checks(int ac, char **av, int *fd, int *height)
{
	*fd = open(av[1], O_RDONLY);
	*height = get_map_height(*fd);
	if (ac < 2)
	{
		ft_printf("Error\nno file given\n");
		close(*fd);
		exit(EXIT_SUCCESS);
	}
	else if (*fd < 0)
	{
		ft_printf("Error\ncouldnt open the given map argument\n");
		exit(EXIT_SUCCESS);
	}
	else if (!check_extension(av[1]))
	{
		ft_printf("Error\nwrong file extension\n");
		close(*fd);
		exit(EXIT_SUCCESS);
	}
	else if (*height < 3)
	{
		ft_printf("Error\nmap too small\n");
		close(*fd);
		exit(EXIT_SUCCESS);
	}
}

void	sprite_handler(t_game_data *st, int fd)
{
	load_sprites(st);
	if (!check_sprites(st))
	{
		ft_printf("Error\ncouldnt load sprites\n");
		close(fd);
		exit(EXIT_SUCCESS);
	}
}

void	init_handler(t_game_data *st, int ac, char **av)
{
	int	fd;
	int	height;

	if (st->init_ptr == NULL)
	{
		ft_printf("Error\nmlx_init failed\n");
		exit(EXIT_SUCCESS);
	}
	basic_checks(ac, av, &fd, &height);
	sprite_handler(st, fd);
	st->map = parse_map_content(av[1], fd, height);
	is_map_valid(st, height);
	struct_init(st, height);
}
