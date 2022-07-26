/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:41:53 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 20:35:16 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

char	**parse_map_content(char *file, int fd, int height)
{
	char	**map;
	int		len;
	char	*line;

	len = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	fd = new_fd(file, fd);
	if (!fd)
		return (NULL);
	while (len < height)
	{
		line = get_next_line(fd);
		map[len] = ft_strdup(line);
		len++;
		free(line);
	}
	map[len] = NULL;
	close(fd);
	return (map);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	index;

	index = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	while (*s && *s != NEWLINE)
	{	
		str[index++] = *s++;
	}
	str[index] = 0;
	return (str);
}

int	get_map_height(int fd)
{
	int		height;
	char	*line;

	height = 0;
	while (1)
	{	
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	return (height);
}

int	check_outer_walls(char **map, int height)
{
	int	i;
	int	j;
	int	bottom;
	int	last_index;

	set_outer_vars(&i, &j);
	bottom = height - 1;
	if (height < 3)
		return (0);
	while (map[i])
	{
		last_index = ft_strlen(map[i]) - 1;
		while (map[i][j])
		{
			if (!outer_wall_check(i, j, bottom, map))
				return (0);
			else if ((i != 0 && i != bottom) && (j == 0 || j == last_index)
				&& map[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_map_rectangular(char **map)
{
	int	last_elem_size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	last_elem_size = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j < 3)
			return (0);
		if (last_elem_size != j && i > 0)
			return (0);
		last_elem_size = j;
		j = 0;
		i++;
	}
	return (1);
}
