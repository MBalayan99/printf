/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:07:38 by mbalayan          #+#    #+#             */
/*   Updated: 2023/02/14 22:08:54 by mbalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdlib.h>

int		ft_putstr(char *str);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putpointer(void *ptr);
int	    ft_putnbr_u(unsigned  int number);
int	    ft_check(char c, va_list macro);
int	    ft_putnbr_u(unsigned int n);
int	    ft_putnbr(int number);
char	*u_int_char(unsigned int n);
long int    ft_uperlower(void *ptr, char *s);
int ft_putnbr_base(unsigned int num, char *base);


#endif
