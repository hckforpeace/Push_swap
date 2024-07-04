/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:17:31 by pierre            #+#    #+#             */
/*   Updated: 2024/07/03 14:07:55 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_stacks(t_stack **s1, t_stack **s2) {
    t_stack *current1 = *s1;
    t_stack *current2 = *s2;
    int len1 = stck_len(s1);
    int len2 = stck_len(s2);

    while (len1 > 0 && len2 > 0) {
        printf("%d %d\n", current1->num, current2->num);
        current1 = current1->next;
        current2 = current2->next;
        len1--;
        len2--;
    }

    while (len1 > 0) {
        printf("%d\n", current1->num);
        current1 = current1->next;
        len1--;
    }

    while (len2 > 0) {
        printf("  %d\n", current2->num);
        current2 = current2->next;
        len2--;
    }

    printf("_ _\na b\n");
}


void	stck_display(t_stack **stack)
{
	t_stack *temp;

	temp = (*stack);
	if (!*stack)
		return ;
	else
	{
		while(temp->next != *stack)
		{
			printf("%d\n", temp->num);
			temp = temp->next;
		}
		printf("%d\n", temp->num);
	}
}