/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:55:57 by mbalayan          #+#    #+#             */
/*   Updated: 2023/02/18 22:43:36 by mbalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include<stdio.h>

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	ret;
	int				res;

	ret = (unsigned long long)ptr;
	res = 0;
	if (ret > 15)
		res += ft_putpointer((void *)(ret / 16));
	res += ft_putchar("0123456789abcdef"[ret % 16]);
	return (res);
}

int	ft_putnbr(int number)
{
	char	*num;
	int		len;

	len = 0;
	num = ft_itoa(number);
	len += ft_putstr(num);
	free(num);
	return (len);
}

char	*u_int_char(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	tmp = n;
	len = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
