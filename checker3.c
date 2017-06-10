/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:23:51 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 18:24:07 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rev_rotate_b1(t_stack *a)
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

void	check_h1(t_stack *a, t_stack *b, char *line)
{
	check_comm(line);
	(ft_strcmp(line, "sa") == 0) ? (swap_a1(a)) : 0;
	(ft_strcmp(line, "sb") == 0) ? (swap_b1(b)) : 0;
	(ft_strcmp(line, "ss") == 0) ? (swap_ab1(a, b)) : 0;
	(ft_strcmp(line, "ra") == 0) ? (rotate_a1(a)) : 0;
	(ft_strcmp(line, "rb") == 0) ? (rotate_b1(b)) : 0;
	(ft_strcmp(line, "rr") == 0) ? (rotate_ab1(a, b)) : 0;
	(ft_strcmp(line, "rra") == 0) ? (rev_rotate_a1(a)) : 0;
	(ft_strcmp(line, "rrb") == 0) ? (rev_rotate_b1(b)) : 0;
	(ft_strcmp(line, "rrr") == 0) ? (rev_rotate_ab1(a, b)) : 0;
	(ft_strcmp(line, "pa") == 0) ? (push_a1(a, b)) : 0;
	(ft_strcmp(line, "pb") == 0) ? (push_b1(a, b)) : 0;
}
