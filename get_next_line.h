/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:30:32 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/22 16:32:14 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_save_for_the_future(char *saved);
char	*ft_craft_line(char *saved);
char	*ft_read_more(int fd, char *saved);
char	*get_next_line(int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int chr);
char	*ft_strdup(const char *original);
char	*ft_free_strjoin(char *str1, char *str2);

#endif
