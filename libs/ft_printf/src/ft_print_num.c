/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:54:51 by amercier          #+#    #+#             */
/*   Updated: 2026/01/05 15:34:51 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	char	to_print[64];
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(base);
	if (nbr == 0)
	{
		to_print[63] = '0';
		i++;
	}
	while (nbr)
	{
		to_print[63 - i] = base[nbr % len];
		nbr /= len;
		i++;
	}
	i = write(1, to_print + (64 - i), i);
	return (i);
}

int	print_p(va_list ap)
{
	unsigned long	arg;
	int				len;

	len = 0;
	arg = (unsigned long)va_arg(ap, void *);
	if (arg == 0)
		len = write(1, "(nil)", 5);
	else
	{
		len = write(1, "0x", 2);
		len += ft_putnbr_base(arg, "0123456789abcdef");
	}
	return (len);
}

int	print_x(va_list ap, char cs)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(ap, unsigned int);
	if (cs == 'x')
		len = ft_putnbr_base(arg, "0123456789abcdef");
	else
		len = ft_putnbr_base(arg, "0123456789ABCDEF");
	return (len);
}

int	print_u(va_list ap)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(ap, unsigned int);
	len = ft_putnbr_base(arg, "0123456789");
	return (len);
}

int	print_i(va_list ap)
{
	long	arg;
	int		len;

	arg = (long)va_arg(ap, int);
	len = 0;
	if (arg < 0)
	{
		len = write(1, "-", 1);
		arg *= -1;
	}
	len += ft_putnbr_base(arg, "0123456789");
	return (len);
}
