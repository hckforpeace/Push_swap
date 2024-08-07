/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:38:32 by pierre            #+#    #+#             */
/*   Updated: 2024/08/07 10:29:26 by pbeyloun         ###   ########.fr       */
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
				process(split, 1);
			else
				ft_putstr_fd("Error\n", 2);
			clear_wordar(split);
		}
		else if (parser(&argv[1]))
			process(&argv[1], 0);
		else
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}

void	process(char **params, int flag)
{
	char	**instructions;
	int		i;
	t_stack	*a;
	t_stack	*b;

	a = add_tostack(params);
	b = NULL;
	i = 0;
	instructions = read_instructions(a, params, flag);
	while (instructions && instructions[i])
	{
		apply_tostack(instructions[i], ft_strlen(instructions[i]), &a, &b);
		i++;
	}
	if (is_sortedstck(a) && stck_len(&b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stck_clr(&a);
	stck_clr(&b);
	clear_wordar(instructions);
}

char	**read_instructions(t_stack *a, char **params, int flag)
{
	char	*line;
	char	**instructions;

	instructions = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n")
			&& ft_strcmp(line, "rrr\n") && ft_strcmp(line, "sa\n")
			&& ft_strcmp(line, "sb\n") && ft_strcmp(line, "ss\n")
			&& ft_strcmp(line, "pa\n") && ft_strcmp(line, "pb\n")
			&& ft_strcmp(line, "ra\n") && ft_strcmp(line, "rb\n")
			&& ft_strcmp(line, "rr\n"))
		{
			stck_clr(&a);
			free_stuff(line, instructions, params, flag);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
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
	else if (!ft_strncmp(instr, "rrr", instr_len - 1))
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
