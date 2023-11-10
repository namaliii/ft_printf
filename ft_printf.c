/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:39:57 by anamieta          #+#    #+#             */
/*   Updated: 2023/11/10 14:03:01 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *args, char fmt)
{
	if (fmt == 'c')
		return (ft_putchar_fd((unsigned char)va_arg(*args, int), 1));
	else if (fmt == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	else if (fmt == 'p')
		return (ft_puthex(va_arg(*args, void *), 0, 1));
	else if (fmt == 'i' || fmt == 'd')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (fmt == 'u')
		return (ft_putunsignednbr_fd(va_arg(*args, unsigned int), 1));
	else if (fmt == 'x')
		return (ft_puthex(va_arg(*args, void *), 0, 0));
	else if (fmt == 'X')
		return (ft_puthex(va_arg(*args, void *), 1, 0));
	else if (fmt == '%' )
		return (write(1, "%", 1));
	return (0);
}

static int	formatted_output(const char *str, va_list *args)
{
	int	i;
	int	len;
	int	written;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			written = ft_format(args, str[i]);
			if (written == -1)
				return (-1);
			len += written;
		}
		else
		{
			written = write(1, &str[i], 1);
			if (written == -1)
				return (-1);
			len += written;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = formatted_output(str, &args);
	va_end(args);
	return (len);
}

// How does the function get to the one character after % we are looking for?

// #include "ft_printf.h"
// #include <stdio.h>

// int main(void)
// {
//     int myprintf;
//     int sys_fun;
//     myprintf = ft_printf("%s --- %d Output of my function: %x\n", 44096);
//     sys_fun = printf("%s --- %d Output of sy function: %x\n", 44096);
//     printf("My function: %d\n", myprintf);
//     printf("System function: %d\n", sys_fun);
//     return (0);
// }