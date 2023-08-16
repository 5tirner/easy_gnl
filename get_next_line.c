/**
 * Made By Zasabri
 *
 * get_next_line - get onr line from a file
 * 
 * @fd: file Discriptor
 *
 * Return: Line Until NewLine Or Null If Somthing Wrong
 *
 * Ellegale Get_Next_line
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#if BUFFER_SIZE > 1
#undef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
char    *add_char(char *str, char c)
{
        char *new;
        int i;
        if (!str)
        {
                new = malloc(3);
                new[0] = c;
                new[1] = '\0';
        }
        else
        {
                i = 0;
                while (str[i])
                        i++;
                new = malloc(i + 2);
                i = 0;
                while (str[i])
                {
                        new[i] = str[i];
                        i++;
                }
                new[i] = c;
                new[i + 1] = '\0';
        }
	if (str)
		free(str);
        return (new);
}

char    *gl(int fd)
{
        if (fd == -1)
                return (NULL);
        char c;
        char *str;
        str = NULL;
        int i = read(fd, &c, BUFFER_SIZE);
        if (i == 0)
                return (NULL);
        while (i != 0 && c != '\n')
        {
                if (i == -1)
                        return (NULL);
                str = add_char(str, c);
                i = read(fd, &c, BUFFER_SIZE);
        }
        if (c == '\n')
                str = add_char(str, c);
        return (str);
}
int main()
{
        int fd = open("get_next_line.c", O_RDONLY, 0777);
        char *str;
        int i = 1;
        while (i)
        {
                str = gl(fd);
                printf("%s", str);
                if (!str)
                        break;
		free(str);
        }
        close(fd);
}

/*************************************************************************************
* ==269905== HEAP SUMMARY:                                                           *
* ==269905==     in use at exit: 0 bytes in 0 blocks                                 *
* ==269905==   total heap usage: 1,839 allocs, 1,839 frees, 30,227 bytes allocated   *
* ==269905==                                                                         *
* ==269905== All heap blocks were freed -- no leaks are possible                     *
* ==269905==                                                                         *
* ==269905== For lists of detected and suppressed errors, rerun with: -s             *
* ==269905== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)          *
**************************************************************************************/
