/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:00:22 by pierre            #+#    #+#             */
/*   Updated: 2024/07/07 19:39:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swapb(t_stack *a, t_stack *b, t_data *data)
{
	int	minnbra;
	int	moves;

	while (stck_len(&b) > 0)
	{
		data->nbrb = get_cheapestnumberb(a, b, data);
		get_priceb(data, &a, &b, APPLY);
	}
	if (!is_sortedstck(a))
	{
		minnbra = get_min(a);
		moves = get_movestotop(minnbra, a);
		if (get_index(minnbra, a) <= stck_len(&a) / 2)
			apply_xrs(moves, &a, 'a', R);
		else
			apply_xrs(moves, &a, 'a', RR);
	}
	free(data);
}

int	get_cheapestnumberb(t_stack *a, t_stack *b, t_data *data)
{
	int		number;
	int		moves;
	t_stack	*temp;

	temp = b;
	data->nbrb = temp->num;
	moves = get_priceb(data, &a, &b, CALC);
	number = temp->num;
	temp = temp->next;
	while (temp->next != b)
	{
		data->nbrb = temp->num;
		if (get_priceb(data, &a, &b, CALC) < moves)
		{
			number = temp->num;
			moves = get_priceb(data, &a, &b, CALC);
		}
		temp = temp->next;
	}
	data->nbrb = temp->num;
	if (get_priceb(data, &a, &b, CALC) < moves)
		number = temp->num;
	return (number);
}

int	get_priceb(t_data *data, t_stack **a, t_stack **b, int action)
{
	data->lena = stck_len(a);
	data->lenb = stck_len(b);
	data->nbra = get_numberb(data->nbrb, *a);
	data->movesa = get_movestotop(data->nbra, *a);
	data->movesb = get_movestotop(data->nbrb, *b);
	if (action == CALC)
	{
		if (is_sephalf(data, *a, *b))
			return (data->movesa + data->movesb + 1);
		return (get_totalmoves(data->movesa, data->movesb,
				data->lena, data->lenb));
	}
	else
	{
		if (is_sephalf(data, *a, *b))
		{
			apply_sep(data, a, b, PA);
			return (1);
		}
		apply_moves(data, a, b, PA);
		return (1);
	}
}

int	get_numberb(int nbr, t_stack *a)
{
	t_stack	*temp;

	if (is_max(nbr, a) || is_min(nbr, a))
		return (get_min(a));
	temp = a;
	while (temp->next != a)
	{
		if (nbr > temp->num && nbr < temp->next->num)
			return (temp->next->num);
		temp = temp->next;
	}
	return (a->num);
}

int	get_min(t_stack *a)
{
	t_stack	*temp;
	int		min;

	min = a->num;
	temp = a;
	temp = temp->next;
	while (temp->next != a)
	{
		if (min > temp->num)
			min = temp->num;
		temp = temp->next;
	}
	if (min > temp->num)
		min = temp->num;
	return (min);
}
