/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:47:09 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:47:20 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_3b_h5(t_stack *b, t_stack *a, char **commands)
{
	push_a(a, b, commands);
	swap_b(b, a, commands);
	push_a(a, b, commands);
	swap_a(a, b, commands);
	push_a(a, b, commands);
}

void	sort_3b_h6(t_stack *b, t_stack *a, char **commands)
{
	swap_b(b, a, commands);
	push_a(a, b, commands);
	swap_b(b, a, commands);
	push_a(a, b, commands);
	push_a(a, b, commands);
}

void	sort_3b_h7(t_stack *b, t_stack *a, char **commands)
{
	swap_b(b, a, commands);
	push_a(a, b, commands);
	push_a(a, b, commands);
	push_a(a, b, commands);
}

void	sort_3b_h8(t_stack *b, t_stack *a, char **commands)
{
	push_a(a, b, commands);
	swap_b(b, a, commands);
	push_a(a, b, commands);
	push_a(a, b, commands);
}

void	sort_3b(t_stack *b, t_stack *a, int n, char **commands)
{
	if (n < 2)
	{
		push_a(a, b, commands);
		return ;
	}
	if (n == 2)
	{
		sort_3b_h2(b, a, commands);
		return ;
	}
	if (sort_3b_h1(b, a, n, commands) == 1)
		return ;
	if ((b->a)[0] > (b->a)[1] && (b->a)[1] > (b->a)[2])
		sort_3b_h3(b, a, commands);
	else if ((b->a)[2] > (b->a)[1] && (b->a)[1] > (b->a)[0])
		sort_3b_h4(b, a, commands);
	else if ((b->a)[2] > (b->a)[0] && (b->a)[0] > (b->a)[1])
		sort_3b_h5(b, a, commands);
	else if ((b->a)[1] > (b->a)[2] && (b->a)[2] > (b->a)[0])
		sort_3b_h6(b, a, commands);
	else if ((b->a)[1] > (b->a)[0] && (b->a)[0] > (b->a)[2])
		sort_3b_h7(b, a, commands);
	else if ((b->a)[0] > (b->a)[2] && (b->a)[2] > (b->a)[1])
		sort_3b_h8(b, a, commands);
}
