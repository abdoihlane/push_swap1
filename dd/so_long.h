#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mlx.h"

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *player_img;
    void    *coin_img;
    void    *exit_img;
    void    *empty_img;
    int     player_x;
    int     player_y;
    int     map_len;
    int     map_wid;
    char    **map;
    char    **map_copy;
    void    *img;
    void    *wind;
    void    *wall_img;
    int     img_width;
    int     img_height;
    int     coins;
    int     coin_count;
    int     exit;
    int     player;
    int     collected_coins_f;
	int     exit_found;
    int    i;
} t_game;

void    not_valid(t_game *game,char *message);
int     handle_key(int keycode, t_game *game);
void    coin_collect(t_game *game, int i, int j);
void    check_exit(t_game *game, int new_x, int new_y);
void    move_up_down(int keycode, t_game *game);
void    move_left_right(int keycode, t_game *game);
void    tfi_zmer(t_game *game);
void    *load_allshit(t_game *game);
void    check_name(char *name);
int     check_map_bounds(char **map, int j, int z);
void    check2(t_game *game, char **map);
void    check3(t_game *game, char **map, int j, int z);
int     map_check(char **map, t_game *game);
int     ft_strlcpy(char *dest, const char *src);
void    ft_map_copy(t_game *game, int y);
void    read_map(const char *map_path, t_game *game);
char    *get_next_line(int fd);
void free_all(t_game *game);

void    draw_map(t_game *game);
void    put2_to_screen(t_game *game, int a, int b);
void    put3_to_screen(t_game *game, int a, int b);
void    while_put_to_screen(t_game *game, int a, int b);
void    *put_to_screen(t_game *game);
void	flood_fill(t_game *game,int y, int x);
void map_copy_check(t_game *game);
void free_map(t_game *game);

#endif
