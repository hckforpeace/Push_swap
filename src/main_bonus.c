/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:38:32 by pierre            #+#    #+#             */
/*   Updated: 2024/07/18 14:57:28 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	else
	{
		if (!parser(&argv[1]))
			write(2, "Error\n", 7);
		else
		{
			a = add_tostack(&argv[1]);
			b = NULL;
			process(&a, &b);
			stck_clr(&a);
			stck_clr(&b);
		}
	}
	return (0);
}

void	process(t_stack **a, t_stack **b)
{
	char	**instructions;
	int		i;

	i = 0;
	instructions = read_instructions();
	while (instructions && instructions[i])
	{
		apply_tostack(instructions[i], ft_strlen(instructions[i]), a, b);
		i++;
	}
	if (is_sortedstck(*a) && stck_len(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_wordar(instructions);
}

char	**read_instructions(void)
{
	char	*line;
	char	**instructions;

	instructions = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		instructions = add_instr(line, instructions);
		line = get_next_line(0);
	}
	return (instructions);
}

void	apply_tostackaux(char *instr, int instr_len, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(instr, "rra", instr_len - 1))
		stck_rotate(a, RR, '0');
	else if (!ft_strncmp(instr, "rrb", instr_len - 1))
		stck_rotate(b, RR, '0');
	else if (!ft_strncmp(instr, "rrb", instr_len - 1))
	{
		stck_rotate(b, RR, '0');
		stck_rotate(a, RR, '0');
	}
}

/* int	parse_input(char *line, int line_len, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa", line_len - 1)
		|| !ft_strncmp(line, "sb", line_len - 1)
		|| !ft_strncmp(line, "ss", line_len - 1)
		|| !ft_strncmp(line, "pa", line_len - 1)
		|| !ft_strncmp(line, "pb", line_len - 1)
		|| !ft_strncmp(line, "ra", line_len - 1)
		|| !ft_strncmp(line, "rb", line_len - 1)
		|| !ft_strncmp(line, "rr", line_len - 1)
		|| !ft_strncmp(line, "rra", line_len - 1)
		|| !ft_strncmp(line, "rrb", line_len - 1)
		|| !ft_strncmp(line, "rrr", line_len - 1))
		return (1);
	else
	{
		free(line);
		stck_clr(a);
		stck_clr(b);
		return (0);
	}
} */

void	apply_tostack(char *instr, int instr_len, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(instr, "sa", instr_len - 1))
		stck_swap(a, '0');
	else if (!ft_strncmp(instr, "sb", instr_len - 1))
		stck_swap(b, '0');
	else if (!ft_strncmp(instr, "ss", instr_len - 1))
	{
		stck_swap(a, '0');
		stck_swap(b, '0');
	}
	else if (!ft_strncmp(instr, "pa", instr_len - 1))
		stck_push(a, b, '0');
	else if (!ft_strncmp(instr, "pb", instr_len - 1))
		stck_push(b, a, '0');
	else if (!ft_strncmp(instr, "ra", instr_len - 1))
		stck_rotate(a, R, '0');
	else if (!ft_strncmp(instr, "rb", instr_len - 1))
		stck_rotate(b, R, '0');
	else if (!ft_strncmp(instr, "rr", instr_len - 1))
	{
		stck_rotate(b, R, '0');
		stck_rotate(a, R, '0');
	}
	else
		apply_tostackaux(instr, instr_len, a, b);
}
