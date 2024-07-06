/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:59:40 by pierre            #+#    #+#             */
/*   Updated: 2024/07/06 15:10:10 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_data	*data;

	data = (struct s_data*)malloc(sizeof(struct s_data));
	if (!data)
	{
		write(2, "Memory allocation error\n", 24);
		return ;
	}
	while (stck_len(&a) > 3)
	{
		data->nbra = get_cheapestnumber(a, b, data);
		printf("cheapest number is %d\n\n", data->nbra);
		get_price(data, &a, &b, APPLY);
		printf("\n");
		display_stacks(&a, &b);
		printf("************************\n");
	}
	printf("************************\n");
	sort_3(&a, 'a');
	display_stacks(&a, &b);
}

int	apply_moves(t_data *data, t_stack **a, t_stack **b)
{
	if (data->movesa == data->lena / 2 && data->movesb == data->lenb / 2)
	{
		display_symrot(data->movesa, R);
		apply_xrs(data->movesa, a, '0', R);
		apply_xrs(data->movesb, b, '0', R);
		stck_push(b, a, 'b');
	}
	else
	{
		if (data->movesa > data->movesb)
			apply_ab(data, a, b);
		else
			apply_bb(data, a, b);
	}
	return (0);
}

void apply_ab(t_data *data, t_stack **a, t_stack **b)
{
	if (get_index(data->nbra, *a) < data->lena / 2)
	{
		display_symrot(data->movesb, R);
		apply_xrs(data->movesb, a, '0', R);
		apply_xrs(data->movesb, b, '0', R);
		apply_xrs(data->movesa - data->movesb, a, 'a', R);				
		stck_push(b, a, 'b');
	}
	else
	{
		display_symrot(data->movesb, RR);
		apply_xrs(data->movesb, a, '0', RR);
		apply_xrs(data->movesb, b, '0', RR);
		apply_xrs(data->movesa - data->movesb, a, 'a', RR);				
		stck_push(b, a, 'b');
	}
}
void apply_bb(t_data *data, t_stack **a, t_stack **b)
{
	if (get_index(data->nbra, *a) < data->lena / 2)
	{
		display_symrot(data->movesa, R);
		apply_xrs(data->movesa, a, '0', R);
		apply_xrs(data->movesa, b, '0', R);
		apply_xrs(data->movesb - data->movesa, b, 'b', R);				
		stck_push(b, a, 'b');
	}
	else
	{
		display_symrot(data->movesa, RR);
		apply_xrs(data->movesa, a, '0', RR);
		apply_xrs(data->movesa, b, '0', RR);
		apply_xrs(data->movesb - data->movesa, b, 'b', RR);				
		stck_push(b, a, 'b');
	}
}

void	display_symrot(int i, int sens)
{
	while (i > 0)
	{
		if (sens == R)
			ft_printf("rr\n");
		else
			ft_printf("rrr\n");
		i--;
	}
}

int	apply_sep(t_data *data, t_stack **a, t_stack **b)
{
	if (get_index(data->nbra, *a) < data->lena / 2)
	{
		apply_xrs(data->movesa, a, 'a', R);
		apply_xrs(data->movesb, b, 'b', RR);
		stck_push(b, a, 'b');
	}
	else
	{
		apply_xrs(data->movesa, a, 'a', RR);
		apply_xrs(data->movesb, b, 'b', R);
		stck_push(b, a, 'b');
	}
	return (0);
}

void	apply_xrs(int i, t_stack **stack, char c, int sens)
{
	while (i > 0)
	{
		stck_rotate(stack, sens, c);
		i--;
	}
}