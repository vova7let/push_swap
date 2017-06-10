/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:49:34 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:50:34 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_3a(t_stack *b, t_stack *a, int n, char **commands)
{
	if (n < 2)
		return ;
	if (n == 2)
	{
		if ((b->a)[0] > (b->a)[1])
			swap_a(b, a, commands);
		return ;
	}
	if (n == 3 && b->a_size == 3)
	{
		sort_3a_h1(b, a, commands);
		return ;
	}
	if ((b->a)[0] < (b->a)[1] && (b->a)[1] < (b->a)[2])
		return ;
	else if ((b->a)[2] < (b->a)[1] && (b->a)[1] < (b->a)[0])
		sort_3a_h2(b, a, commands);
	else if ((b->a)[2] < (b->a)[0] && (b->a)[0] < (b->a)[1])
		sort_3a_h3(b, a, commands);
	else if ((b->a)[1] < (b->a)[2] && (b->a)[2] < (b->a)[0])
		sort_3a_h4(b, a, commands);
	else if ((b->a)[1] < (b->a)[0] && (b->a)[0] < (b->a)[2])
		swap_a(b, a, commands);
	else if ((b->a)[0] < (b->a)[2] && (b->a)[2] < (b->a)[1])
		sort_3a_h5(b, a, commands);
}

void	in_two_from_a_to_b_h1(t_stack *a, t_stack *b, int **aa, char **commands)
{
	int	to_rotate_back;

	to_rotate_back = 0;
	while ((*aa)[1] > 0)
	{
		if ((a->a)[0] < (*aa)[0])
		{
			push_b(a, b, commands);
			(*aa)[1]--;
		}
		else
		{
			to_rotate_back++;
			rotate_a(a, b, commands);
		}
	}
	while (to_rotate_back > 0)
	{
		rev_rotate_a(a, b, commands);
		to_rotate_back--;
	}
}

void	in_two_from_a_to_b_h2(t_stack *a, int **aa, int n)
{
	*aa = (int *)malloc(sizeof(int) * 5);
	(*aa)[1] = 0;
	(*aa)[2] = 0;
	(*aa)[4] = 0;
	(*aa)[0] = (a->a)[mediana(a, n)];
	while ((*aa)[2] < a->a_size && (*aa)[2] < n)
	{
		if ((a->a)[(*aa)[2]] < (*aa)[0])
			((*aa)[1])++;
		((*aa)[2])++;
	}
	(*aa)[3] = (*aa)[1];
}

int		in_two_from_a_to_b(t_stack *a, t_stack *b, int n, char **commands)
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
				rotate_a(a, b, commands);
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

void	in_two_from_b_to_a_h2(t_stack *a, int **aa, int n)
{
	*aa = (int *)malloc(sizeof(int) * 5);
	(*aa)[1] = 0;
	(*aa)[2] = 0;
	(*aa)[4] = 0;
	(*aa)[0] = (a->a)[mediana_b(a, n)];
	while ((*aa)[2] < a->a_size && (*aa)[2] < n)
	{
		if ((a->a)[(*aa)[2]] > (*aa)[0])
			((*aa)[1])++;
		((*aa)[2])++;
	}
	(*aa)[3] = (*aa)[1];
}
