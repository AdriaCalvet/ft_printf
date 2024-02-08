/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:30:54 by acalvet           #+#    #+#             */
/*   Updated: 2024/02/07 17:30:57 by acalvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Imprimeix un unic caracter i torna el valor 1 ja que nomes es un caracter
int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

//Imprimeix un a un cadascun dels caracters d'un string i retorna la mida
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	numberlen(int n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

void	end_read(char *str, int len)
{
	while (len >= 0)
	{
		ft_printchar(str[len]);
		len--;
	}
}

//Funcio per %u
char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = numberlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}
