/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:03:56 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/13 18:58:11 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bubble_sort(t_stack **stack)
{
	int		swapped;
	int		tmp;
	t_stack	*current;
	t_stack	*last;

	last = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *stack;
		while (current->next != last)
		{
			if (current->val > current->next->val)
			{
				tmp = current->val;
				current->val = current->next->val;
				current->next->val = tmp;
				swapped = 1;
			}
			current = current->next;
		}
		last = current;
	}
}

void	add_back(t_stack **stack_a, int val)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = malloc(sizeof(t_stack));
	if (tmp == NULL)
	{
		ft_free(stack_a);
		return ;
	}
	tmp->val = val;
	tmp->next = NULL;
	if (*stack_a == NULL)
		*stack_a = tmp;
	else
	{
		node = *stack_a;
		while (node->next)
			node = node->next;
		node->next = tmp;
	}
}

void	fill_stack(t_array *var, t_stack **stack)
{
	int	i;

	i = -1;
	while (++i < var->size)
		add_back(stack, var->tab[i]);
}

t_stack	*copy_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*copy;

	tmp = *stack;
	copy = NULL;
	while (tmp)
	{
		add_back(&copy, tmp->val);
		tmp = tmp->next;
	}
	return (copy);
}

void	map_stack(t_stack **stack_a)
{
	t_stack	*copy;
	t_stack	*tmp;
	t_stack	*tmp_c;

	copy = copy_stack(stack_a);
	bubble_sort(stack_a);
	tmp = NULL;
	map_stack2(stack_a, tmp, copy);
	tmp = *stack_a;
	tmp_c = copy;
	while (copy)
	{
		tmp->val = copy->val;
		tmp = tmp->next;
		copy = copy->next;
	}
	ft_free(&tmp_c);
}
