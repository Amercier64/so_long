/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:50 by amercier          #+#    #+#             */
/*   Updated: 2026/01/06 19:58:27 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Error\nWrong number of args");
		return (1);
	}

	// init
	//
	// init events -> <esc> [loop_end]
	//
	// loop
	//
	//
	// free
	// free
	// free


	int *ptr1 = NULL;
	int *ptr2 = NULL;


	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);



	(void)argv;
}



struct Window {
	int x;
	int *ptr;
	int *ptr1;
}

destroy_window(window *window) {
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
}
