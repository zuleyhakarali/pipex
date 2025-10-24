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

static void free_s(char **s)
{
    char *s_f_a;

    s_f_a = s;
    while (*s)
    {
        free(*s);
        s++;
    }
    free(s_f_a);
}

char *check_path(char *command)
{
    char *path;
    char **paths;
    char **paths_first_adress;
    char *true;
    int i;

    path = getenv("PATH");
    if (!path)
        return (NULL);
    paths = ft_split(path, ':');
    if (!paths)
        return (NULL);
    paths_first_adress = paths;
    i = 0;
    while (paths[i])
    {
        true = making_str(paths[i], command);
        if (!true)
            return (free_s(paths_first_adress), NULL);
        if (access(true, X_OK) == 0)
            return (free_s(paths_first_adress), true);
        free(true);
        i++;
    }
    return (free_s(paths_first_adress), NULL);
}