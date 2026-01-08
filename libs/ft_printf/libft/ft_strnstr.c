/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:19:14 by amercier          #+#    #+#             */
/*   Updated: 2025/10/22 15:49:50 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;
	size_t	i;

	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && (i < len) && (little_len <= big_len - i)
		&& little_len <= len - i)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
