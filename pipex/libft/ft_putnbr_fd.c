/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:44:17 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/18 11:27:36 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int digit)
{
	if (digit < 0)
		return (-digit);
	else
		return (digit);
}

static void	ft_putnbr_rec(int n, int fd)
{
	char	digit;

	if ((n < 10) && (n > -10))
	{
		digit = ft_abs(n) + '0';
		write(fd, &digit, 1);
		return ;
	}
	ft_putnbr_rec(n / 10, fd);
	digit = ft_abs(n % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_putnbr_rec(n, fd);
}
