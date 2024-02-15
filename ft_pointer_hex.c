/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:11:59 by acalvet           #+#    #+#             */
/*   Updated: 2024/02/14 17:12:07 by acalvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len_pointer(unsigned	long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex_pointer(unsigned long long num, char format)
{
	if (num >= 16)
	{
		ft_put_hex_pointer(num / 16, format);
		ft_put_hex_pointer(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_printchar((num - 10 + 'a'));
			if (format == 'X')
				ft_printchar((num - 10 + 'A'));
		}
	}
}

int	ft_pointer_hex(unsigned long long num)
{
	char	format;
	int		dest;

	format = 'x';
	dest = 0;
	dest = ft_putstr("0x");
	if (num == 0)
		dest += ft_printchar('0');
	else
		ft_put_hex_pointer(num, format);
	return (ft_hex_len_pointer(num) + dest);
}
