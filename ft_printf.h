/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvet <acalvet@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:44:34 by acalvet           #+#    #+#             */
/*   Updated: 2024/02/07 16:44:42 by acalvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//BORRAR STDIO QUAN ENTREGUI / ES PER FER PROVES
# include <stdio.h>

void	end_read(char *str, int n);
char	*ft_uitoa(unsigned int n);
int		ft_printf(char const *str, ...);
int		ft_hex(int n, char *base);
int		ft_print_unsigned(unsigned int n);
int		ft_porcentaje(char *str);
int		conversiones(va_list args, char const format);
int		ft_printchar(int c);
int		ft_putstr(char *str);
int		ft_printnbr(int nb, int mida);
int		numberlen(int n);
int		digit_counter(int n);
int		exp_counter(int n);
char	*ft_itoa(int n);
#endif
