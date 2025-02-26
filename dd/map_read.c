#include "so_long.h"

void read_map(const char *map_path, t_game *game)
{
    int i = 0;
    int j = 0;
    char *line;
    int fd;
    char **map =NULL;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        printf("Cannot open map file: %s\n", map_path);
        exit(1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        free(line);
        i++;
    }
    close(fd);
    if (i == 0)
    {
        printf("Failed to read map line");
        exit(0);
    }
    map = malloc(sizeof(char *) * (i + 1));
    if (!map)
    {
        printf("MALLOC FAILED");
        exit(1);
    }
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        perror("INVALID PATH");
        free(map);
        exit(1);
    }
    while (j <= i)
    {
        map[j] = get_next_line(fd);
        // printf("%s", map[j]);?
        if (!map[j] && j < i)
        {
            while(j >= 0)
            {
                printf("Failed to read map line%d",j);
                free(map[j]);
                j--;
            }
            free(map);
            close(fd);
            exit(0);
        }
        j++;
    }
    map[j] = NULL;
    close(fd);
    game->map = map;
    map_check(map, game);
    ft_map_copy(game, j);
    return;
}
