/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:49:33 by ssurilla          #+#    #+#             */
/*   Updated: 2023/03/25 18:30:03 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	printfdi(long long n);
int	printfh(unsigned long long n, int switcher, int counter);
int	ft_printf(const char *str, ...);
int	printfc(int c);

#endif