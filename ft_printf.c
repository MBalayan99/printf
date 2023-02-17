/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:50:57 by mbalayan          #+#    #+#             */
/*   Updated: 2023/02/14 21:55:40 by mbalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list macro)
{
	if (c == 'c')
		return (ft_putchar(va_arg(macro, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(macro, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putpointer(va_arg(macro, void *)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(macro, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(macro, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
    	return (ft_putnbr_base(va_arg(macro, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(macro, unsigned int), "0123456789ABCDEF"));
	return (0);
}


int	ft_putnbr_u(unsigned  int number)
{
	char	*num;
	int		len;

	len = 0;
	num = u_int_char(number);
	len += ft_putstr(num);
	free(num);
	return (len);
}
/*
  long int	ft_uperlower(void *ptr, char *s)
{
	unsigned long 	ret;
	unsigned  long int				res;

	ret = (unsigned long)ptr;
	res = 0;
	if (ret > 15)
		res += ft_putpointer((void *)(ret / 16));
	res += ft_putchar(s[ret % 16]);
	return (res);
	
}
*/

int	ft_printf(const char *s, ...)
{
	va_list	macro;
	int		i;
	int		len;

	va_start(macro, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_check(s[i + 1], macro);
			i++;
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(macro);
	return (len);
}
