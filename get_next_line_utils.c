
#include "get_next_line.h"

void    ft_cpy_output(char *dst, const char *src)
{
        size_t  i;

        i = 0;
        while (src[i] && src[i] != '\n')
        {
                dst[i] = src[i];
                i++;
        }
        if (src[i] == '\n')
        {
                dst[i] = '\n';
                i++;
        }
        dst[i] = '\0';
}

void    *ft_calloc(size_t count, size_t size)
{
        unsigned char   *tmp;
        size_t                  i;

        if (count != 0 && size > (size_t)-1 / count)
                return (NULL);
        tmp = malloc(count * size);
        if (!tmp)
                return (NULL);
        i = 0;
        while (i < count * size)
        {
                tmp[i] = 0;
                i++;
        }
        return (tmp);
}

size_t  ft_strlen(const char *str)
{
        size_t  i;

        if (!str)
                return (0);
        i = -1;
        while (str[++i])
                ;
        return (i);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
        char    *concatenated;
        int             i;
        int             j;

        if (!s2)
                return (NULL);
        if (!s1)
                s1 = "";
        i = 0;
        j = 0;
        concatenated = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
                        * sizeof(char));
        if (!concatenated)
                return (NULL);
        while (s1[i])
                concatenated[i] = s1[i++];
        while (s2[j])
                concatenated[i++] = s2[j++];
        concatenated[i] = '\0';
        return (concatenated);
}
