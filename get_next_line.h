
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char *ft_read_more(int fd, char *saved)
int ft_read_until_new_line(char *saved)
char *ft_craft_line(char *saved)
char *ft_save_for_the_future(char *saved)
char *get_next_line(int fd)

void ft_cpy_output(char *dst, const char *src)
void *ft_calloc(size_t count, size_t size)
size_t ft_strlen(const char *str)
char *ft_strjoin(const char *s1, const char *s2)

#endif
