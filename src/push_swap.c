/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:55:08 by pierre            #+#    #+#             */
/*   Updated: 2024/07/04 23:47:39 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_indexcheapest(t_stack *a, t_stack *b)
{
	int idx;
	int i;
	int moves;
	t_stack	*temp;

	temp = a;
	printf("index: 0, numb: %d\n", a->num);
	moves = get_price(temp->num, a, b);
	temp = temp->next;
	idx = 0;
	i = 1;
	while (temp->next != a)
	{
		printf("index: %d, numb: %d\n", i, temp->num);
		if (get_price(temp->num, a, b) < moves)
		{
			idx = i;
			moves = get_price(temp->num, a, b);
		}
		temp = temp->next;
		i++;
	}
	printf("index: %d, numb: %d\n", i, temp->num);
	if (get_price(temp->num, a, b) < moves)
	{
		idx = i;
	}
	return (idx);
}


int	get_price(int nbr, t_stack *a, t_stack *b)
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
		{
			printf("moves: %d\n\n", moves_a + moves_b + 1);
			return (moves_a + moves_b + 1);
		}
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
	printf("idxa: %d, lena: %d, idxb: %d, lenb: %d, nbrb: %d\n", idxa, len_a, idxb, len_b, nbrb);
	if ((idxa < len_a / 2 && idxb > len_b / 2) || (idxb < len_b / 2 && idxa > len_a / 2))
		return (1);
	return (0);
}

//	retruns the total number of moves need to place the number from a to b
int	get_totalmoves(int	movesa, int movesb, int len_a, int len_b)
{
	if (movesa == len_a / 2 && movesb == len_b / 2)
	{
		printf("movesa: %d, movesb: %d, moves: %d\n\n", movesa, movesb, movesa + 1);
		return (movesa + 1);
	}
	else
	{
		printf("movesa: %d, movesb: %d,  moves: %d***\n\n", movesa, movesb, smallest(movesa, movesb) + get_absolute(movesa - movesb) + 1);
		// if (movesa == 1 && movesb == 1)
		// 	return (3);
		return (smallest(movesa, movesb) + get_absolute(movesa - movesb) + 1);
	}
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