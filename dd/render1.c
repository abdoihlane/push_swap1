#include "so_long.h"

void draw_map(t_game *game)
{
    int i = 0;
    int j;
    
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j] && game->map[game->player_y][game->player_x] != 'E')
        {
            if (game->map[i][j] == '1')
            mlx_put_image_to_window(game->mlx, game->wind, game->wall_img, j * 64, i * 64);
            else if (game->map[i][j] == 'P')
            mlx_put_image_to_window(game->mlx, game->wind, game->player_img, j * 64, i * 64);
            else if (game->map[i][j] == 'C')
            mlx_put_image_to_window(game->mlx, game->wind, game->coin_img, j * 64, i * 64);
            else if (game->map[i][j] == 'E')
            mlx_put_image_to_window(game->mlx, game->wind, game->exit_img, j * 64, i * 64);
            else if (game->map[i][j] == '0')
            mlx_put_image_to_window(game->mlx, game->wind, game->empty_img, j * 64, i * 64);
            j++;
        }
        i++;
    }
    return;
}

void *load_allshit(t_game *game)
{
    int width, height;
    
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Failed to initialize MLX\n");
        exit(1);
    }    
    game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/batman.xpm", &width, &height);
    game->coin_img = mlx_xpm_file_to_image(game->mlx, "textures/coin2.xpm", &width, &height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
    game->empty_img = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &width, &height);
    put_to_screen(game);
    return NULL;
}
