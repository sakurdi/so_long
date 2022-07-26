/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <sal-kurd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:16:02 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/06/19 21:24:03 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*realloc_buffer(char *arr)
{
	size_t	index;
	size_t	j;
	char	*str;

	index = 0;
	j = 0;
	while (arr[index] != NEWLINE && arr[index])
		index++;
	if (!arr[index])
	{
		free(arr);
		return (NULL);
	}
	index++;
	str = malloc(ft_strlen(arr + index) * sizeof(char) + 1);
	while (arr[index])
		str[j++] = arr[index++];
	str[j] = 0;
	free(arr);
	return (str);
}

char	*extract_line(char *arr)
{
	size_t	index;
	size_t	len;
	char	*str;

	index = 0;
	len = 0;
	if (!*arr)
		return (NULL);
	while (arr[index] != NEWLINE && arr[index])
		index++;
	if (arr[index] == NEWLINE)
		index++;
	str = malloc((index * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (len < index)
	{
		str[len] = arr[len];
		len++;
	}
	str[len] = 0;
	return (str);
}

char	*read_data(int fd, char *arr)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	temp_buffer = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!temp_buffer)
		return (NULL);
	*temp_buffer = 0;
	while (!ft_strchr(temp_buffer, NEWLINE) && bytes_read != 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[bytes_read] = 0;
		arr = ft_strjoin(arr, temp_buffer);
	}
	free(temp_buffer);
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*line_stocked;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_stocked = read_data(fd, line_stocked);
	if (!line_stocked)
		return (NULL);
	line = extract_line(line_stocked);
	line_stocked = realloc_buffer(line_stocked);
	return (line);
}
