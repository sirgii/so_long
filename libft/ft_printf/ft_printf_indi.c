/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_indi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:44:22 by ssurilla          #+#    #+#             */
/*   Updated: 2023/03/25 18:29:40 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(unsigned long long digit)
{
	if (digit > 9)
	{
		putnbr(digit / 10);
		putnbr(digit % 10);
	}
	else
	{
		printfc(digit + '0');
	}
}

int	printfdi(long long n)
{
	int	counter;

	if (n < 0)
	{
		counter = 1;
		write(1, "-", 1);
		n = n * -1;
	}
	else
		counter = 0;
	if (n == 0)
		counter++;
	putnbr(n);
	while (n != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
