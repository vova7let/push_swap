/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:43:05 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:45:14 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rev_rotate_a(t_stack *a, t_stack *b, char **commands)
{
	int	i;
	int	tmp;

	if (a->a_size < 1)
		return ;
	i = a->a_size - 1;
	tmp = (a->a)[a->a_size - 1];
	while (i > 0)
	{
		(a->a)[i] = (a->a)[i - 1];
		i--;
	}
	(a->a)[0] = tmp;
	if (a->flag == 1)
	{
		ft_putstr("rra\n");
		print_stack_a(a);
		ft_putstr("\n");
		print_stack_b(b);
	}
	(*commands) = ft_strjoin(*commands, "rra ");
}

void	rev_rotate_b(t_stack *a, t_stack *b, char **commands)
{
	int	i;
	int	tmp;

	if (a->a_size < 1)
		return ;
	i = a->a_size - 1;
	tmp = (a->a)[a->a_size - 1];
	while (i > 0)
	{
		(a->a)[i] = (a->a)[i - 1];
		i--;
	}
	(a->a)[0] = tmp;
	if (a->flag == 1)
	{
		ft_putstr("rrb\n");
		print_stack_a(b);
		ft_putstr("\n");
		print_stack_b(a);
	}
	(*commands) = ft_strjoin(*commands, "rrb ");
}

void	new_stack(t_stack **a, t_stack **b, char **av, int ac)
{
	int	i;
	int	j;

	(ac < 2) ? (exit(0)) : 0;
	(*a) = (t_stack *)malloc(sizeof(t_stack));
	(*a)->a = (int *)malloc(sizeof(int) * (ac));
	(*b) = (t_stack *)malloc(sizeof(t_stack));
	(*b)->a = (int *)malloc(sizeof(int) * (ac));
	(*a)->flag = 0;
	(*a)->flag2 = 0;
	j = 0;
	if (av[j + 1][0] == '-')
	{
		(av[j + 1][1] == 'v' || av[j + 1][2] == 'v') ? ((*a)->flag = 1) : 0;
		(av[j + 1][1] == 'c' || av[j + 1][2] == 'c') ? ((*a)->flag2 = 1) : 0;
		((*a)->flag == 1 || (*a)->flag == 1) ? (j++) : 0;
	}
	i = 0;
	while (i < ac - 1 - j)
	{
		((*a)->a)[i] = ft_atoi(av[i + 1 + j]);
		i++;
	}
	(*b)->a_size = 0;
	(*a)->a_size = i;
}

void	mediana_h1(int **bolshe, int **menshe, t_stack *a, int n)
{
	int	i;
	int	j;

	i = 0;
	*bolshe = (int *)malloc(sizeof(int) * a->a_size);
	*menshe = (int *)malloc(sizeof(int) * a->a_size);
	while (i < a->a_size && i < n)
	{
		(*bolshe)[i] = 0;
		(*menshe)[i] = 0;
		j = 0;
		while (j < a->a_size && j < n)
		{
			if ((a->a)[i] > (a->a)[j])
				((*bolshe)[i])++;
			else if ((a->a)[i] < (a->a)[j])
				((*menshe)[i])++;
			j++;
		}
		i++;
	}
}

int		mediana(t_stack *a, int n)
{
	int i;
	int *bolshe;
	int *menshe;
	int razn;
	int med_n;

	med_n = 0;
	mediana_h1(&bolshe, &menshe, a, n);
	i = 0;
	razn = (bolshe[i] - menshe[i]) * (bolshe[i] - menshe[i]);
	while (i < a->a_size && i < n)
	{
		if ((bolshe[i] - menshe[i]) * (bolshe[i] - menshe[i]) < razn
				|| ((bolshe[i] - menshe[i]) * (bolshe[i] - menshe[i]) == razn
					&& (a->a)[i] > (a->a)[med_n]))
		{
			med_n = i;
			razn = (bolshe[i] - menshe[i]) * (bolshe[i] - menshe[i]);
		}
		i++;
	}
	free(bolshe);
	free(menshe);
	return (med_n);
}
