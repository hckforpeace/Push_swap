/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:17:31 by pierre            #+#    #+#             */
/*   Updated: 2024/07/18 11:24:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_aux(t_stack *s2, int len2)
{
	while (len2 > 0)
	{
		ft_printf(" %d\n", s2->num);
		s2 = s2->next;
		len2--;
	}
}

void	display_stacks(t_stack *s1, t_stack *s2)
{
	int	len1;
	int	len2;

	len1 = stck_len(&s1);
	len2 = stck_len(&s2);
	while (len1 > 0 && len2 > 0)
	{
		ft_printf("%d %d\n", s1->num, s2->num);
		s1 = s1->next;
		s2 = s2->next;
		len1--;
		len2--;
	}
	while (len1 > 0)
	{
		ft_printf("%d\n", s1->num);
		s1 = s1->next;
		len1--;
	}
	display_aux(s2, len2);
	ft_printf("_ _\na b\n");
}

void	stck_display(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack);
	if (!*stack)
		return ;
	else
	{
		while (temp->next != *stack)
		{
			printf("%d\n", temp->num);
			temp = temp->next;
		}
		printf("%d\n", temp->num);
	}
}

int	is_sortedstck(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (temp->num < (temp->next)->num)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

/* void    display_stacks(t_stack **s1, t_stack **s2)
{
    t_stack *current1;
    t_stack *current2;
    int len1;
    int len2;

    current1 = *s1;
    current2 = *s2;
    len1 = stck_len(s1);
    len2 = stck_len(s2);
    while (len1 > 0 && len2 > 0) {
        ft_printf("%d %d\n", current1->num, current2->num);
        current1 = current1->next;
        current2 = current2->next;
        len1--;
        len2--;
    }
    while (len1 > 0) {
        ft_printf("%d\n", current1->num);
        current1 = current1->next;
        len1--;
    }
    while (len2 > 0) {
        ft_printf("  %d\n", current2->num);
        current2 = current2->next;
        len2--;
    }
    ft_printf("_ _\na b\n");
} */
