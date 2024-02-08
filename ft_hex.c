/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:21:22 by acalvet           #+#    #+#             */
/*   Updated: 2024/02/07 18:21:29 by acalvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(int n, char *base)
{
	int		i;
	int		digits;
	char	*str;

	i = 0;
	digits = numberlen(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	while (i < digits)
	{
		if (n > 16)
		{
			str[i] = base[n % 16];
			n = n / 16;
		}
		else
		{
			str[i++] = base[n];
			break ;
		}
		i++;
	}
	str[i] = '\0';
	end_read(str, i);
	free(str);
	return (i);
}
