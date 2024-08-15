/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:21:19 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/09 17:10:25 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_array *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < var->size)
	{
		j = i;
		while (++j < var->size)
		{
			if (var->tab[i] > var->tab[j])
				return (0);
		}
	}
	return (1);
}

int	find_max(t_array *var)
{
	int	i;
	int	max;
	int	max_ind;

	i = -1;
	max = var->tab[0];
	max_ind = 0;
	while (++i < var->size)
	{
		if (var->tab[i] > max)
		{
			max = var->tab[i];
			max_ind = i;
		}
	}
	return (max_ind);
}

int	find_min(t_array *var)
{
	int	i;
	int	min;
	int	min_ind;

	i = -1;
	min = var->tab[0];
	min_ind = 0;
	while (++i < var->size)
	{
		if (var->tab[i] < min)
		{
			min = var->tab[i];
			min_ind = i;
		}
	}
	return (min_ind);
}

int	update(t_array *var, int min_ind)
{
	if (min_ind == 1)
		ft_putstr_fd("ra\n", 1);
	if (min_ind == 2)
		ft_putstr_fd("ra\nra\n", 1);
	if (min_ind == 3)
		ft_putstr_fd("rra\n", 1);
	ft_putstr_fd("pb\n", 1);
	var->tab = rot_tab(var, min_ind);
	if (var->tab == NULL)
		return (0);
	sort_three(var);
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	update_5(t_array *var, int min_ind)
{
	if (min_ind == 1)
		ft_putstr_fd("ra\n", 1);
	if (min_ind == 2)
		ft_putstr_fd("ra\nra\n", 1);
	if (min_ind == 3)
		ft_putstr_fd("rra\nrra\n", 1);
	if (min_ind == 4)
		ft_putstr_fd("rra\n", 1);
	ft_putstr_fd("pb\n", 1);
	var->tab = rot_tab(var, min_ind);
	if (var->tab == NULL)
		return (0);
	if (update(var, find_min(var)) == 0)
		return (free(var->tab), 0);
	else
		return (ft_putstr_fd("pa\n", 1), 1);
}
