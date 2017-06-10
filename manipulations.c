/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:37:24 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:38:28 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	*main_sort2(int ac, char **av, int *flag)
{
	t_stack	*a;
	t_stack	*b;
	char	*commands;

	new_stack(&a, &b, av, ac);
	a->flag = 0;
	if (a->flag2 == 1)
		*flag = 1;
	if (check(a) != 1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	commands = (char *)malloc(1);
	commands[0] = '\0';
	sort_a_rev(a, b, a->a_size, &commands);
	free(a->a);
	free(a);
	free(b->a);
	free(b);
	return (commands);
}

int		main(int ac, char **av)
{
	char	*commands;
	char	*rev_commands;
	int		flag;

	if (ac < 2)
		exit(0);
	commands = main_sort1(ac, av, &flag);
	rev_commands = main_sort2(ac, av, &flag);
	if (ft_strlen(commands) > ft_strlen(rev_commands))
		cmds_optimizer(rev_commands, flag);
	else
		cmds_optimizer(commands, flag);
	free(commands);
	free(rev_commands);
	return (0);
}
