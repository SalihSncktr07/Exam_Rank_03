#include "get_next_line.h"

char *get_next_line(int fd)
{
    if(BUFFER_SIZE <= 0)
        return NULL;
    int i = 0;
    int rd = 0;
    char chr;
    char *buff = malloc(100000);

    while((rd = read(fd, &chr, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buff[i++] = chr;
        if(chr == '\n')
            break ;
    }
    buff[i] = '\0';
    if(i == 0 || rd == -1 || (!buff[i - 1] && !rd))
        return (free(buff), NULL);
    return buff;
}