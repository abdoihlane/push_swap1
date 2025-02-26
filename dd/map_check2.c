#include "so_long.h"

int map_check(char **map, t_game *game)
{
    int j = 0, z = 0;
    
    while (map[j])
    {
        z = 0;
        while (map[j][z] && map[j][z] != '\n')
        {
            check3(game, map, j, z);
            z++;
        }
        j++;
        
    }           
    game->map_len = z;
    game->map_wid = j;
        if (map[j] && map[j][0] != '1')
    not_valid(game,"Map not enclosed by walls");
    check2(game, map);
    if (game->player != 1)
        not_valid(game,"Must have exactly one player");
    if (game->coin_count == 0)
        not_valid(game,"Must have at least one collectible");
    ft_map_copy(game, j);
    flood_fill(game, game->player_y, game->player_x);
    if (game->collected_coins_f < game->coin_count)
        not_valid(game,"Not all collectibles can be reached");
     map_copy_check(game);
    if (game->exit != 1)
        not_valid(game,"Must have exactly one exit");
    int i =0;
    while(game->map_copy[i])
    {    
        free(game->map_copy[i]);
        i++;
    }
    free(game->map_copy);
    return 0;
}

void ft_map_copy(t_game *game, int y)
{
    int i;

    game->map_copy = malloc(sizeof(char *) * (y + 1));
    if (!game->map_copy)
        return ;
    i = 0;
    while (game->map[i])
    {
        game->map_copy[i] = strdup(game->map[i]);
        if (!game->map_copy[i])
        {
            while (--i >= 0)
                free(game->map_copy[i]);
            free(game->map_copy);
            return ;
        }
        i++;
    }
    game->map_copy[i] = NULL;
    // return (game->map_copy);
}

int ft_strlcpy(char *dest, const char *src)
{
    unsigned int i;
    unsigned int s;

    s = strlen(src);
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (s);
}

void check_exit(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == 'E' && game->coin_count == game->coins)
    {
        printf("You reached the exit! 🎉\n");
        // free_all(game);
        tfi_zmer(game);
        exit(0);
    }
}
void flood_fill(t_game *game, int y, int x)
{
    if (x < 0 || y < 0 || y > game->map_wid || x > game->map_len
        || game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'V' || game->map_copy[y][x] == 'E')
        return;
    
    if (game->map_copy[y][x] == 'C')
        game->collected_coins_f++;

    game->map_copy[y][x] = 'V';
    flood_fill(game, y, x - 1); // Left
    flood_fill(game, y + 1, x); // Down
    flood_fill(game, y, x + 1); // Right
    flood_fill(game, y - 1, x); // Up
}

void map_copy_check(t_game *game)
{
    int i = 0;
    int j;
    while(game->map_copy[i])
    {
        j =0;
        while(game->map_copy[i][j])
        {
            if(game->map_copy[i][j] == 'E')
                {
                    if(game->map_copy[i+1][j] == '1' && game->map_copy[i-1][j] == '1' && game->map_copy[i][j+1] == '1'&& game->map_copy[i][j-1] == '1')
                        not_valid(game,"exit can not be reached");
                }
            j++;
        }
        i++;
    }
    return;
}