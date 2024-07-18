/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:59:58 by pierre            #+#    #+#             */
/*   Updated: 2024/07/18 14:53:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int num)
{
	struct s_stack	*node;

	node = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!node)
		return (NULL);
	node->next = node;
	node->prev = node;
	node->num = num;
	return (node);
}

void	stck_addlst(t_stack **stack, t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	if (!*stack)
	{
		*stack = lst;
		lst->next = lst;
		lst->prev = lst;
	}
	else
	{
		temp = (*stack)->prev;
		temp->next = lst;
		lst->prev = temp;
		lst->next = *stack;
		(*stack)->prev = lst;
	}
}

void	stck_addfst(t_stack **stack, t_stack *fst)
{
	t_stack	*temp;

	temp = *stack;
	if (!fst)
		return ;
	if (!*stack)
	{
		*stack = fst;
		fst->next = fst;
		fst->prev = fst;
	}
	else
	{
		temp = (*stack)->prev;
		fst->next = (*stack);
		fst->prev = temp;
		temp->next = fst;
		(*stack)->prev = fst;
		*stack = fst;
	}
}

void	stck_clr(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	temp = (*stack)->next;
	if (stck_len(stack) == 1)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	while (temp != *stack)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	*stack = NULL;
}

int	count_words(char **wordlist)
{
	int	len;

	if (!wordlist)
		return (0);
	len = 0;
	while (*wordlist)
	{
		len++;
		wordlist++;
	}
	return (len);
}
