/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:34:18 by amercier          #+#    #+#             */
/*   Updated: 2025/11/18 11:12:15 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list ap)
{
	char	c;
	int		len;

	c = (char) va_arg(ap, int);
	len = write(1, &c, 1);
	return (len);
}

int	print_s(va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		len = 6;
		write(1, "(null)", len);
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}
