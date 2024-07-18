/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:18:21 by pierre            #+#    #+#             */
/*   Updated: 2024/07/18 14:41:58 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_sep(t_data *data, t_stack **a, t_stack **b, int topush)
{
	if (get_index(data->nbra, *a) <= data->lena / 2)
	{
		apply_xrs(data->movesa, a, 'a', R);
		apply_xrs(data->movesb, b, 'b', RR);
		if (topush == PB)
			stck_push(b, a, 'b');
		else
			stck_push(a, b, 'a');
	}
	else
	{
		apply_xrs(data->movesa, a, 'a', RR);
		apply_xrs(data->movesb, b, 'b', R);
		if (topush == PB)
			stck_push(b, a, 'b');
		else
			stck_push(a, b, 'a');
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

char	**add_instr(char *instruct, char **wordlist)
{
	int		num_words;
	char	**wl;
	int		i;

	i = 0;
	num_words = count_words(wordlist);
	wl = (char **)malloc(sizeof(char *) * (num_words + 2));
	if (wl == 0)
	{
		clear_wordar(wordlist);
		exit(1);
	}
	while (wordlist && wordlist[i])
	{
		wl[i] = wordlist[i];
		i++;
	}
	wl[i] = instruct;
	i++;
	wl[i] = 0;
	free(wordlist);
	return (wl);
}
