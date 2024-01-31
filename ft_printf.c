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

#include "printf.h"
#include "stdarg.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

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
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return(i);
}

int	ft_putnbr(int nb, int mida)
{

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return 0;
	}
	else if (nb == 2147483647)
	{
		write (1, "2147483647", 10);
		return 0;
	}
	else if (nb >= 10)
	{
		mida += ft_putnbr(nb / 10, mida);
		ft_putnbr(nb % 10, mida);
		mida++;
	}
	else if (nb < 0)
	{
		mida += ft_printchar('-');
		ft_putnbr(-nb, mida++);
	}
	else
	{
		mida += ft_printchar(nb + '0');
	}
	return (mida);
}

int numberlen(int n)
{
	int digits;

	digits = 0;
	while(n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}
//Falta calcular llargada del numero per posar en el while
//Falta posar el malloc
int	ft_hex(int n, char *base)
{
	int	i;
	int caracter;
	int digits;
	char	*str;

	i = 0;
	//digits = ft_putnbr(n,0);
	digits = numberlen(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	printf("\nMida del numero: %d\n", digits);
	while(i < digits)
	{
		if (n > 9)
		{
			caracter = n % 16;
			str[digits - i - 1] = base[caracter];
			//ft_printchar(caracter);
			n = n / 16;
		}
		else
		{
			//ft_printchar(base[n]);
			str[i] = base[n];
			break;
		}
		i++;
	}
	str[i] = '\0';

	return (ft_putstr(str));
}

//Comproba quin es el tipus de conversio que es fara
int	conversiones(va_list args, char const format)
{
	int	print_lenght;

	print_lenght = 0;
	if(format == 'c')
		print_lenght += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_lenght += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		return 0;
	else if (format == 'd')
		print_lenght += ft_putnbr(va_arg(args, int), 0);
	//Se li passa l'argument i la mida que te per ara el numero (en un principi es 0)
	else if (format == 'i')
		print_lenght += ft_putnbr(va_arg(args, int), 0);
	else if (format == 'u')
		return 0;
	else if (format == 'x')
		return 0;
	else if (format == 'X')
		print_lenght += ft_hex(va_arg(args, int), "0123456789ABCDEF");
	else if (format == '%')
		return 0;
	return (print_lenght);
}

//
int	ft_printf(char const *str, ...)
{
	va_list args;
	int	i;
	int	print_lenght;

	i = 0;
	print_lenght = 0;
	va_start(args, str);
	while(str[i])
	{
		//Comprobem si el parametre es una conversio o nomes un caracter. 
		//En cas que sigui un caracter el mostrem i incrementem la variable print_lenght. 
		//En cas que sigui una conversio, enviem el seguent caracter que sera la lletra descriptora i el va_list args.
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

	//COMPROBACIONS puntero (%p)

	//COMPROBACIONS numero decimal (%d)

	//COMPROBACIONS numero entero de base 10 (%i)
	// printf(" \nResult length: %i\n", ft_printf("%i", 123));
	// printf(" \nResult length: %i\n", ft_printf("%i", 12));
	// printf(" \nResult length: %i\n", ft_printf("%i", -1));
	// printf(" \nResult length: %i\n", ft_printf("%i", 1000));
	// printf(" \nResult length: %i\n", ft_printf("%i", 123));
	// printf(" \nResult length: %i\n", ft_printf("%i", +123)); //VIGILAR SI AQUEST ES CORRECTE

	//COMPROBACIONS numero decimal sense signe (%u)

	//COMPROBACIONS numero hexadecimal en minuscules (%x)

	//COMPROBACIONS numero hexadecimal en majuscules (%X)
	printf(" \nResult length: %i\n", ft_printf("%X", 1800));
	printf(" \n--------------------------------\n");
	printf(" \nResult length: %i\n", ft_printf("%X", 12));
		printf(" \n--------------------------------\n");
	printf(" \nResult length: %i\n", ft_printf("%X", 960));


	//COMPROBACIONS simbol porcentatge (%%)



	return (0);
}