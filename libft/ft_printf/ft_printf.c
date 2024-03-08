/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:03 by erramos           #+#    #+#             */
/*   Updated: 2023/11/13 18:07:20 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_id(char id, va_list args)
{
	int	len;

	len = 0;
	if (id == '%')
		len += ft_putchar('%');
	else if (id == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (id == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (id == 'd' || id == 'i')
		len += ft_printnb(va_arg(args, int));
	else if (id == 'x' || id == 'X')
		len += ft_printhex(id, va_arg(args, unsigned long long));
	else if (id == 'p')
		len += ft_printpoint(va_arg(args, unsigned long long));
	else if (id == 'u')
		len += ft_printu(va_arg(args, unsigned int));
	return (len);
}

int	check_last(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && check_last("cspdiuxX%", s[i + 1]))
		{
			len += check_id(s[i + 1], args);
			i++;
		}
		else
		{
			if (s[i] != '%')
				len += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main()
{
        char a = 'w';
        char *s = "Olá, mundo!";
	int	c;
	
	c = 155;
        ft_printf("pointer = %d // s = %s // c = %X // %% = %", 155, s, c);

        return 0;
}*/
