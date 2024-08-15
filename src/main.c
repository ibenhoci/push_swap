/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:21:40 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/08/15 19:43:38 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_array	var;

	if (argc <= 1)
		return (0);
	if (check_input(argc, argv) == 0)
		return (1);
	if (init(&var, argc, argv) == 0)
		return (1);
	sort(&var);
	free(var.tab);
	return (0);
}
