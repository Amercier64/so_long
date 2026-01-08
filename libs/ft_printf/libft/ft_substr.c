/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:22 by amercier          #+#    #+#             */
/*   Updated: 2025/10/24 18:31:55 by amercier         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		sub_len = 0;
	else
		sub_len = ft_getmin(s_len - start, len);
	sub = malloc(sizeof(char) * (sub_len + 1));
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, sub_len);
	sub[sub_len] = '\0';
	return (sub);
}
