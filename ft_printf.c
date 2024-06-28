/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:08:26 by mthamir           #+#    #+#             */
/*   Updated: 2024/06/18 22:20:04 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		s += write (1, &str[i], 1);
		i++;
	}
	return (s);
}

int	ft_putint(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (write (1, "-2147483648", 11));
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		i++;
	}
	if (nbr <= 9)
		i += ft_putchar(nbr + 48);
	if (nbr > 9)
	{
		i += ft_putint(nbr / 10);
		i += ft_putchar((nbr % 10) + 48);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			format++;
			if (*format == 'd' || *format == 'd')
				i += ft_putint(va_arg(ap, int));
			else if (*format == 's')
				i += ft_putstr(va_arg(ap, char *));
			else
				i += ft_putchar(*format);
		}
		else if (*format != '%')
			i += write (1, format, 1);
		format++;
	}
	va_end(ap);
	return (i);
}
