/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:41:30 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:42:53 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		sorted_b(t_stack *a, int n)
{
	int	res;
	int	i;

	i = 0;
	res = 1;
	while (i < a->a_size - 1 && i < n - 1)
	{
		if ((a->a)[i] < (a->a)[i + 1])
			res = 0;
		i++;
	}
	return (res);
}

void	push_a(t_stack *a, t_stack *b, char **commands)
{
	int	i;

	if (b->a_size < 1)
		return ;
	i = a->a_size;
	while (i > 0)
	{
		(a->a)[i] = (a->a)[i - 1];
		i--;
	}
	(a->a)[0] = (b->a)[0];
	(a->a_size)++;
	(b->a_size)--;
	i = -1;
	while (i++ < b->a_size)
		(b->a)[i] = (b->a)[i + 1];
	if (a->flag == 1)
	{
		ft_putstr("pa\n");
		print_stack_a(a);
		ft_putstr("\n");
		print_stack_b(b);
	}
	(*commands) = ft_strjoin(*commands, "pa ");
}

void	push_b(t_stack *a, t_stack *b, char **commands)
{
	int	i;

	if (a->a_size < 1)
		return ;
	i = b->a_size;
	while (i > 0)
	{
		(b->a)[i] = (b->a)[i - 1];
		i--;
	}
	(b->a)[0] = (a->a)[0];
	(b->a_size)++;
	i = -1;
	while (i++ < a->a_size)
		(a->a)[i] = (a->a)[i + 1];
	(a->a_size)--;
	if (a->flag == 1)
	{
		ft_putstr("pb\n");
		print_stack_a(a);
		ft_putstr("\n");
		print_stack_b(b);
	}
	(*commands) = ft_strjoin(*commands, "pb ");
}

void	rotate_a(t_stack *a, t_stack *b, char **commands)
{
	int	i;
	int	tmp;

	if (a->a_size < 1)
		return ;
	i = 0;
	tmp = (a->a)[0];
	while (i < a->a_size - 1)
	{
		(a->a)[i] = (a->a)[i + 1];
		i++;
	}
	(a->a)[a->a_size - 1] = tmp;
	if (a->flag == 1)
	{
		ft_putstr("ra\n");
		print_stack_a(a);
		ft_putstr("\n");
		print_stack_b(b);
	}
	(*commands) = ft_strjoin(*commands, "ra ");
}

void	rotate_b(t_stack *a, t_stack *b, char **commands)
{
	int i;
	int tmp;

	if (a->a_size < 1)
		return ;
	i = 0;
	tmp = (a->a)[0];
	while (i < a->a_size - 1)
	{
		(a->a)[i] = (a->a)[i + 1];
		i++;
	}
	(a->a)[a->a_size - 1] = tmp;
	if (a->flag == 1)
	{
		ft_putstr("rb\n");
		print_stack_a(b);
		ft_putstr("\n");
		print_stack_b(a);
	}
	(*commands) = ft_strjoin(*commands, "rb ");
}
