#include "pipex.h"


static char *making_str(char *paths, char *command)
{
    char *str;
    char *str2;

    str = ft_strjoin(paths, "/");
    if (!str)
        return (NULL);
    str2 = ft_strjoin(str, command);
    if (!str2)
        return (NULL);
    free(str);
    return (str2);
}

void free_s(char **s)
{
    int i;

    i = 0;
    if (!s)
        return ;
    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}

char *check_path(char *command)
{
    char *path;
    char **paths;
    char *true;
    int i;

    if (command[0] == '\0')
        return (NULL);
    path = getenv("PATH");
    if (!path)
        return (NULL);
    paths = ft_split(path, ':');
    if (!paths)
        return (NULL);
    i = 0;
    while (paths[i])
    {
        true = making_str(paths[i], command);
        if (!true)
            return (free_s(paths), free(true), NULL);
        if (access(true, X_OK) == 0)
            return (free_s(paths), true);
        free(true);
        i++;
    }
    error_message(3);
    return (free_s(paths), free(true), NULL);
}