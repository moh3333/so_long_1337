/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:16:55 by mthamir           #+#    #+#             */
/*   Updated: 2024/06/19 16:50:46 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	direction(t_game *game, int x, int y)
{
	int	old_x;
	int	old_y;
	int	s[2];

	if (game->map_l[y][x] == '1' || (game->map_l[y][x] == 'E' && game->c0 != 0))
		return (1);
	old_x = game->x_p * 50;
	old_y = game->y_p * 50;
	if (game->map_l[y][x] == 'C')
		game->c0--;
	if (game->map_l[y][x] == 'E' && game->c0 == 0)
		free_map(game);
	game->map_l[y][x] = 'P';
	game->map_l[game->y_p][game->x_p] = '0';
	game->x_p = x;
	game->y_p = y;
	s[0] = game->x_p * 50;
	s[1] = game->y_p * 50;
	game->moves++;
	mlx_put_image_to_window(game->mlx, game->win, game->b_g, old_x, old_y);
	mlx_put_image_to_window(game->mlx, game->win, game->player, s[0], s[1]);
	ft_printf("moves number : %d\n", game->moves);
	return (0);
}

int	move(int key, t_game *game)
{
	if (key == 53)
		free_map(game);
	else if (key == 126)
		direction(game, game->x_p, (game->y_p - 1));
	else if (key == 125)
		direction(game, game->x_p, (game->y_p + 1));
	else if (key == 124)
		direction(game, (game->x_p + 1), game->y_p);
	else if (key == 123)
		direction(game, (game->x_p - 1), game->y_p);
	return (0);
}

int	x_click(t_game *game)
{
	free_map(game);
	return (0);
}

int	ft_loop(t_game *game)
{
	mlx_hook(game->win, 17, 0, x_click, game);
	mlx_hook(game->win, 2, 0, move, game);
	return (0);
}

void	init_images(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	game->player = mlx_xpm_file_to_image(game->mlx, "./textures/p.xpm", &a, &b);
	if (!game->player)
		error_handling(game, "invalid image\n");
	game->b_g = mlx_xpm_file_to_image(game->mlx, "./textures/g.xpm", &a, &b);
	if (!game->b_g)
		error_handling(game, "invalid image\n");
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/d.xpm", &a, &b);
	if (!game->exit)
		error_handling(game, "invalid image\n");
	game->coin = mlx_xpm_file_to_image(game->mlx, "./textures/c.xpm", &a, &b);
	if (!game->coin)
		error_handling(game, "invalid image\n");
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/w.xpm", &a, &b);
	if (!game->wall)
		error_handling(game, "invalid image\n");
}
