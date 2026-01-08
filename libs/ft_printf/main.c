/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:28:02 by amercier          #+#    #+#             */
/*   Updated: 2025/11/18 11:08:49 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char	*str = NULL;
	int	a = 12;
	printf("%d printf\n", printf("%c\n", ' '));
	printf("%d ft_printf\n", ft_printf("%c\n", ' '));
	printf("%d printf\n", printf("%s\n", "test"));
	printf("%d ft_printf\n", ft_printf("%s\n", "test"));
	printf("%d printf\n", printf("%s\n", str));
	printf("%d ft_printf\n", ft_printf("%s\n", str));
	printf("%d printf\n", printf("%d\n", 12356123));
	printf("%d ft_printf\n", ft_printf("%d\n", 12356123));
	printf("%d printf\n", printf("%x\n", 42));
	printf("%d ft_printf\n", ft_printf("%x\n", 42));
	printf("%d printf\n", printf("%X\n", 42));
	printf("%d ft_printf\n", ft_printf("%X\n", 42));
	printf("%d printf\n", printf("%u\n", -42));
	printf("%d ft_printf\n", ft_printf("%u\n", -42));
	printf("%d printf\n", printf("%p\n", str));
	printf("%d ft_printf\n", ft_printf("%p\n", str));
	printf("%d printf\n", printf("%p\n", &a));
	printf("%d ft_printf\n", ft_printf("%p\n", &a));
}
