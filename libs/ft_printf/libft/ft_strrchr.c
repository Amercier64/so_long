/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:30:50 by amercier          #+#    #+#             */
/*   Updated: 2025/10/21 20:46:33 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(s);
	while (len > 0 && ((unsigned char *)s)[len] != (unsigned char)c)
		len--;
	if (len == 0 && ((unsigned char *)s)[len] != (unsigned char)c)
		return (NULL);
	ret = (char *)s + len;
	return (ret);
}
