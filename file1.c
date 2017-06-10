/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:38:43 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:41:15 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_stack_a(t_stack *a)
{
	int	i;

	i = 0;
	ft_putstr("stack A: ");
	while (i < a->a_size)
	{
		ft_putnbr((a->a)[i]);
		write(1, " ", 1);
		i++;
	}
}

void	print_stack_b(t_stack *a)
{
	int	i;

	i = 0;
	ft_putstr("stack B: ");
	while (i < a->a_size)
	{
		ft_putnbr((a->a)[i]);
		write(1, " ", 1);
		i++;
	}
	ft_putstr("\n");
}

void	swap_a(t_stack *a, t_stack *b, char **commands)
{
	int	tmp;

	if (a->a_size < 2)
		return ;
	tmp = (a->a)[0];
	(a->a)[0] = (a->a)[1];
	(a->a)[1] = tmp;
	if (a->flag == 1)
	{
		ft_putstr("sa\n");
		print_stack_a(a);
		ft_putstr("\n");
		print_stack_b(b);
	}
	(*commands) = ft_strjoin(*commands, "sa ");
}

void	swap_b(t_stack *a, t_stack *b, char **commands)
{
	int	tmp;

	if (a->a_size < 2)
		return ;
	tmp = (a->a)[0];
	(a->a)[0] = (a->a)[1];
	(a->a)[1] = tmp;
	if (a->flag == 1)
	{
		ft_putstr("sb\n");
		print_stack_a(b);
		ft_putstr("\n");
		print_stack_b(a);
	}
	(*commands) = ft_strjoin(*commands, "sb ");
}

int		sorted_a(t_stack *a, int n)
{
	int	res;
	int	i;

	i = 0;
	res = 1;
	while (i < a->a_size - 1 && i < n - 1)
	{
		if ((a->a)[i] > (a->a)[i + 1])
			res = 0;
		i++;
	}
	return (res);
}
