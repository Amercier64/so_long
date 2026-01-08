/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 08:46:44 by amercier          #+#    #+#             */
/*   Updated: 2025/10/22 09:10:55 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		res;
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	res = 0;
	while (i < n && res == 0)
	{
		res = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		i++;
	}
	return (res);
}
