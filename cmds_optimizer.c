/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_optimizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:16:43 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 17:25:28 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	cmds_optimizer_h10(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (tmp[k + a][0] == '\0' ||
				(tmp[k + a][0] == 'r' && tmp[k + a][1] == 'r' &&
				tmp[k + a][2] == 'a') || ((tmp[k + a][1] == 'a' &&
						(tmp[k + a][0] == 's' || tmp[k + a][0] == 'r')))))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'b')
	{
		(*optimize)++;
		ft_bzero(tmp[k], ft_strlen(tmp[k]));
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h11(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (((tmp[k + a][1] == 'a' && tmp[k + a][0] == 's') ||
					(tmp[k + a][0] == 'r' && tmp[k + a][1] == 'a'))
				|| (tmp[k + a][0] == '\0')))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'r'
			&& tmp[k + a][2] == 'b')
	{
		(*optimize)++;
		tmp[k][0] = 'r';
		tmp[k][1] = 'r';
		tmp[k][2] = 'r';
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h12(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (((tmp[k + a][1] == 'b' && tmp[k + a][0] == 's') ||
					(tmp[k + a][0] == 'r' && tmp[k + a][1] == 'b'))
				|| (tmp[k + a][0] == '\0')))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'r'
			&& tmp[k + a][2] == 'a')
	{
		(*optimize)++;
		tmp[k][0] = 'r';
		tmp[k][1] = 'r';
		tmp[k][2] = 'r';
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h13(char **tmp, int i, int k, int *optimize)
{
	if (tmp[k][0] == 's' && tmp[k][1] == 'b')
		cmds_optimizer_h1(tmp, i, k, optimize);
	if (tmp[k][0] == 's' && tmp[k][1] == 'a')
		cmds_optimizer_h2(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'a')
		cmds_optimizer_h3(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'b')
		cmds_optimizer_h4(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'a')
		cmds_optimizer_h5(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'b')
		cmds_optimizer_h6(tmp, i, k, optimize);
	if (tmp[k][0] == 'p' && tmp[k][1] == 'a')
		cmds_optimizer_h7(tmp, i, k, optimize);
	if (tmp[k][0] == 'p' && tmp[k][1] == 'b')
		cmds_optimizer_h8(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'r' && tmp[k][2] == 'a')
		cmds_optimizer_h9(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'r' && tmp[k][2] == 'b')
		cmds_optimizer_h10(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'r' && tmp[k][2] == 'a')
		cmds_optimizer_h11(tmp, i, k, optimize);
	if (tmp[k][0] == 'r' && tmp[k][1] == 'r' && tmp[k][2] == 'b')
		cmds_optimizer_h12(tmp, i, k, optimize);
}

void	cmds_optimizer(char *str, int flag)
{
	char	**tmp;
	int		i;
	int		k;
	int		optimize;

	tmp = ft_strsplit(str, ' ');
	i = 0;
	while (tmp[i])
		i++;
	k = 0;
	optimize = 1;
	while (optimize != 0)
	{
		optimize = 0;
		while (k < i)
		{
			cmds_optimizer_h13(tmp, i, k, &optimize);
			k++;
		}
	}
	print_zvezda_zvezda(&tmp, i, flag);
}
