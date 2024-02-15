/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:21:02 by acalvet           #+#    #+#             */
/*   Updated: 2024/02/07 18:21:04 by acalvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
		ft_print_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_printchar(nb + 48);
		return ;
	}
	ft_printchar((nb % 10) + 48);
}

int	ft_print_unsigned(unsigned int nb)
{
	unsigned int	i;

	printout(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
