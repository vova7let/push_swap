/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:49:10 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 16:49:17 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_3a_h1(t_stack *b, t_stack *a, char **commands)
{
	if ((b->a)[0] < (b->a)[1] && (b->a)[1] < (b->a)[2])
		return ;
	else if ((b->a)[2] < (b->a)[1] && (b->a)[1] < (b->a)[0])
	{
		swap_a(b, a, commands);
		rev_rotate_a(b, a, commands);
	}
	else if ((b->a)[2] < (b->a)[0] && (b->a)[0] < (b->a)[1])
		rev_rotate_a(b, a, commands);
	else if ((b->a)[1] < (b->a)[2] && (b->a)[2] < (b->a)[0])
		rotate_a(b, a, commands);
	else if ((b->a)[1] < (b->a)[0] && (b->a)[0] < (b->a)[2])
		swap_a(b, a, commands);
	else if ((b->a)[0] < (b->a)[2] && (b->a)[2] < (b->a)[1])
	{
		rev_rotate_a(b, a, commands);
		swap_a(b, a, commands);
	}
}

void	sort_3a_h2(t_stack *b, t_stack *a, char **commands)
{
	swap_a(b, a, commands);
	rotate_a(b, a, commands);
	swap_a(b, a, commands);
	rev_rotate_a(b, a, commands);
	swap_a(b, a, commands);
}

void	sort_3a_h3(t_stack *b, t_stack *a, char **commands)
{
	rotate_a(b, a, commands);
	swap_a(b, a, commands);
	rev_rotate_a(b, a, commands);
	swap_a(b, a, commands);
}

void	sort_3a_h4(t_stack *b, t_stack *a, char **commands)
{
	swap_a(b, a, commands);
	rotate_a(b, a, commands);
	swap_a(b, a, commands);
	rev_rotate_a(b, a, commands);
}

void	sort_3a_h5(t_stack *b, t_stack *a, char **commands)
{
	rotate_a(b, a, commands);
	swap_a(b, a, commands);
	rev_rotate_a(b, a, commands);
}
