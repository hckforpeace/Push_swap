/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:08:48 by pierre            #+#    #+#             */
/*   Updated: 2024/07/03 16:39:30 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static double	get_decimal(const char *num)
{
	double	decimal;
	int		zero;

	decimal = 0.0;
	zero = 0;
	if (!*num)
		return (0.0);
	if (*num == '.')
		num++;
	while (*num == '0')
	{
		zero++;
		num++;
	}
	decimal += ft_atoi(num);
	decimal /= ft_pow(10, numb_len(decimal, 10) + zero);
	return (decimal);
}

double	ft_atof(const char *string)
{
	double	result;
	double	decimal;
	int		is_neg;

	is_neg = 0;
	if (string[0] == '-')
		is_neg = 1;
	result = ft_atoi(&string[is_neg]);
	decimal = get_decimal(&string[numb_len(result, 10) + is_neg]);
	result += decimal;
	if (is_neg)
		return (result * -1);
	return (result);
}
