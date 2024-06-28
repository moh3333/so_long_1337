/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:39:14 by mthamir           #+#    #+#             */
/*   Updated: 2024/06/18 20:24:35 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handling(t_game *game, char *er_type)
{
	int	i;

	i = 0;
	if (game)
	{
		if (game->map_l)
		{
			while (game->map_l[i])
			{
				free(game->map_l[i]);
				i++;
			}
			free(game->map_l);
			game->map_l = NULL;
		}
	}
	write (2, er_type, ft_strlen(er_type));
	exit(1);
}

void	check_other_char(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->hight && (*game).map_l[i])
	{
		j = 0;
		while ((*game).map_l[i][j])
		{
			if ((*game).map_l[i][j] == 'E' || (*game).map_l[i][j] == 'C'
				|| (*game).map_l[i][j] == 'P' || (*game).map_l[i][j] == '0'
					|| (*game).map_l[i][j] == '1')
				j++;
			else
				error_handling(game, "invalid element\n");
		}
		if (i == (game->hight - 1))
			break ;
		i++;
	}
}

void	check_len_lines(t_game	*game)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen((*game).map_l[i]);
	while (i < game->hight && (*game).map_l[i])
	{
		if (len != ft_strlen((*game).map_l[i]))
			error_handling(game, "invalid map ");
		i++;
	}
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	(*game).width = ft_strlen((*game).map_l[i]);
	while (i < (*game).hight)
	{
		j = 0;
		while (j < (*game).width)
		{
			if (i == 0 || i == ((*game).hight - 1))
				if (check_all_1((*game).map_l[i]))
					error_handling(game, "invalid map");
			if (check_first_and_last((*game).map_l[i][0])
				|| check_first_and_last((*game).map_l[i][(*game).width - 1]))
				error_handling(game, "invalid  map");
			j++;
		}
		i++;
	}
	return (0);
}

void	check_if_rectangular(t_game *game)
{
	if ((*game).hight == (*game).width)
		error_handling(game, "invalid map shape");
}
