/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:31:38 by amercier          #+#    #+#             */
/*   Updated: 2026/01/03 13:41:11 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Exit program correctly, and frees everything.
 */
int	exit_ok(void *param)
{
	t_game *game = param;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

//int exit_ko(void *param)
//{
//	
//}
