/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:31:22 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 20:36:27 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	assign_min_req(int *i, int *j, int *c, int *se_count)
{
	*i = 0;
	*j = 0;
	*c = 0;
	*se_count = 0;
}

int	outer_wall_check(int i, int j, int bottom, char **map)
{
	if (i == 0 && map[i][j] != '1')
		return (0);
	else if (i == bottom && map[i][j] != '1')
		return (0);
	return (1);
}

void	set_outer_vars(int *i, int *j)
{
	*i = 0;
	*j = 0;
}
