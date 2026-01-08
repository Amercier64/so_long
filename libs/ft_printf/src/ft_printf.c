/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:08:46 by amercier          #+#    #+#             */
/*   Updated: 2025/11/18 11:05:48 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printcs(const char *cs, va_list ap)
{
	size_t	len;

	len = 0;
	if (cs[1] == 's')
		len = print_s(ap);
	else if (cs[1] == 'c')
		len = print_c(ap);
	else if (cs[1] == 'd' || cs[1] == 'i')
		len = print_i(ap);
	else if (cs[1] == 'p')
		len = print_p(ap);
	else if (cs[1] == 'u')
		len = print_u(ap);
	else if (cs[1] == 'x' || cs[1] == 'X')
		len = print_x(ap, cs[1]);
	else if (cs[1] == '%')
		len = write(1, cs + 1, 1);
	return (len);
}

int	ft_printf(const char *fs, ...)
{
	size_t	len;
	va_list	ap;
	size_t	len_substr;
	char	*cs;

	if (fs == NULL)
		return (-1);
	va_start(ap, fs);
	len = 0;
	cs = ft_strchr(fs, '%');
	while (cs != NULL)
	{
		len_substr = cs - fs;
		write(1, fs, len_substr);
		len += len_substr + ft_printcs(cs, ap);
		fs = cs + 2;
		cs = ft_strchr(fs, '%');
	}
	len += ft_strlen(fs);
	ft_putstr_fd((char *)fs, 1);
	va_end(ap);
	return (len);
}
