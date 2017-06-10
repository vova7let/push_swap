/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:53:55 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:54:31 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_b(t_stack *a, t_stack *b, int n, char **commands)
{
	int	k;
	int	push;

	if (sorted_b(b, n) == 1)
	{
		k = 0;
		while (k < n)
		{
			push_a(a, b, commands);
			k++;
		}
		return ;
	}
	if (n > 3)
	{
		push = in_two_from_b_to_a(b, a, n, commands);
		sort_a(a, b, push, commands);
		sort_b(a, b, n - push, commands);
	}
	else if (n < 4)
	{
		sort_3b(b, a, n, commands);
	}
}

void	sort_a_rev(t_stack *a, t_stack *b, int n, char **commands)
{
	int push;

	if (sorted_a(a, n) == 1)
		return ;
	if (n > 3)
	{
		push = in_two_from_a_to_b_rev(a, b, n, commands);
		sort_a_rev(a, b, n - push, commands);
		sort_b_rev(a, b, push, commands);
	}
	if (n < 4)
		sort_3a(a, b, n, commands);
}

void	sort_b_rev(t_stack *a, t_stack *b, int n, char **commands)
{
	int k;
	int push;

	if (sorted_b(b, n) == 1)
	{
		k = 0;
		while (k < n)
		{
			push_a(a, b, commands);
			k++;
		}
		return ;
	}
	if (n > 3)
	{
		push = in_two_from_b_to_a_rev(b, a, n, commands);
		sort_a_rev(a, b, push, commands);
		sort_b_rev(a, b, n - push, commands);
	}
	else if (n < 4)
	{
		sort_3b(b, a, n, commands);
	}
}

int		check(t_stack *a)
{
	int i;
	int j;

	i = 0;
	while (i < a->a_size)
	{
		j = 0;
		while (j < a->a_size)
		{
			if (i != j && (a->a)[i] == (a->a)[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*main_sort1(int ac, char **av, int *flag)
{
	t_stack	*a;
	t_stack	*b;
	char	*commands;

	new_stack(&a, &b, av, ac);
	if (a->flag2 == 1)
		*flag = 1;
	if (check(a) != 1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	commands = (char *)malloc(1);
	commands[0] = '\0';
	sort_a(a, b, a->a_size, &commands);
	(a->flag == 1) ? (ft_putstr("\n---------------------------------\n")) : 0;
	free(a->a);
	free(a);
	free(b->a);
	free(b);
	return (commands);
}
