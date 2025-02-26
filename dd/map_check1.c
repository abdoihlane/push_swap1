#include "so_long.h"

void free_map(t_game *game)
{
    int i = 0;
    while(game->map_copy[i] && game->map[i])
    {    
        write(1, "here\n", 5);
        free(game->map_copy[i]);
        free(game->map[i]);
        i++;
    }
    free(game->map_copy);
    free(game->map);
    // exit(1);
}

void    not_valid(t_game *game,char *message)
{
    printf("%s\n", message);
    free_map(game);
    exit(1);
}

void check_name(char *name)
{
    int i;

    i = strlen(name);
    if (i <= 4)
    {
        printf("name must be like <name.ber>\n");
        exit(0);
    }
    i -= 4;
    if ((strcmp(&name[i], ".ber") != 0))
    {
        printf("the name of this map is invalid\n");
        exit(1);
    }
}

int check_map_bounds(char **map, int j, int z)
{
    if (!map || !map[j] || !map[j][z])
        return 0;
    return 1;
}

void check2(t_game *game, char **map)
{
    int row;
    row = 0;
    while (row < game->map_wid)
    {
        if ((int)strlen(map[row]) != game->map_len)
            not_valid(game,"Map is not a rectangle");
        row++;
    }
    row = 0;
    while (row < game->map_len)
    {
        if (map[0][row] != '1' || map[game->map_wid - 1][row] != '1')
            not_valid(game,"Map not enclosed by walls (top/bottom)");
        row++;
    }
    row = 0;
    while (row < game->map_wid)
    {
        if (map[row][0] != '1' || map[row][game->map_len - 1] != '1')
            not_valid(game,"Map not enclosed by walls (left/right)");
        row++;
    }
}

void check3(t_game *game, char **map, int j, int z)
{
    if (!check_map_bounds(map, j, z))
        not_valid(game,"Invalid map bounds");
    if (!strchr("PCE01", map[j][z]))
        not_valid(game,"Invalid character in map");
        
    if (map[j][z] == 'P')
    {
        game->player += 1;
        game->player_x = z;
        game->player_y = j;
    }
    else if (map[j][z] == 'C')
        game->coin_count += 1;
    else if (map[j][z] == 'E')
        game->exit += 1;
}
