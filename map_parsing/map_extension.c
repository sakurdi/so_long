/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:49:26 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/07/24 18:49:54 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

char	*ft_strrchr(char *s, int c)
{
	ssize_t	len;

	len = ft_strlen(s);
	if (c == '\0' && s[len] == '\0')
		return (&s[len]);
	while (--len >= 0)
	{
		if (s[len] == (char)c)
			return (&s[len]);
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (p_s1[i] != p_s2[i] || p_s1[i] == 0 || p_s2[i] == 0)
			return (p_s1[i] - p_s2[i]);
		i++;
	}
	return (0);
}

int	check_extension(char *s)
{
	char	*ext;

	ext = ft_strrchr(s, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
		return (0);
	else
		return (1);
}
