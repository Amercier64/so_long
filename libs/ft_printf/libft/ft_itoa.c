/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:44:13 by amercier          #+#    #+#             */
/*   Updated: 2025/10/24 15:47:38 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		str_len;
	long	nbr;

	nbr = n;
	str_len = ft_getlen(nbr);
	str = malloc(sizeof(char) *(str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr)
	{
		str_len--;
		str[str_len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}
