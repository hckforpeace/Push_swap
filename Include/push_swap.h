/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:50:00 by pierre            #+#    #+#             */
/*   Updated: 2024/07/18 14:45:43 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

# define RR 0
# define R 1
# define CALC 0
# define APPLY 1
# define PB 12
# define PA 13

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int	nbra;
	int	nbrb;
	int	movesa;
	int	movesb;
	int	lena;
	int	lenb;
}	t_data;

t_stack	*create_node(int num);
void	stck_addlst(t_stack **stack, t_stack *lst);
void	stck_addfst(t_stack **stack, t_stack *fst);
void	stck_clr(t_stack **stack);
void	stck_display(t_stack **stack);

int		stck_len(t_stack **stack);
void	stck_swap(t_stack **stack, char c);
void	stck_push(t_stack **dest, t_stack **src, char c);
void	display_stacks(t_stack *s1, t_stack *s2);
t_stack	*stck_pop(t_stack **stack);
void	stck_rotate(t_stack **stack, int sens, int c);

/* parcer.c */
int		parser(char **argv);
void	init_stacks(char **numbers);
int		is_sortedstck(t_stack *stack);
int		is_revsortedstck(t_stack *stack);
void	sort_3(t_stack **stack, char c);

// void	push_swap(t_stack *a, t_stack *b);
int		get_cheapestnumbera(t_stack *a, t_stack *b, t_data *data);
int		get_price(t_data *data, t_stack **a, t_stack **b, int action);
int		get_totalmoves(int movesa, int movesb);
int		get_movestotop(int nbr, t_stack *stack);
int		get_number(int nbr, t_stack *b);
int		is_max(int nbr, t_stack *b);
int		is_min(int nbr, t_stack *b);
int		get_max(t_stack *b);
int		smallest(int a, int b);
int		get_absolute(int value);
int		get_index(int nbr, t_stack *stack);

// int	is_sephalf(int nbra, int nbrb, t_stack *a, t_stack *b);
int		is_sephalf(t_data *data, t_stack *a, t_stack *b);
int		get_numberidx(int idx, t_stack *stack);

// push.c
void	push_swap(t_stack *a, t_stack *b);
int		apply_moves(t_data *data, t_stack **a, t_stack **b, int push);
void	apply_ab(t_data *data, t_stack **a, t_stack **b);
void	apply_bb(t_data *data, t_stack **a, t_stack **b);
void	display_symrot(int i, int sens);
int		apply_sep(t_data *data, t_stack **a, t_stack **b, int topush);
void	apply_xrs(int i, t_stack **stack, char c, int sens);
int		get_priceb(t_data *data, t_stack **a, t_stack **b, int action);
int		get_numberb(int nbr, t_stack *a);
int		get_min(t_stack *a);
int		get_cheapestnumberb(t_stack *a, t_stack *b, t_data *data);
void	push_swapb(t_stack *a, t_stack *b, t_data *data);

// BONUS
void	process(t_stack **a, t_stack **b);
void	apply_tostack(char *instr, int instr_len, t_stack **a, t_stack **b);
void	apply_tostackaux(char *instr, int instr_len, t_stack **a, t_stack **b);
int		parse_input(char *line, int line_len, t_stack **a, t_stack **b);
t_stack	*add_tostack(char **argv);
int		is_sortedstck(t_stack *stack);
char	**read_instructions(void);
int		count_words(char **wordlist);
char	**add_instr(char *instruct, char **wordlist);

#endif
