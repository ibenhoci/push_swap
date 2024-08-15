/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:52:16 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/13 19:35:54 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_array *var)
{
	int	max_ind;

	max_ind = find_max(var);
	if (max_ind == 2)
	{
		if (var->tab[0] > var->tab[1])
			ft_putstr_fd("sa\n", 1);
	}
	else if (max_ind == 1)
	{
		ft_putstr_fd("rra\n", 1);
		if (var->tab[2] > var->tab[0])
			ft_putstr_fd("sa\n", 1);
	}
	else if (max_ind == 0)
	{
		ft_putstr_fd("ra\n", 1);
		if (var->tab[1] > var->tab[2])
			ft_putstr_fd("sa\n", 1);
	}
}

void	sort_small(t_array *var)
{
	int	min_ind;

	if (is_sorted(var))
		return ;
	if (var->size == 4)
	{
		min_ind = find_min(var);
		if (!update(var, min_ind))
			return ;
	}
	if (var->size == 5)
	{
		min_ind = find_min(var);
		if (!update_5(var, min_ind))
			return ;
	}
}

int	counting_sort(t_stack **stack_a, t_stack **stack_b, int q)
{
	int		nums;
	int		count;
	t_stack	*tmp;

	tmp = *stack_a;
	nums = 0;
	while (tmp)
	{
		nums++;
		tmp = tmp->next;
	}
	count = counting_sort2(stack_a, stack_b, q, nums);
	while (count--)
	{
		push(stack_b, stack_a);
		ft_putstr_fd("pa\n", 1);
	}
	return (1);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	q;
	int	bit;

	max = stack_max(*stack_a);
	bit = 0;
	while (max > 0)
	{
		max /= 2;
		bit++;
	}
	q = 0;
	while (q < bit)
	{
		if (stack_sorted(*stack_a))
			break ;
		if (counting_sort(stack_a, stack_b, q) == 0)
			break ;
		q++;
	}
}

void	sort(t_array *var)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (is_sorted(var))
		return ;
	if (var->size == 2)
	{
		if (var->tab[0] > var->tab[1])
			ft_putstr_fd("sa\n", 1);
	}
	else if (var->size == 3)
		sort_three(var);
	else if ((var->size == 4 || var->size == 5))
		sort_small(var);
	else
	{
		stack_a = NULL;
		stack_b = NULL;
		fill_stack(var, &stack_a);
		map_stack(&stack_a);
		sort_big(&stack_a, &stack_b);
		ft_free(&stack_a);
		stack_a = NULL;
		stack_b = NULL;
	}
}
