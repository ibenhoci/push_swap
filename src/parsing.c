/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:05 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/13 19:35:39 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**check(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '\0')
		return (NULL);
	if (!ft_isdigit(argv[0]) && argv[0] != '-' && argv[0] != '+')
		return (NULL);
	else
	{
		while (argv[i] && (ft_isdigit(argv[i]) || argv[i] == '-'
				|| argv[i] == '+'))
		{
			i++;
			if (argv[i] == ' ')
				i++;
			if (argv[i] == '\0' && (argv[i - 1] < '0' || argv[i - 1] > '9'))
				return (NULL);
		}
		if (argv[i] == '\0')
			return (ft_split(argv, ' '));
		else
			return (NULL);
	}
}

int	parse_two(char *argv)
{
	char	**mat;
	int		i;
	int		j;

	mat = check(argv);
	if (mat == NULL)
		return (ft_error(1), 0);
	i = -1;
	while (mat[++i])
	{
		if (!correct_int(mat[i]))
			return (f_split(mat), ft_error(2), 0);
	}
	i = -1;
	while (mat[++i])
	{
		j = i;
		while (mat[++j])
		{
			if (!ft_strncmp(mat[i], mat[j], ft_strlen(mat[j]))
				&& !ft_strncmp(mat[i], mat[j], ft_strlen(mat[i])))
				return (f_split(mat), ft_error(2), 0);
		}
	}
	return (f_split(mat), 1);
}

int	parse_multiple(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		if (!correct_int(argv[i]))
			return (ft_error(2), 0);
	}
	i = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (!ft_strncmp(argv[i], argv[j], ft_strlen(argv[j]))
				&& !ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])))
				return (ft_error(2), 0);
		}
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!parse_two(argv[1]))
			return (0);
	}
	else
	{
		if (!parse_multiple(argv))
			return (0);
	}
	return (1);
}
