/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:00:22 by pierre            #+#    #+#             */
/*   Updated: 2024/07/06 15:04:37 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_tob(t_data *data, t_stack *a, t_stack *b)
{
	
	while (stck_len(&b) > 0)
	{
		data->nbrb = get_cheapestnumber(b, a, data);
	}
}