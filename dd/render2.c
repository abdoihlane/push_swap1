#include "so_long.h"

void put2_to_screen(t_game *game, int a, int b)
{
    if (game->map_copy[a][b] == '0')
    {
        // safe_load_image(game, "textures/empty.xpm");
        mlx_put_image_to_window(game->mlx, game->wind, game->empty_img, b * 64, a * 64);
    }
    else if (game->map_copy[a][b] == '1')
    {
        // safe_load_image(game, "textures/wall.xpm");
        mlx_put_image_to_window(game->mlx, game->wind, game->wall_img, b * 64, a * 64);
    }
    else if (game->map_copy[a][b] == 'P')
    {
        // safe_load_image(game, "textures/batman.xpm");
        mlx_put_image_to_window(game->mlx, game->wind, game->player_img, b * 64, a * 64);
        game->player_x = b;
        game->player_y = a;
    }
    else if(game->map_copy[a][b] == 'C')
    {
        // safe_load_image(game, "textures/coin2.xpm");
        mlx_put_image_to_window(game->mlx, game->wind, game->coin_img, b * 64, a * 64);
    }
}

void put3_to_screen(t_game *game, int a, int b)
{
    if(game->map_copy[a][b] == 'E')
    {
        // safe_load_image(game, "textures/exit.xpm");
        mlx_put_image_to_window(game->mlx, game->wind, game->exit_img, b * 64, a * 64);
    }
}

void while_put_to_screen(t_game *game, int a, int b)
{
    while (game->map_copy[a][b])
    {
        if (game->map_copy[a][b] == '0')
            put2_to_screen(game, a, b);
        else if (game->map_copy[a][b] == '1')
            put2_to_screen(game, a, b);
        else if (game->map_copy[a][b] == 'P')
            put2_to_screen(game, a, b);
        else if(game->map_copy[a][b] == 'C')
            put2_to_screen(game, a, b);
        else if(game->map_copy[a][b] == 'U')
            put3_to_screen(game, a, b);
        else if(game->map_copy[a][b] == 'E')
            put3_to_screen(game, a, b);
        b++;
    }
}

void *put_to_screen(t_game *game)
{
    int a = 0;
    int b;

    game->wind = mlx_new_window(game->mlx, game->map_len * 64, game->map_wid * 64, "so_long");
    if (!game->wind)
    {
        printf("Failed to create window\n");
        exit(1);
    }
    while (game->map[a])
    {
        b = 0;
        while_put_to_screen(game, a, b);
        a++;
    }
    mlx_key_hook(game->wind, handle_key, game);
    printf("move number :%d\n", game->i);
    game->i++;
    mlx_loop(game->mlx);
    return NULL;
}
