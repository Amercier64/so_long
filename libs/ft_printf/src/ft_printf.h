/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:38:36 by amercier          #+#    #+#             */
/*   Updated: 2026/01/05 15:33:54 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//libs
# include "libft.h"
# include <stdarg.h>
//structs
//custom functions
int	ft_printf(const char *fs, ...) __attribute__((format(printf, 1, 2)));
int	print_c(va_list ap);
int	print_s(va_list ap);
int	print_x(va_list ap, char cs);
int	print_i(va_list ap);
int	print_u(va_list ap);
int	print_p(va_list ap);
#endif
