/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:25:42 by amercier          #+#    #+#             */
/*   Updated: 2025/10/24 18:32:59 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, str_len + 1);
	ft_strlcat(str, s2, str_len + 1);
	return (str);
}
