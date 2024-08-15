/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:32:09 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/13 15:17:51 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*rot_tab(t_array *var, int min_ind)
{
	int	i;
	int	*arr;
	int	j;

	arr = malloc(sizeof(int) * (var->size - 1));
	if (arr == NULL)
		return (ft_error(1), NULL);
	i = 0;
	while (i + min_ind + 1 < var->size)
	{
		arr[i] = var->tab[min_ind + i + 1];
		i++;
	}
	j = 0;
	while (j < min_ind)
	{
		arr[i] = var->tab[j];
		i++;
		j++;
	}
	var->size--;
	free(var->tab);
	return (arr);
}

int	*copy_array(t_array *var)
{
	int	i;
	int	*arr_copy;

	arr_copy = malloc(sizeof(int) * var->size);
	if (arr_copy == NULL)
		return (ft_error(1), NULL);
	i = -1;
	while (++i < var->size)
		arr_copy[i] = var->tab[i];
	return (arr_copy);
}

void	rot(t_array *var)
{
	int	tmp;
	int	i;

	tmp = var->tab[0];
	i = -1;
	while (++i < var->size - 1)
		var->tab[i] = var->tab[i + 1];
	var->tab[var->size - 1] = tmp;
}
