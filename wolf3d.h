/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:15:47 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/17 01:35:40 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "gnl/libft/libft.h"
# include "gnl/get_next_line.h"
# define X_WIN 1200
# define Y_WIN 800
# define S_MINI 141
# define TOP_CL 0x000000
# define BOT_CL 0x000000
# define ROT_SP 0.075

typedef struct	s_cast
{
	double			text_x;
	int				text_fx;
	int				text_fy;
	double			time;
	double			last_time;
	double			camera_x;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				touch;
	double			rngwall_x;
	double			rngwall_y;
	double			rngwall2_x;
	double			rngwall2_y;
	double			raydir_x;
	double			raydir_y;
	double			last_dir_x;
	double			dir_x;
	double			dir_y;
	double			last_plan_x;
	double			plan_x;
	double			plan_y;
	double			wall_len;
	int				witch_side;
	int				hght_wall;
	int				draw_str;
	int				draw_end;
	unsigned int	color;
}				t_cast;

typedef struct	s_ground
{
	double			f_wall_x;
	double			f_wall_y;
	double			weight;
	double			current_x;
	double			current_y;
	int				text_x;
	int				text_y;
	double			range_wall;
	double			range_player;
	double			current_range;
}				t_ground;

typedef struct	s_win
{
	int				bpp;
	int				sizeline;
	int				endian;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
}				t_win;

typedef struct	s_tex
{
	int		bpp;
	int		endian;
	int		sizeline;
	void	*img;
	char	*addr;
	int		x;
	int		y;
}				t_tex;

typedef struct	s_key
{
	char			up;
	char			down;
	char			left;
	char			right;
	char			fire_key;
	unsigned char	theme;
	unsigned char	fire;
	unsigned char	weap;
	char			ammo1;
	char			ammo2;
	float			rot;
	int				wait;
	char			help;
}				t_key;

typedef struct	s_menu
{
	t_tex		*t_1_g_1;
	t_tex		*t_1_g_1_f;
	t_tex		*t_1_g_2;
	t_tex		*t_1_g_2_f;

	t_tex		*t_2_g_1;
	t_tex		*t_2_g_1_f;
	t_tex		*t_2_g_2;
	t_tex		*t_2_g_2_f;

	t_tex		*t_3_g_1;
	t_tex		*t_3_g_1_f;
	t_tex		*t_3_g_2;
	t_tex		*t_3_g_2_f;

	t_tex		*t_4_g_1;
	t_tex		*t_4_g_1_f;
	t_tex		*t_4_g_2;
	t_tex		*t_4_g_2_f;

	t_tex		*t_5_g_1;
	t_tex		*t_5_g_1_f;
	t_tex		*t_5_g_2;
	t_tex		*t_5_g_2_f;
}				t_menu;

typedef struct	s_theme
{
	t_tex			*t1_floor;
	t_tex			*t1_wall;
	t_tex			*t1_roof;
	t_tex			*t1_sun;

	t_tex			*t2_floor;
	t_tex			*t2_wall;
	t_tex			*t2_roof;
	t_tex			*t2_sun;

	t_tex			*t3_floor;
	t_tex			*t3_wall;
	t_tex			*t3_roof;
	t_tex			*t3_sun;

	t_tex			*t4_floor;
	t_tex			*t4_wall;
	t_tex			*t4_roof;
	t_tex			*t4_sun;

	t_tex			*t5_floor;
	t_tex			*t5_wall;
	t_tex			*t5_roof;
	t_tex			*t5_sun;

}				t_theme;

typedef struct	s_wolf
{
	int			sky_x;
	char		**map;
	int			y_max;
	int			x_max;
	char		blank;
	char		wall;
	char		block;
	t_cast		*cast;
	t_win		*mlx;

	t_key		*key;
	t_ground	*ground;

	t_tex		*mini_map;
	t_tex		*sun;
	t_tex		*dyke;
	t_tex		*floor;
	t_tex		*cloud;
	t_tex		*interface;
	t_tex		*ammo;

	t_menu		*menu;
	t_theme		*theme;

	int			r_player;
	double		x_player;
	double		y_player;

	int			face_bpp;
	int			face_endian;
	int			face_sizeline;
	void		*face;
	char		*face_addr;
	int			face_x;
	int			face_y;
}				t_wolf;

int				keycode_ch(int keycode);
int				menu_to_xpm_theme_img_1(t_menu *menu, t_win *win);
int				menu_to_xpm_theme_img_2(t_menu *menu, t_win *win);
int				menu_to_xpm_theme_img_3(t_menu *menu, t_win *win);
int				menu_to_xpm_theme_img(t_menu *menu, t_win *win);
void			menu_to_xpm_theme_addr_1(t_menu *menu);
void			menu_to_xpm_theme_addr_2(t_menu *menu);
void			menu_to_xpm_theme_addr(t_menu *menu);
void			menu_to_xpm(t_wolf *wolf);
int				theme_to_xpm_theme_img_1(t_theme *theme, t_win *win);
int				theme_to_xpm_theme_img_2(t_theme *theme, t_win *win);
int				theme_to_xpm_theme_img_3(t_theme *theme, t_win *win);
int				theme_to_xpm_theme_img(t_theme *theme, t_win *win);
void			theme_to_xpm_theme_addr_1(t_theme *theme);
void			theme_to_xpm_theme_addr_2(t_theme *theme);
void			theme_to_xpm_theme_addr(t_theme *theme);
void			theme_to_xpm(t_wolf *wolf);
void			xpm_to_img(t_wolf *wolf);
unsigned int	get_img_color_xpm_tex(int x, int y, t_tex *tex);
void			img_add_px(t_win *mlx, unsigned int color, int x, int y);
void			img_add_px_2(t_tex *tex, unsigned int color, int x, int y);
int				ft_produit_en_x(int max1, int max2, int i1);
char			first_line(int fd, t_wolf *wolf);
int				close_and_free_1(int fd, char *str, int ret);
unsigned int	color_fade(unsigned int color, int percent);
void			malloc_map_intra(t_wolf *wolf);
void			ft_minimap_x_y(t_wolf *wolf, int *x_mini, int *y_mini);
void			str_map_intra(char *str, t_wolf *wolf, int y);
void			put_vertical_line(int x, t_cast *cast, t_wolf *wolf,
		t_win *mlx);
double			get_angle(double x, double y);
double			apply_roof_2(double r_sun);
void			apply_roof(int x, t_wolf *wolf, t_cast *cast);
void			apply_floor_1(t_ground *ground, t_cast *cast);
void			apply_floor(int x, t_wolf *wolf, t_cast *cast);
void			true_raycast_1(t_wolf *wolf, t_cast *cast, int x);
void			true_raycast_2(t_wolf *wolf, t_cast *cast);
void			true_raycast_3(t_wolf *wolf, t_cast *cast);
void			true_raycast_4(t_wolf *wolf, t_cast *cast, int x, t_win *mlx);
void			true_raycast(t_wolf *wolf, t_win *mlx);
void			wiew_mini_map_1(t_wolf *wolf, t_tex *tex, int x[2], int y[2]);
void			wiew_mini_map(t_wolf *wolf, t_tex *tex);
int				is_true_first_line(char *line, t_wolf *wolf, int fd);
int				is_true_middle(char *line, t_wolf *wolf, int fd, int *nb_play);
int				is_true_last(char *line, t_wolf *wolf, int fd);
char			is_true_map_1(t_wolf *wolf, char *line, int fd,
		int y_and_nb_play[2]);
char			is_true_map(char **argv, t_wolf *wolf);
void			which_key_2_1(t_cast *cast);
int				which_key_2(int keycode, t_wolf *wolf);
void			which_key_42(t_cast *cast, int keycode);
int				which_key(int keycode, t_wolf *wolf);
double			move_player_1(t_wolf *wolf, t_cast *cast,
		double nobug, t_key *key);
void			move_player_2(t_cast *cast, t_key *key);
void			move_player(t_wolf *wolf);
void			modif_interface(t_wolf *wolf, t_key *key);
void			modif_theme_1(t_wolf *wolf, t_key *key);
void			modif_theme(t_wolf *wolf, t_key *key);
void			press_key_1(int keycode, t_key *key);
void			press_key_2(int keycode, t_key *key, t_wolf *wolf);
int				press_key(int keycode, t_wolf *wolf);
int				release_key(int keycode, t_wolf *wolf);
void			apply_ammo(t_wolf *wolf, int ammo);
void			modif_interface_ammo(t_wolf *wolf, t_key *key);
void			print_help(t_wolf *wolf, int x, int y, char *msg);
void			infinity_loop_1(t_wolf *wolf, t_key *key);
int				infinity_loop(t_wolf *wolf);
void			setup_key(t_wolf *wolf);
int				malloc_menu_3(t_wolf *wolf);
int				malloc_menu_2(t_wolf *wolf);
int				malloc_menu_1(t_wolf *wolf);
int				malloc_theme_3(t_wolf *wolf);
int				malloc_theme_2(t_wolf *wolf);
int				malloc_theme_1(t_wolf *wolf);
int				eteindre(void);
int				main_1(t_wolf *wolf, char **argv);
void			help(void);
#endif
