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
		print_lenght += ft_hex(va_arg(args, int), "0123456789abcdef");
	else if (format == 'd')
		print_lenght += ft_printnbr(va_arg(args, int), 0);
	else if (format == 'i')
		print_lenght += ft_printnbr(va_arg(args, int), 0);
	else if (format == 'u')
		print_lenght += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		print_lenght += ft_hex(va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		print_lenght += ft_hex(va_arg(args, int), "0123456789ABCDEF");
	else if (format == '%')
		print_lenght += ft_porcentaje(va_arg(args, char *));
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

int	main(void)
{
	//COMPROBACIONS nomes un caracter (%c)
	// printf(" \nResult length: %i\n", ft_printf("%c", 'c'));
	// printf(" \nResult length: %i\n", ft_printf("a"));
	// printf(" \nResult length: %i\n", ft_printf("%c", '2'));

	//COMPROBACIONS STRINGS (%s)
	//printf(" \nResult length: %i\n", ft_printf("%s", "hola"));
	//printf(" \nResult length: %i\n", ft_printf(" NULL %s NULL ", NULL));


	//COMPROBACIONS puntero (%p)
	// int x = 102;
    // printf("\nLa dirección de x es: %p\n", (void*)&x);

	//COMPROBACIONS numero decimal (%d)
	// printf(" \nResult length: %i\n", ft_printf("%d", 123));
	// printf(" \nResult length: %i\n", ft_printf("%d", -123));
	// printf(" \nResult length: %i\n", ft_printf("%d", +123));


	//COMPROBACIONS numero entero de base 10 (%i)
	// printf(" \nResult length: %i\n", ft_printf("%i", 123));
	// printf(" \nResult length: %i\n", ft_printf("%i", 12));
	// printf(" \nResult length: %i\n", ft_printf("%i", -1));
	// printf(" \nResult length: %i\n", ft_printf("%i", 1000));
	// printf(" \nResult length: %i\n", ft_printf("%i", 123));
	// printf(" \nResult length: %i\n", ft_printf("%i", +123)); //VIGILAR SI AQUEST ES CORRECTE


	// printf(" \nResult length: %i\n", ft_printf("%i", -960));
	// printf(" \nResult length: %i\n", ft_printf("%i", +960));
	// printf(" \nResult length: %i\n", ft_printf("%i", 0x122));
	// printf(" \nResult length: %i\n", ft_printf("%i", 0X9));
	// printf(" \nResult length: %i\n", ft_printf("%i", 03));

	//COMPROBACIONS numero decimal sense signe (%u) 	=> possiblement no funcioni amb negatius
	// printf(" \nResult length: %i\n", ft_printf("%u", 123));
	// printf(" \nResult length: %i\n", ft_printf("%u", -123));
	// printf(" \nResult length: %i\n", ft_printf("%u", +123));

	//COMPROBACIONS numero hexadecimal en minuscules (%x)
	printf(" \nResult length: %i\n", ft_printf("%x", 1));
	printf(" \nResult length: %i\n", ft_printf("%x", -1));
	printf(" \nResult length: %i\n", ft_printf("%x", 9));

	//COMPROBACIONS numero hexadecimal en majuscules (%X)
	//printf(" \nResult length: %i\n", ft_printf("%X", 960));

	//COMPROBACIONS simbol porcentatge (%%)
	//printf(" \nResult length: %i\n", ft_printf("%%", "20as"));




	return (0);
}