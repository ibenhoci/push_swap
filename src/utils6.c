/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:53:18 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/13 17:17:59 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	map_stack2(t_stack **stack_a, t_stack *tmp, t_stack *copy)
{
	int	ind;

	while (copy)
	{
		ind = 0;
		tmp = *stack_a;
		while (tmp)
		{
			if (copy->val == tmp->val)
			{
				copy->val = ind;
				break ;
			}
			tmp = tmp->next;
			ind++;
		}
		copy = copy->next;
	}
}

int	counting_sort2(t_stack **stack_a, t_stack **stack_b, int q, int nums)
{
	int		count;

	count = 0;
	while (nums--)
	{
		if ((((*stack_a)->val >> q) & 1) == 0)
		{
			count++;
			push(stack_a, stack_b);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			rot_stk(stack_a);
		}
	}
	return (count);
}

void	ft_error(int err_nbr)
{
	if (err_nbr == 1 || err_nbr == 2)
		ft_putstr_fd("Error\n", 1);
}
