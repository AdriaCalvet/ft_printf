/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_porcentaje.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:21:10 by acalvet           #+#    #+#             */
/*   Updated: 2024/02/07 18:21:13 by acalvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Funcion porcentage
int	ft_porcentaje(char *str)
{
	int	print_lenght;

	print_lenght = 0;
	print_lenght += ft_putstr(str);
	print_lenght += ft_printchar('%');
	return (print_lenght);
}
