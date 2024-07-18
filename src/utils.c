/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:01:14 by pierre            #+#    #+#             */
/*   Updated: 2024/07/06 14:08:39 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// determine if the number given from stack a is the biggest in stack b
int	is_max(int nbr, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (temp->next != b)
	{
		if (nbr < temp->num)
			return (0);
		temp = temp->next;
	}
	if (nbr < temp->num)
		return (0);
	return (1);
}

// determine if the number given from stack a is the smallest in stack b
int	is_min(int nbr, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (temp->next != b)
	{
		if (nbr > temp->num)
			return (0);
		temp = temp->next;
	}
	if (nbr > temp->num)
		return (0);
	return (1);
}

// returns the biggest number of the stack
int	get_max(t_stack *b)
{
	t_stack	*temp;
	int		max;

	max = b->num;
	temp = b;
	temp = temp->next;
	while (temp->next != b)
	{
		if (max < temp->num)
			max = temp->num;
		temp = temp->next;
	}
	if (max < temp->num)
		max = temp->num;
	return (max);
}

int	smallest(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	get_absolute(int value)
{
	if (value > 0)
		return (value);
	else
		return (value * -1);
}
