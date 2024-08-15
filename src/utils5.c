/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:52:04 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/13 19:36:11 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_sorted(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*t;

	tmp = stack;
	while (tmp)
	{
		t = tmp->next;
		while (t)
		{
			if (t->val > tmp->val)
				t = t->next;
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	stack_max(t_stack *stack_a)
{
	int	max;

	max = stack_a->val;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->val > max)
			max = stack_a->val;
		stack_a = stack_a->next;
	}
	return (max);
}

void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (*stack)
	{
		tmp = *stack;
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

void	push(t_stack **stack, t_stack **stack_target)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = *stack_target;
	*stack_target = tmp;
}

void	rot_stk(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;
	t_stack	*first_node;

	head = (*stack)->next;
	first_node = *stack;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_node;
	first_node->next = NULL;
	*stack = head;
}
