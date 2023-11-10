/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthextype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:46 by anamieta          #+#    #+#             */
/*   Updated: 2023/11/10 14:03:06 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_longhex_fd(unsigned long value, int upper, int fd)
{
	char	*upperhex;
	char	*lowerhex;
	char	*hex_set;
	int		count;
	int		written;

	upperhex = "0123456789ABCDEF";
	lowerhex = "0123456789abcdef";
	if (upper)
		hex_set = upperhex;
	else
		hex_set = lowerhex;
	if (value > 15)
	{
		count = ft_longhex_fd(value / 16, upper, fd);
		if (count == -1)
			return (-1);
		written = write(fd, &hex_set[value % 16], 1);
		if (written == -1)
			return (-1);
		return (count + written);
	}
	else
		return (write(fd, &hex_set[value], 1));
}

int	ft_puthex(void *ptr, int upper, int isfaddress)
{
	int				written;

	written = 0;
	if (isfaddress == 1)
		written = write(1, "0x", 2);
	if (written == -1)
		return (-1);
	if (!ptr)
		return (written + write(1, "0", 1));
	if (isfaddress == 1)
		return (written + ft_longhex_fd((unsigned long)ptr, upper, 1));
	return (written + ft_longhex_fd((unsigned int)ptr, upper, 1));
}
