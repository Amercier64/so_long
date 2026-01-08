/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:45:44 by amercier          #+#    #+#             */
/*   Updated: 2026/01/02 13:42:12 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strlcpy_not(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL)
	{
		dest[i] = '\0';
		return ;
	}
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	*ft_strjoin_not(char **str, char *buf, size_t size)
{
	char	*tmp;
	size_t	len;

	len = 0;
	if (*str)
		len = ft_strlen(*str);
	tmp = malloc(sizeof(char) * len + size + 1);
	if (tmp == NULL)
	{
		free(*str);
		return (NULL);
	}
	ft_strlcpy_not(tmp, *str, len);
	ft_strlcpy_not(tmp + len, buf, size);
	free(*str);
	return (tmp);
}

static size_t	ft_get_eol(int *is_eol, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*is_eol = 1;
			return (i + 1);
		}
		i++;
	}
	return (i);
}

static int	ft_popbuf(char *buf, char **str)
{
	size_t		size;
	int			is_eol;

	is_eol = 0;
	size = ft_get_eol(&is_eol, buf);
	*str = ft_strjoin_not(str, buf, size);
	ft_strlcpy_not(buf, buf + size, BUFFER_SIZE);
	if (*str == NULL)
		is_eol = -1;
	return (is_eol);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*str;
	static char	buf[BUFFER_SIZE + 1] = {0};
	int			is_eol;

	str = NULL;
	is_eol = 0;
	if (buf[0] != '\0')
		is_eol = ft_popbuf(buf, &str);
	while (!is_eol)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
		else if (bytes_read == 0)
			return (str);
		buf[bytes_read] = '\0';
		is_eol = ft_popbuf(buf, &str);
	}
	if (is_eol == -1)
		return (NULL);
	return (str);
}
