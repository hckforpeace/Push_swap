/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:55:08 by pierre            #+#    #+#             */
/*   Updated: 2024/07/06 17:54:59 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cheapestnumbera(t_stack *a, t_stack *b, t_data *data)
{
	int number;
	int moves;
	t_stack	*temp;

	temp = a;
	data->nbra = temp->num;
	moves = get_price(data, &a, &b, CALC);
	number = temp->num;
	temp = temp->next;
	while (temp->next != a)
	{
		data->nbra = temp->num;
		if (get_price(data, &a, &b, CALC) < moves)
		{
			number = temp->num;
			moves = get_price(data, &a, &b, CALC);
		}
		temp = temp->next;
	}
	data->nbra = temp->num;
	if (get_price(data, &a, &b, CALC) < moves)
		number = temp->num;
	return (number);
}


/* int	get_price(int nbr, t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	nbr_b;
	int	moves_a;
	int	moves_b;

	len_a = stck_len(&a);
	len_b = stck_len(&b);
	if (is_max(nbr, b) || is_min(nbr, b))
	{
		nbr_b = get_max(b);
		moves_a = get_movestotop(nbr, a);
		moves_b = get_movestotop(nbr_b, b);
		if (is_sephalf(nbr, nbr_b, a, b))
			return (moves_a + moves_b + 1);
		return (get_totalmoves(moves_a, moves_b, len_a, len_b));
	}
	else
	{
		nbr_b = get_number(nbr, b);
		moves_a = get_movestotop(nbr, a);
		moves_b = get_movestotop(nbr_b, b);
		if (is_sephalf(nbr, nbr_b, a, b))
			return (moves_a + moves_b + 1);
		return (get_totalmoves(moves_a, moves_b, len_a, len_b));
	}
} */

int	get_price(t_data *data, t_stack **a, t_stack **b, int action)
{

	data->lena = stck_len(a);
	data->lenb = stck_len(b);
	data->nbrb = get_number(data->nbra, *b);
	data->movesa = get_movestotop(data->nbra, *a);
	data->movesb = get_movestotop(data->nbrb, *b);
	if (action == CALC)
	{
		if (is_sephalf(data->nbra, data->nbrb, *a, *b))
			return (data->movesa + data->movesb + 1);
		return (get_totalmoves(data->movesa, data->movesb, data->lena, data->lenb));
	}
	else
	{
		if (is_sephalf(data->nbra, data->nbrb, *a, *b))
			return (apply_sep(data, a, b, PB));
		return (apply_moves(data, a, b, PB));
	}
}

int	is_sephalf(int nbra, int nbrb, t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	idxa;
	int	idxb;
	
	len_a = stck_len(&a);
	len_b = stck_len(&b);
	idxa = get_index(nbra, a);
	idxb = get_index(nbrb, b);
	// printf("idxa: %d, lena: %d, idxb: %d, lenb: %d, nbrb: %d\n", idxa, len_a, idxb, len_b, nbrb);
	if ((idxa < len_a / 2 && idxb > len_b / 2) || (idxb < len_b / 2 && idxa > len_a / 2))
		return (1);
	return (0);
}

//	retruns the total number of moves need to place the number from a to b
int	get_totalmoves(int	movesa, int movesb, int len_a, int len_b)
{
	if (movesa == len_a / 2 && movesb == len_b / 2)
		return (movesa + 1);
	else
		return (smallest(movesa, movesb) + get_absolute(movesa - movesb) + 1);
}

// retruns the number of moves needed to get the number the top of the stack
int	get_movestotop(int nbr, t_stack *stack)
{
	int		stcklen;
	t_stack	*temp;
	int		i;

	i = 0;
	stcklen = stck_len(&stack);
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->num == nbr)
			break;
		temp = temp->next;
		i++;
	}
	if (temp->next == stack)
		return (get_absolute(stck_len(&stack) - i));
	if ((stcklen % 2) == 1 && i == (stcklen / 2))
		return (i);
	if (i < stcklen / 2)
		return (i);
	return (get_absolute(stck_len(&stack) - i));
}

// gets the number in stack b that is the closest to the 
// number in stack b if the number is nor min or max 
int	get_number(int nbr, t_stack *b)
{
	t_stack	*temp;

	if (is_max(nbr, b) || is_min(nbr, b))
		return (get_max(b));
	temp = b;
	while (temp->next != b)
	{
		if (nbr < temp->num && nbr > temp->next->num)
			return (temp->next->num);
		temp = temp->next;
	}
/*  	if (nbr > b->prev->num && nbr < temp->next->num)
		return (b->prev->num); */
	return (b->num);
}
int	get_index(int nbr, t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->num == nbr)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

/* int	get_numberidx(int idx, t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp->next != stack)
	{
		if (i == idx)
			return (temp->num);
		i++;
		temp = temp->next;
	}
	return (temp->num);
} */