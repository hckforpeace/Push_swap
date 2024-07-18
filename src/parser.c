/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:01:07 by pierre            #+#    #+#             */
/*   Updated: 2024/07/17 12:22:38 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_overflow(char *str)
{
	double	vald;
	int		vali;

	vald = ft_atof(str);
	vali = ft_atoi(str);
	if (str[0] == '-' && ft_strlen(str) > 11)
		return (1);
	else if (ft_strlen(str) > 10)
		return (1);
	if (vald != vali)
		return (1);
	return (0);
}

static int	contains_dup(char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (argv[i])
	{
		temp = argv[i];
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[j], temp))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parser(char **argv)
{
	if (contains_dup(argv))
		return (0);
	while (*argv)
	{
		if (is_integer(*argv) && !is_overflow(*argv))
			argv++;
		else
			return (0);
	}
	return (1);
}
