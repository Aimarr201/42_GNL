/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:30:35 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/22 16:37:15 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;
	size_t		dstlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	dstlen = ft_strlen(s);
	if (len > dstlen - start)
		len = dstlen - start;
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (const char)chr)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)chr == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *original)
{
	size_t	i;
	char	*dup;
	char	*ptr;

	ptr = (char *)original;
	dup = malloc(sizeof(char) * ft_strlen(original) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (original[i])
	{
		dup[i] = ptr[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_free_strjoin(char *str1, char *str2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!str1 || !str2)
		return (NULL);
	joined = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	free(str1);
	return (joined);
}
