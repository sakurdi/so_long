/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:24:04 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/06/19 21:23:55 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef  GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define NEWLINE '\n'

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, unsigned char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif