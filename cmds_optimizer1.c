/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_optimizer1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:26:31 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 17:29:38 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_zvezda_zvezda(char ***tmp, int i, int flag)
{
	int k;
	int rules;

	rules = 0;
	k = 0;
	while (k < i)
	{
		if ((*tmp)[k][0] != '\0')
		{
			ft_putstr((*tmp)[k]);
			write(1, "\n", 1);
			rules++;
		}
		free((*tmp)[k]);
		k++;
	}
	if (flag == 1)
		ft_putnbr(rules);
	free(*tmp);
}

void	cmds_optimizer_h1(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (((tmp[k + a][1] == 'b' && (tmp[k + a][0] == 's'
							|| tmp[k + a][0] == 'r')) || (tmp[k + a][0] == 'r'
							&& tmp[k + a][1] == 'r' && tmp[k + a][2] == 'b'))
				|| (tmp[k + a][0] == '\0')))
		a++;
	if (k + a < i && tmp[k + a][0] == 's' && tmp[k + a][1] == 'a')
	{
		(*optimize)++;
		tmp[k][0] = 's';
		tmp[k][1] = 's';
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h2(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (((tmp[k + a][1] == 'a' && (tmp[k + a][0] == 's'
							|| tmp[k + a][0] == 'r')) || (tmp[k + a][0] == 'r'
							&& tmp[k + a][1] == 'r' && tmp[k + a][2] == 'a'))
				|| (tmp[k + a][0] == '\0')))
		a++;
	if (k + a < i && tmp[k + a][0] == 's' && tmp[k + a][1] == 'b')
	{
		(*optimize)++;
		tmp[k][0] = 's';
		tmp[k][1] = 's';
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h3(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (((tmp[k + a][1] == 'a' && tmp[k + a][0] == 's') ||
					(tmp[k + a][0] == 'r' && tmp[k + a][1] == 'r' &&
					tmp[k + a][2] == 'a')) || (tmp[k + a][0] == '\0')))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'b')
	{
		(*optimize)++;
		tmp[k][0] = 'r';
		tmp[k][1] = 'r';
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h4(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (((tmp[k + a][1] == 'b' && tmp[k + a][0] == 's') ||
					(tmp[k + a][0] == 'r' && tmp[k + a][1] == 'r' &&
					tmp[k + a][2] == 'b')) || (tmp[k + a][0] == '\0')))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'a')
	{
		(*optimize)++;
		tmp[k][0] = 'r';
		tmp[k][1] = 'r';
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}
