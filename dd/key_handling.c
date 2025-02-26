#include "so_long.h"

void coin_collect(t_game *game, int i, int j)
{
    if(game->map[i][j] == 'C')
    {
        game->coins++;
    }
}

void	tfi_zmer(t_game *game)
{
    // int i = 0;
    // free_map(game);
    mlx_destroy_image(game->mlx,game->empty_img);
    mlx_destroy_image(game->mlx,game->wall_img);
    mlx_destroy_image(game->mlx,game->coin_img);
    mlx_destroy_image(game->mlx,game->exit_img);
    mlx_destroy_image(game->mlx,game->player_img);
	mlx_destroy_window(game->mlx, game->wind);
    mlx_destroy_display(game->mlx);
	free_all(game);
}

int handle_key(int keycode, t_game *game)
{
    if (keycode == 65307)
        {
            printf("ss");
            // free_all(game);
            tfi_zmer(game);
            exit(0);
        } 
    else if (keycode == 65364 || keycode == 115) // Down
        move_up_down(65364, game);
    else if (keycode == 65362 || keycode == 119)  // Up
        move_up_down(65362, game);
    else if (keycode == 65361 || keycode == 97) // Left
        move_left_right(65361, game);
    else if (keycode == 65363 || keycode == 100) // Right
        move_left_right(65363, game);
    draw_map(game);
    //     printf("move number :%d\n", game->i);
    // game->i++;
    return 0;
}

void move_up_down(int keycode, t_game *game)
{
    if (keycode == 65364) // Down
    {
        coin_collect(game, game->player_y + 1, game->player_x);
        check_exit(game, game->player_x, game->player_y + 1);
        if (game->map[game->player_y + 1][game->player_x] != '1'
            && game->map[game->player_y + 1][game->player_x] != 'E')
        {
            game->map[game->player_y + 1][game->player_x] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_y++;
        }
    }
    else if (keycode == 65362) // Up
    {
        coin_collect(game, game->player_y - 1, game->player_x);
        check_exit(game, game->player_x, game->player_y - 1);
        if (game->map[game->player_y - 1][game->player_x] != '1'
            && game->map[game->player_y - 1][game->player_x] != 'E')
        {
            game->map[game->player_y - 1][game->player_x] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_y--;
        }
    }
}

void move_left_right(int keycode, t_game *game)
{
    if (keycode == 65361 || keycode == 97) // Left
    {   
        coin_collect(game, game->player_y, game->player_x - 1);
        check_exit(game, game->player_x - 1, game->player_y);
        if (game->map[game->player_y][game->player_x - 1] != '1'
            && game->map[game->player_y][game->player_x - 1] != 'E')
        {
            game->map[game->player_y][game->player_x - 1] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_x--;
        }
    }
    else if (keycode == 65363 || keycode == 100) // Right
    {
        coin_collect(game, game->player_y, game->player_x + 1);
        check_exit(game, game->player_x + 1, game->player_y);
        if (game->map[game->player_y][game->player_x + 1] != '1'
            && game->map[game->player_y][game->player_x + 1] != 'E')
        {
            game->map[game->player_y][game->player_x + 1] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_x++;
        }
    }
}
