/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:23:01 by anamieta          #+#    #+#             */
/*   Updated: 2023/11/09 19:04:25 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, sizeof(c)));
}

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return (write(fd, "(null)", 6));
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	int		i;

	if (n == -2147483648)
	{
		return (ft_putstr_fd("-2147483648", fd));
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = ft_putnbr_fd(-n, fd);
		return (i + 1);
	}
	if (n > 9)
	{
		i = ft_putnbr_fd(n / 10, fd);
		digit = n % 10 + '0';
		return (i + ft_putchar_fd(digit, fd));
	}
	digit = '0' + n;
	return (ft_putchar_fd(digit, fd));
}

int	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	int		count;
	char	c;
	int		written;

	if (n > 9)
	{
		count = ft_putunsignednbr_fd(n / 10, fd);
		if (count == -1)
			return (-1);
		c = '0' + n % 10;
		written = write(fd, &c, 1);
		if (written == -1)
			return (-1);
		return (count + written);
	}
	else
	{
		c = '0' + n;
		return (write(fd, &c, 1));
	}
}
