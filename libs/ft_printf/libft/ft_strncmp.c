/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:19:22 by amercier          #+#    #+#             */
/*   Updated: 2025/11/03 12:39:09 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getmin(size_t x, size_t y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	nb;
	int		ret;

	nb = ft_getmin(ft_strlen(s1), ft_strlen(s2)) + 1;
	nb = ft_getmin(nb, n);
	ret = ft_memcmp(s1, s2, nb);
	return (ret);
}
