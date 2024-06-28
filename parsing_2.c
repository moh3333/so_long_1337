/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:18:54 by mthamir           #+#    #+#             */
/*   Updated: 2024/06/14 22:58:21 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_p_c_e(t_game	*game, int i, int j)
{
	while ((*game).map_l[i])
	{
		j = 0;
		while ((*game).map_l[i][j])
		{
			if ((*game).map_l[i][j] == 'E')
				(*game).e++;
			if ((*game).map_l[i][j] == 'C')
				(*game).c++;
			if ((*game).map_l[i][j] == 'P')
			{
				(*game).x_p = j;
				(*game).y_p = i;
				(*game).p++;
			}
			j++;
		}
		i++;
	}
	game->c0 = game->c;
	if ((*game).c >= 1 && (*game).e == 1 && (*game).p == 1)
		return (0);
	return (1);
}

int	ft_strcmpr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_all_1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_first_and_last(char c)
{
	if (c == '1')
		return (0);
	return (1);
}

void	remove_new_line(t_game	*game, int i)
{
	int	j;

	j = 0;
	while ((*game).map_l[i][j])
	{
		if ((*game).map_l[i][j] == '\n')
			(*game).map_l[i][j] = '\0';
		j++;
	}
}
