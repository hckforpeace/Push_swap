/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:01:16 by pierre            #+#    #+#             */
/*   Updated: 2024/07/07 19:40:28 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stck_swap(t_stack **stack, char c)
{
	int	temp;

	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	if (stck_len(stack) < 2)
		return ;
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
}

t_stack	*stck_pop(t_stack **stack)
{
	t_stack	*pop;

	if (!*stack)
		return (NULL);
	if ((*stack)->next == (*stack))
	{
		pop = *stack;
		*stack = NULL;
		return (pop);
	}
	pop = *stack;
	(pop->next)->prev = pop->prev;
	(pop->prev)->next = pop->next;
	*stack = pop->next;
	pop->next = pop;
	pop->prev = pop;
	return (pop);
}

void	stck_push(t_stack **dest, t_stack **src, char c)
{
	t_stack	*pop;

	if (c == 'a' || c == 'b')
		ft_printf("p%c\n", c);
	if (stck_len(src) == 0)
		return ;
	pop = stck_pop(src);
	stck_addfst(dest, pop);
}

int	stck_len(t_stack **stack)
{
	int		len;
	t_stack	*temp;

	if (!*stack)
		return (0);
	temp = (*stack)->next;
	len = 1;
	while (temp != *stack)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	stck_rotate(t_stack **stack, int sens, int c)
{
	if (!*stack)
		return ;
	if (sens == R)
	{
		if (c == 'a' || c == 'b')
			ft_printf("r%c\n", c);
		(*stack) = (*stack)->next;
	}
	else if (sens == RR)
	{
		if (c == 'a' || c == 'b')
			ft_printf("rr%c\n", c);
		(*stack) = (*stack)->prev;
	}
}
