/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:06:31 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/26 10:43:38 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSING_H
# define PARSING_H

# include "../so_long.h"

void	assign_min_req(int *i, int *j, int *c, int *se_count);
int		outer_wall_check(int i, int j, int bottom, char **map);
void	set_outer_vars(int *i, int *j);
char	*get_next_line(int fd);

#endif