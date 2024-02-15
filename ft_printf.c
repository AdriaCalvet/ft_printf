/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:23:56 by acalvet           #+#    #+#             */
/*   Updated: 2024/01/31 11:23:59 by acalvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Comproba quin es el tipus de conversio que es fara
int	conversiones(va_list args, char const format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_lenght += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_lenght += ft_pointer_hex(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_lenght += ft_printnbr(va_arg(args, int), 0);
	else if (format == 'u')
		print_lenght += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		print_lenght += ft_hex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		print_lenght += ft_hex(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		print_lenght += ft_porcentaje();
	return (print_lenght);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		print_lenght;

	i = 0;
	print_lenght = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_lenght += conversiones(args, str[i + 1]);
			i++;
		}
		else
			print_lenght += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_lenght);
}
