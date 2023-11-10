/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:23:01 by anamieta          #+#    #+#             */
/*   Updated: 2023/11/10 14:03:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	written;

	written = write(fd, &c, sizeof(c));
	if (written == -1)
		return (-1);
	return (written);
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
	int	written;

	if (s == NULL)
		return (write(fd, "(null)", 6));
	len = ft_strlen(s);
	written = write(fd, s, len);
	if (written == -1)
		return (-1);
	return (written);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		written;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		written = ft_putchar_fd('-', fd);
		if (written == -1)
			return (-1);
		i = ft_putnbr_fd(-n, fd);
		return (i + 1);
	}
	if (n > 9)
	{
		i = ft_putnbr_fd(n / 10, fd);
		if (i == -1)
			return (-1);
		written = ft_putchar_fd(n % 10 + '0', fd);
		if (written == -1)
			return (-1);
		return (i + written);
	}
	return (ft_putchar_fd('0' + n, fd));
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
