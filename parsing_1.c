/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:55:52 by mthamir           #+#    #+#             */
/*   Updated: 2024/06/18 21:34:31 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_one(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

void	ft_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	if (s)
		free(s);
}

char	**fake_map(t_game game)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = (char **) malloc ((game.hight + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	while (i < game.hight)
	{
		j = 0;
		s[i] = (char *) malloc ((game.width + 1));
		if (!s[i])
		{
			ft_free(s, i);
			exit(1);
		}
		while (j++ < game.width - 1)
			s[i][j] = '0';
		s[i][j] = '\0';
		i++;
	}
	s[i] = NULL;
	return (s);
}

int	check_the_path_for_coins(int x, int y, t_game *game, char **matrix)
{
	if (game->map_l[y][x] == '1'
		|| game->map_l[y][x] == 'E'
			|| matrix[y][x] == 'v')
		return (0);
	if (game->map_l[y][x] == 'C')
		game->c--;
	matrix[y][x] = 'v';
	if (game->c == 0)
	{
		ft_free(matrix, game->hight);
		return (1);
	}
	if (check_the_path_for_coins((x + 1), y, game, matrix))
		return (1);
	if (check_the_path_for_coins((x - 1), y, game, matrix))
		return (1);
	if (check_the_path_for_coins(x, (y + 1), game, matrix))
		return (1);
	if (check_the_path_for_coins(x, (y - 1), game, matrix))
		return (1);
	return (0);
}

int	check_the_path_for_exit(int x, int y, t_game *game, char **matrix)
{
	if (game->map_l[y][x] == '1' || matrix[y][x] == 'v')
		return (0);
	if (game->map_l[y][x] == 'E')
		game->e--;
	matrix[y][x] = 'v';
	if (game->e == 0)
	{
		ft_free(matrix, game->hight);
		return (1);
	}
	if (check_the_path_for_exit((x + 1), y, game, matrix))
		return (1);
	if (check_the_path_for_exit((x - 1), y, game, matrix))
		return (1);
	if (check_the_path_for_exit(x, (y + 1), game, matrix))
		return (1);
	if (check_the_path_for_exit(x, (y - 1), game, matrix))
		return (1);
	return (0);
}
