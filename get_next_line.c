/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:30:29 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/22 17:06:18 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_for_the_future(char *saved)
{
	char	*non_used;
	size_t	i;

	if (!saved)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	if (saved[i] == '\0')
	{
		free(saved);
		return (NULL);
	}
	non_used = ft_strdup(saved + i);
	free(saved);
	return (non_used);
}

char	*ft_craft_line(char *saved)
{
	size_t	i;
	char	*line;

	if (!saved)
		return (NULL);
	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	if (saved[i] == '\n')
		i++;
	line = ft_substr(saved, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read_more(int fd, char *saved)
{
	char		*buffer;
	int			bytes_read;
	char		*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(saved), NULL);
	bytes_read = 1;
	while ((saved && !ft_strchr(saved, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(saved), free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_free_strjoin(saved, buffer);
		if (!tmp)
			return (free(saved), free(buffer), NULL);
		saved = tmp;
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved)
		saved = ft_strdup("");
	if (!saved)
		return (NULL);
	saved = ft_read_more(fd, saved);
	if (!saved)
		return (NULL);
	if (*saved == '\0')
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	output = ft_craft_line(saved);
	saved = ft_save_for_the_future(saved);
	return (output);
}

/* #include <fcntl.h>
#include <stdio.h>
int	main()
{
	int		fd;
	char	*result;
	int		i;

	printf("BUFFER_SIZE=%i\n", BUFFER_SIZE);

	fd = open("texto.txt", O_RDONLY);
	i = 1;
	result = malloc(1);
	while (result && fd != -1)
	{
		free(result);
		result = get_next_line(fd);
		if (!result)
			break ;
		// printf("line %d: %s\n", i, result);
		printf("%s", result);
		i++;
	}
	close(fd);
} */
