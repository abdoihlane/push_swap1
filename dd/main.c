#include "so_long.h"

void    init_game(t_game *game)
{
    game->mlx = NULL;
    game->player_img = NULL;
    game->coin_img = NULL;
    game->exit_img = NULL;
    game->empty_img = NULL;
    game->map = NULL;
    game->map_copy = NULL;
    game->img = NULL;
    game->wind = NULL;
    game->wall_img = NULL;
    game->player_x = 0;
    game->player_y = 0;
    game->map_len = 0;
    game->map_wid = 0;
    game->img_width = 0;
    game->img_height = 0;
    game->coins = 0;
    game->coin_count = 0;
    game->exit = 0;
    game->player = 0;
    game->collected_coins_f = 0;
    game->exit_found = 0;
    game->i = 0;
}
void free_all(t_game *game)
{
    printf("ss");
    free_map(game);
    free(game->mlx);
    // free(game);
    // free(game->win );
    // free(game->player_img);
    // free(game->coin_img);
    // free(game->exit_img);
    // free(game->empty_img);
    // free(game->img );
    // free(game->wind );
    // free(game->wall_img );

}
int main(int ac, char **av)
{
    t_game game;
    init_game(&game);
    if (ac != 2)
    {
        printf("Usage: %s <map_file.ber>\n", av[0]);
        exit(1);
    }
    check_name(av[1]);
    read_map(av[1], &game);
    load_allshit(&game);
    // free_all(&game);
    printf("ss");
    free_map(&game);
    free(game.mlx);
    
    return 0;
}
// int main(int ac, char **av){
//     maiin(ac, av);
//     system("leaks so_long");
//     return 0;
// }