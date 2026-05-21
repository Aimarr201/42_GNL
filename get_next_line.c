
#include "get_next_line.h"

char    *ft_read_more(int fd, char *saved)
{
        char    *buffer;
        int             bytes_read;
        char    *tmp;

        buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
        if (!buffer)
                return (free(saved), NULL);
        bytes_read = 1;
        while (ft_read_until_new_line(saved) == -1 && bytes_read > 0)
        {
                bytes_read = read(fd, buffer, BUFFER_SIZE);
                if (bytes_read < 0)
                        return (free(buffer), free(saved), NULL);
                buffer[bytes_read] = '\0';
                tmp = ft_strjoin(saved, buffer);
                free(saved);
                if (!tmp)
                        return (free(buffer), NULL);
                saved = tmp;
        }
        if (bytes_read == 0 && (!saved || !saved[0]))
                return (free(saved), NULL);
        return (free(buffer), saved);
}

int     ft_read_until_new_line(char *saved)
{
        int     i;

        if (!saved)
                return (-1);
        i = 0;
        while (saved[i])
        {
                if (saved[i] == '\n')
                        return (i);
                i++;
        }
        return (-1);
}

char    *ft_craft_line(char *saved)
{
        char    *line;
        int             i;

        if (!saved || !saved[0])
                return (NULL);
        i = 0;
        while (saved[i] && saved[i] != '\n')
                i++;
        line = ft_calloc(i + 2, sizeof(char));
        if (!line)
                return (NULL);
        ft_cpy_output(line, saved);
        return (line);
}

char    *ft_save_for_the_future(char *saved)
{
        char    *rest;
        int             i;
        int             j;

        if (!saved)
                return (NULL);
        i = 0;
        while (saved[i] && saved[i] != '\n')
                i++;
        if (!saved[i])
                return (free(saved), NULL);
        i++;
        rest = ft_calloc(ft_strlen(saved + i) + 1, sizeof(char));
        if (!rest)
        {
                free(saved);
                return (NULL);
        }
        j = 0;
        while (saved[i])
                rest[j++] = saved[i++];
        free(saved);
        return (rest);
}

char    *get_next_line(int fd)
{
        static char     *saved;
        char            *output;

        if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
                return (NULL);
        saved = ft_read_more(fd, saved);
        if (!saved)
                return (NULL);
        output = ft_craft_line(saved);
        if (!output)
                return (free(saved), saved = NULL, NULL);
        saved = ft_save_for_the_future(saved);
        return (output);
}
