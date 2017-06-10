/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:19:37 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 18:21:30 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_a1(t_stack *a)
{
	int tmp;

	if (a->a_size < 2)
		return ;
	tmp = (a->a)[0];
	(a->a)[0] = (a->a)[1];
	(a->a)[1] = tmp;
}

void	swap_b1(t_stack *a)
{
	int tmp;

	if (a->a_size < 2)
		return ;
	tmp = (a->a)[0];
	(a->a)[0] = (a->a)[1];
	(a->a)[1] = tmp;
}

void	swap_ab1(t_stack *a, t_stack *b)
{
	swap_a1(a);
	swap_b1(b);
}

int		sorted_a1(t_stack *a)
{
	int res;
	int i;

	i = 0;
	res = 1;
	while (i < a->a_size - 1)
	{
		if ((a->a)[i] > (a->a)[i + 1])
			res = 0;
		i++;
	}
	return (res);
}

void	push_a1(t_stack *a, t_stack *b)
{
	int	i;
	int	the_first_b;

	if (b->a_size < 1)
		return ;
	i = a->a_size;
	the_first_b = (b->a)[0];
	while (i >= 0)
	{
		(a->a)[i + 1] = (a->a)[i];
		i--;
	}
	(a->a)[0] = the_first_b;
	(a->a_size)++;
	i = 0;
	(b->a_size)--;
	while (i < b->a_size)
	{
		(b->a)[i] = (b->a)[i + 1];
		i++;
	}
}
