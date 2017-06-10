/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:11:48 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/27 13:08:44 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rev_rotate_ab1(t_stack *a, t_stack *b)
{
	rev_rotate_a1(a);
	rev_rotate_b1(b);
}

void	new_stack1(t_stack **a, t_stack **b, char **av, int n)
{
	int	i;

	(*a) = (t_stack *)malloc(sizeof(t_stack *));
	(*a)->a = (int *)malloc(sizeof(int) * n);
	(*b) = (t_stack *)malloc(sizeof(t_stack *));
	(*b)->a = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		((*a)->a)[i] = ft_atoi(av[i + 1]);
		i++;
	}
	(*b)->a_size = 0;
	(*a)->a_size = i;
}

int		check1(t_stack *a)
{
	int	i;
	int	j;

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

void	check_comm(char *line)
{
	if (ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0
			&& ft_strcmp(line, "ss") != 0 &&
		ft_strcmp(line, "ra") != 0 && ft_strcmp(line, "rb") != 0
		&& ft_strcmp(line, "rr") != 0 &&
		ft_strcmp(line, "rra") != 0 && ft_strcmp(line, "rrb") != 0
		&& ft_strcmp(line, "rrr") != 0 &&
		ft_strcmp(line, "pa") != 0 && ft_strcmp(line, "pb") != 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

int		main(int ac, char **av)
{
	int		n;
	t_stack	*a;
	t_stack	*b;
	char	*line;

	n = 1;
	(ac < 2) ? exit(0) : 0;
	new_stack1(&a, &b, av, ac - 1);
	if (check1(a) != 1 || a->a_size == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	while (get_next_line(0, &line))
	{
		check_h1(a, b, line);
		free(line);
	}
	if (sorted_a1(a) == 1 && b->a_size == 0)
		ft_putstr("\x1B[32mOK\x1B[0m\n");
	else
		ft_putstr("\x1B[31mKO\x1B[0m\n");
	return (0);
}
