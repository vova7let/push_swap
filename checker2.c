/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:22:23 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 18:23:30 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_b1(t_stack *a, t_stack *b)
{
	int	i;

	if (a->a_size < 1)
		return ;
	i = b->a_size;
	while (i >= 0)
	{
		(b->a)[i + 1] = (b->a)[i];
		i--;
	}
	(b->a)[0] = (a->a)[0];
	(b->a_size)++;
	i = 0;
	while (i < a->a_size)
	{
		(a->a)[i] = (a->a)[i + 1];
		i++;
	}
	(a->a_size)--;
}

void	rotate_a1(t_stack *a)
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
}

void	rotate_b1(t_stack *a)
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
}

void	rotate_ab1(t_stack *a, t_stack *b)
{
	rotate_a1(a);
	rotate_b1(b);
}

void	rev_rotate_a1(t_stack *a)
{
	int	i;
	int	tmp;

	if (a->a_size < 1)
		return ;
	i = a->a_size;
	tmp = (a->a)[a->a_size - 1];
	while (i > 0)
	{
		(a->a)[i] = (a->a)[i - 1];
		i--;
	}
	(a->a)[0] = tmp;
}
