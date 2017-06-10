/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:50:55 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:51:36 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	in_two_from_b_to_a_h1(t_stack *a, t_stack *b, int **aa, char **commands)
{
	int to_rotate_back;

	to_rotate_back = 0;
	while ((*aa)[1] > 0)
	{
		if ((a->a)[0] > (*aa)[0])
		{
			push_a(b, a, commands);
			(*aa)[1]--;
		}
		else
		{
			to_rotate_back++;
			rotate_b(a, b, commands);
		}
	}
	while (to_rotate_back > 0)
	{
		rev_rotate_b(a, b, commands);
		to_rotate_back--;
	}
}

int		in_two_from_b_to_a(t_stack *a, t_stack *b, int n, char **commands)
{
	int *aa;
	int res;

	in_two_from_b_to_a_h2(a, &aa, n);
	if (n == a->a_size)
	{
		while (aa[1] > 0)
		{
			if ((a->a)[0] > aa[0])
			{
				push_a(b, a, commands);
				(aa[1])--;
			}
			else
				rotate_b(a, b, commands);
		}
		res = aa[3];
		free(aa);
		return (res);
	}
	in_two_from_b_to_a_h1(a, b, &aa, commands);
	res = aa[3];
	free(aa);
	return (res);
}

int		in_two_from_a_to_b_rev(t_stack *a, t_stack *b, int n, char **commands)
{
	int *aa;
	int res;

	in_two_from_a_to_b_h2(a, &aa, n);
	if (n == a->a_size)
	{
		while (aa[1] > 0)
		{
			if ((a->a)[0] < aa[0])
			{
				push_b(a, b, commands);
				(aa[1])--;
			}
			else
				rev_rotate_a(a, b, commands);
		}
		res = aa[3];
		free(aa);
		return (res);
	}
	in_two_from_a_to_b_h1(a, b, &aa, commands);
	res = aa[3];
	free(aa);
	return (res);
}

int		in_two_from_b_to_a_rev(t_stack *a, t_stack *b, int n, char **commands)
{
	int *aa;
	int res;

	in_two_from_b_to_a_h2(a, &aa, n);
	if (n == a->a_size)
	{
		while (aa[1] > 0)
		{
			if ((a->a)[0] > aa[0])
			{
				push_a(b, a, commands);
				(aa[1])--;
			}
			else
				rev_rotate_b(a, b, commands);
		}
		res = aa[3];
		free(aa);
		return (res);
	}
	in_two_from_b_to_a_h1(a, b, &aa, commands);
	res = aa[3];
	free(aa);
	return (res);
}

void	sort_a(t_stack *a, t_stack *b, int n, char **commands)
{
	int push;

	if (sorted_a(a, n) == 1)
		return ;
	if (n > 3)
	{
		push = in_two_from_a_to_b(a, b, n, commands);
		sort_a(a, b, n - push, commands);
		sort_b(a, b, push, commands);
	}
	if (n < 4)
		sort_3a(a, b, n, commands);
}
