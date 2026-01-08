/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:11:37 by amercier          #+#    #+#             */
/*   Updated: 2025/11/03 12:42:15 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_countwd(const char	*s, char c)
{
	unsigned int	wd_count;
	int				isword;

	if (s[0] == '\0')
		return (0);
	isword = 0;
	wd_count = 0;
	while (*s)
	{
		if (*s != c && !isword)
		{
			wd_count++;
			isword = 1;
		}
		else if (*s == c)
			isword = 0;
		s++;
	}
	return (wd_count);
}

static char	*ft_getwd(const char **s, char c, size_t len)
{
	char	*end;
	char	*wd;
	size_t	wd_len;

	end = ft_memchr(*s, c, len);
	if (end)
		wd_len = end - *s;
	else
		wd_len = len;
	wd = malloc(sizeof(char) * wd_len + 1);
	if (wd == NULL)
		return (NULL);
	ft_memcpy(wd, *s, wd_len);
	wd[wd_len] = '\0';
	*s = end;
	return (wd);
}

static int	ft_filltab(char const *s, char c, unsigned int wd_count,
		char **wd_arr)
{
	size_t			s_len;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	while (i < wd_count)
	{
		while (*s == c)
			s++;
		if (i == wd_count - 1)
		{
			s_len = ft_strlen(s);
			wd_arr[i] = ft_getwd(&s, c, s_len);
		}
		else
			wd_arr[i] = ft_getwd(&s, c, s_len);
		if (wd_arr[i] == NULL)
			return (0);
		i++;
	}
	wd_arr[i] = NULL;
	return (1);
}

static void	ft_free(char **wd_arr)
{
	while (*wd_arr)
	{
		free(*wd_arr);
		wd_arr++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**wd_arr;
	unsigned int	wd_count;

	if (s == NULL)
		return (NULL);
	wd_count = ft_countwd(s, c);
	wd_arr = malloc(sizeof(char *) * (wd_count + 1));
	if (wd_arr == NULL)
		return (NULL);
	if (!ft_filltab(s, c, wd_count, wd_arr))
	{
		ft_free(wd_arr);
		free(wd_arr);
		return (NULL);
	}
	return (wd_arr);
}
