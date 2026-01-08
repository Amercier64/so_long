/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:09:10 by amercier          #+#    #+#             */
/*   Updated: 2025/10/24 18:34:29 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getstart(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			set_len;
	char			*tmp;

	set_len = ft_strlen(set);
	start = 0;
	while (s1[start])
	{
		tmp = ft_memchr(set, s1[start], set_len);
		if (tmp == NULL)
			return (start);
		start++;
	}
	return (start);
}

static unsigned int	ft_getend(char const *s1, char const *set)
{
	unsigned int	end;
	size_t			set_len;
	char			*tmp;

	set_len = ft_strlen(set);
	end = ft_strlen(s1);
	while (end)
	{
		tmp = ft_memchr(set, s1[end - 1], set_len);
		if (tmp == NULL)
			return (end);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	len;
	unsigned int	start;
	unsigned int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	len = 0;
	if (end > start)
		len = end - start;
	str = ft_substr(s1, start, len);
	return (str);
}
