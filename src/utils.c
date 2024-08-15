/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:41:02 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/13 19:33:57 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	f_split(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
}

int	correct_int(char *str)
{
	int		i;
	int		nb;
	char	*nbr;

	if (str[0] == '-' || str[0] == '+')
		i = 0;
	else
		i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	if (str[0] == '+')
		str++;
	nb = ft_atoi(str);
	nbr = ft_itoa(nb);
	if (!ft_strncmp(nbr, str, ft_strlen(str)))
		return (free(nbr), 1);
	else
		return (free(nbr), 0);
}

void	*init_two(t_array *var, char *argv)
{
	char	**mat;
	int		i;

	mat = ft_split(argv, ' ');
	if (mat == NULL)
		return (ft_error(1), NULL);
	i = -1;
	while (mat[++i])
		;
	var->tab = malloc(sizeof(int) * i);
	if (var->tab == NULL)
		return (f_split(mat), ft_error(1), NULL);
	var->size = i;
	i = -1;
	while (mat[++i])
		var->tab[i] = ft_atoi(mat[i]);
	return (f_split(mat), var);
}

void	*init_multiple(t_array *var, int argc, char **argv)
{
	int	i;

	var->tab = malloc(sizeof(int) * (argc - 1));
	if (var->tab == NULL)
		return (ft_error(1), NULL);
	var->size = argc - 1;
	i = 0;
	while (argv[++i])
		var->tab[i - 1] = ft_atoi(argv[i]);
	return (var);
}

int	init(t_array *var, int argc, char **argv)
{
	if (argc == 2)
	{
		if (init_two(var, argv[1]) == NULL)
			return (0);
	}	
	else
	{
		if (init_multiple(var, argc, argv) == NULL)
			return (0);
	}
	return (1);
}
