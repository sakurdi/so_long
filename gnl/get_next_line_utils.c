/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:23:46 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/06/19 21:24:23 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, unsigned char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_empty_str(char *s)
{
	s = malloc(sizeof(char) * 1);
	if (!s)
		return (NULL);
	*s = 0;
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	index;
	size_t	j;

	j = 0;
	index = 0;
	if (!s1 && s2)
		s1 = ft_empty_str(s1);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (s2[j])
		str[index++] = s2[j++];
	str[index] = 0;
	free(s1);
	return (str);
}
