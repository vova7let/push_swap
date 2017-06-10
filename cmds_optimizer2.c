/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_optimizer2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:29:57 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 17:33:40 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	cmds_optimizer_h5(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (tmp[k + a][0] == '\0' || (tmp[k + a][0] == 'r'
					&& tmp[k + a][1] == 'r' && tmp[k + a][2] == 'b') ||
				((tmp[k + a][1] == 'b' && (tmp[k + a][0] == 's'
								|| tmp[k + a][0] == 'r')))))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'r'
		&& tmp[k + a][2] == 'a')
	{
		(*optimize)++;
		ft_bzero(tmp[k], ft_strlen(tmp[k]));
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h6(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && (tmp[k + a][0] == '\0' || (tmp[k + a][0] == 'r'
					&& tmp[k + a][1] == 'r' && tmp[k + a][2] == 'a') ||
				((tmp[k + a][1] == 'a' && (tmp[k + a][0] == 's'
									|| tmp[k + a][0] == 'r')))))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'r'
			&& tmp[k + a][2] == 'b')
	{
		(*optimize)++;
		ft_bzero(tmp[k], ft_strlen(tmp[k]));
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h7(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && tmp[k + a][0] == '\0')
		a++;
	if (k + a < i && tmp[k + a][0] == 'p' && tmp[k + a][1] == 'b')
	{
		(*optimize)++;
		ft_bzero(tmp[k], ft_strlen(tmp[k]));
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h8(char **tmp, int i, int k, int *optimize)
{
	int a;

	a = 1;
	while (k + a < i && tmp[k + a][0] == '\0')
		a++;
	if (k + a < i && tmp[k + a][0] == 'p' && tmp[k + a][1] == 'a')
	{
		(*optimize)++;
		ft_bzero(tmp[k], ft_strlen(tmp[k]));
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}

void	cmds_optimizer_h9(char **tmp, int i, int k, int *optimize)
{
	int	a;

	a = 1;
	while (k + a < i && (tmp[k + a][0] == '\0' || (tmp[k + a][0] == 'r'
					&& tmp[k + a][1] == 'r' && tmp[k + a][2] == 'b') ||
				((tmp[k + a][1] == 'b' && (tmp[k + a][0] == 's'
									|| tmp[k + a][0] == 'r')))))
		a++;
	if (k + a < i && tmp[k + a][0] == 'r' && tmp[k + a][1] == 'a')
	{
		(*optimize)++;
		ft_bzero(tmp[k], ft_strlen(tmp[k]));
		ft_bzero(tmp[k + a], ft_strlen(tmp[k + a]));
	}
}
