/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:40:55 by pierre            #+#    #+#             */
/*   Updated: 2024/07/23 11:45:35 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**split;

	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		if (argc == 2)
		{
			split = ft_split(argv[1], ' ');
			if (!split)
				return (1);
			if (parser(split))
				init_stacks(split);
			else
				ft_printf("Error\n");
			clear_wordar(split);
		}
		else if (parser(&argv[1]))
			init_stacks(&argv[1]);
		else
			ft_printf("Error\n");
	}
	return (0);
}

void	init_stacks(char **numbers)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (numbers[1] == 0)
		return ;
	a = add_tostack(numbers);
	if (a == NULL)
	{
		write(2, "Malloc error exiting\n", 21);
		return ;
	}
	if (stck_len(&a) == 2)
	{
		if (!is_sortedstck(a))
			stck_swap(&a, 'a');
	}
	else if (stck_len(&a) == 3 && !is_sortedstck(a))
		sort_3(&a, 'a');
	else if (!is_sortedstck(a))
		push_swap(a, b);
	stck_clr(&a);
	stck_clr(&b);
}

int	is_revsortedstck(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (temp->num > (temp->next)->num)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	sort_3(t_stack **stack, char c)
{
	if (!*stack)
		return ;
	if (is_sortedstck(*stack))
		return ;
	else if (is_revsortedstck(*stack))
	{
		stck_rotate(stack, R, c);
		stck_swap(stack, c);
	}
	else if (((*stack)->num) > (*stack)->prev->num
		&& (*stack)->prev->num > (*stack)->next->num)
		stck_rotate(stack, R, c);
	else if ((*stack)->num < (*stack)->prev->num
		&& (*stack)->prev->num < (*stack)->next->num)
	{
		stck_rotate(stack, RR, c);
		stck_swap(stack, c);
	}
	else if ((*stack)->num < (*stack)->prev->num
		&& (*stack)->prev->num > (*stack)->num)
		stck_swap(stack, c);
	else
		stck_rotate(stack, RR, c);
}

/* int	main()
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	stck_addlst(&a, create_node(4));
	stck_addlst(&a, create_node(6));
	stck_addlst(&a, create_node(7));
	b = NULL;
	stck_addlst(&b, create_node(1));
	stck_addlst(&b, create_node(5));
	stck_addlst(&b, create_node(2));

	display_stacks(&a, &b);
	printf("************************************\n");

	stck_push(&b, &a);
	stck_push(&b, &a);
	stck_push(&b, &a);
	stck_push(&b, &a);
	display_stacks(&a, &b);
	printf("************************************\n");

	stck_push(&a, &b);
	stck_push(&a, &b);
	stck_push(&a, &b);
	stck_push(&a, &b);
	stck_push(&a, &b);
	stck_push(&a, &b);
	display_stacks(&a, &b);
	printf("************************************\n");

	stck_swap(&a);
	stck_swap(&b);

	display_stacks(&a, &b);
	printf("************************************\n");

	stck_push(&b, &a);
	stck_push(&b, &a);

	display_stacks(&a, &b);
	printf("************************************\n");

	stck_swap(&b);
	stck_push(&b, &a);
	display_stacks(&a, &b);
	printf("************************************\n");

	stack_rotate(&b, R);
	stack_rotate(&a, R);
	display_stacks(&a, &b);
	printf("************************************\n");

	stack_rotate(&b, RR);
	stack_rotate(&a, RR);
	display_stacks(&a, &b);
	printf("************************************\n");

	stck_clr(&a);
	stck_clr(&b);
	return (0);
} */
