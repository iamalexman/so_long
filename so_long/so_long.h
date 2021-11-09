/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:13:46 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:48 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./minilibx_mms/mlx.h"

# define WINDOW_X 640
# define WINDOW_Y 480

# define FILE_ERROR 100
# define MAP_ERROR 101
# define READ_ERROR 103
# define MALLOC_ERROR 102

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_data
{
	int		x;
	int		y;
	int		*h;
	int		*w;
	void	*mlx;
	int		move;
	void	*wall;
	void	*gift;
	void	*exit;
	int		width;
	int		color;
	int		u_win;
	char	**map;
	int		height;
	void	*enemy;
	void	*grave;
	int		enemy_x;
	int		enemy_y;
	void	*player;
	int		actions;
	void	*mlx_win;
	void	*mlx_image;
	void	*big_enemy;
	int		enemy_flag;
	int		nbr_to_exit;
	int		collectibles;
	int		loop_counter;

}				t_data;

int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa_light(int n, char *str);
int		ft_strcmp(char *str1, char *str2);
int		get_next_line(int fd, char **line);

int		ft_check(char *argv);
void	free_map(char **data);
void	ft_mlx_init(t_data *data);
void	ft_init_data_struct(t_data *data);
void	ft_map_reader(t_data *data, char *line);
void	ft_get_map(char **old_map, t_data *data);
void	ft_check_map(char **map, int width, int height);
void	ft_get_map_size(t_data *data, int out, char *argv);
void	ft_validation(char **new_map, int size, t_data *data);

void	ft_make_bonus_images(t_data *data);
void	ft_bonus_map_reader(t_data *data, char *line);
void	ft_check_bonus_map(char **map, int width, int height);
void	ft_get_bonus_map_size(t_data *data, int out, char *argv);

void	ft_error(int data);
int		ft_close(t_data *data);
int		ft_action(t_data *data);
int		lets_play(t_data *data);
int		ft_press_buttons(int key, t_data *data);
int		ft_win_message(t_data *data, int x, int y);
int		ft_kill_message(t_data *data, int x, int y);

void	ft_move_up(t_data *data);
void	ft_boss_draw(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_enemy_walk(t_data *data);
void	ft_move_right(t_data *data);
void	ft_make_images(t_data *data);
void	ft_enemy_walk_2(t_data *data);
void	exit_animations(t_data *data);
void	gifts_animations(t_data *data);
void	enemy_animations(t_data *data);
void	enemy_big_animations(t_data *data);
void	ft_put_color_to_image(t_data *data);
void	ft_drawing_tab_actions(t_data *data);
void	ft_enemy_draw(t_data *data, int x, int y);
void	ft_drawing_map(t_data *data, int x, int y);
void	ft_player_up_move_draw(t_data *data, int x, int y);
void	ft_player_left_move_draw(t_data *data, int x, int y);
void	ft_player_down_move_draw(t_data *data, int x, int y);
void	ft_player_idle_left_draw(t_data *data, int x, int y);
void	ft_player_idle_move_draw(t_data *data, int x, int y);
void	ft_player_right_move_draw(t_data *data, int x, int y);
void	player_idle_animations(t_data *data, float x, float y);
void	player_left_animations(t_data *data, float x, float y);
void	player_jump_animations(t_data *data, float x, float y);
void	player_idle_left_animations(t_data *data, float x, float y);

#endif
