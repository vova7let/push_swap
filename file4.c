/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:45:30 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:46:49 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		mediana_b(t_stack *a, int n)
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
					&& (a->a)[i] < (a->a)[med_n]))
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

int		sort_3b_h1(t_stack *b, t_stack *a, int n, char **commands)
{
	if (n == 3 && b->a_size == 3)
	{
		if ((b->a)[2] > (b->a)[1] && (b->a)[1] > (b->a)[0])
		{
			swap_b(b, a, commands);
			rev_rotate_b(b, a, commands);
		}
		else if ((b->a)[2] > (b->a)[0] && (b->a)[0] > (b->a)[1])
			rev_rotate_b(b, a, commands);
		else if ((b->a)[1] > (b->a)[2] && (b->a)[2] > (b->a)[0])
			rotate_b(b, a, commands);
		else if ((b->a)[1] > (b->a)[0] && (b->a)[0] > (b->a)[2])
			swap_b(b, a, commands);
		else if ((b->a)[0] > (b->a)[2] && (b->a)[2] > (b->a)[1])
		{
			rev_rotate_b(b, a, commands);
			swap_b(b, a, commands);
		}
		push_a(a, b, commands);
		push_a(a, b, commands);
		push_a(a, b, commands);
		return (1);
	}
	return (0);
}

void	sort_3b_h2(t_stack *b, t_stack *a, char **commands)
{
	if ((b->a)[0] < (b->a)[1])
		swap_b(b, a, commands);
	push_a(a, b, commands);
	push_a(a, b, commands);
}

void	sort_3b_h3(t_stack *b, t_stack *a, char **commands)
{
	push_a(a, b, commands);
	push_a(a, b, commands);
	push_a(a, b, commands);
}

void	sort_3b_h4(t_stack *b, t_stack *a, char **commands)
{
	rotate_b(b, a, commands);
	swap_b(b, a, commands);
	push_a(a, b, commands);
	push_a(a, b, commands);
	rev_rotate_b(b, a, commands);
	push_a(a, b, commands);
}
