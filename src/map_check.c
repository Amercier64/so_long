/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:38:48 by amercier          #+#    #+#             */
/*   Updated: 2026/01/05 11:58:25 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map *map)
{
	check_size;
	check_set;
	check_struct
	{
		check_firstandlast_rows;
		check_firstandlast_columns;
	}
	check_lab
	{
		check_path_PtoC; loop while C;
		check_path_PtoE;
	}
}

//static check_size(t_map *map)
//{
//	int	y;
//
//	y = 0;
//	while(y < map->height)
//	{
//		if (ft_strlen(map->map[y]) != map->width)
//			return (1);
//		y++;
//	}
//	return (0);
//}

static int	check_set(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (c != '0' || c != '1' || c != 'P' || c != 'C' || c != 'E')
				return (1);
		}
		y++;
	}
	return (0);
}
