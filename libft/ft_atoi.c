/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:34:09 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/28 18:15:58 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	help(const char *str, int *i, int *flag)
{
	if (str[*i] == '+' && (str[*i + 1] >= '0' && str[*i + 1] <= '9'))
		(*i)++;
	if (str[*i] == '-' && (str[*i + 1] >= '0' && str[*i + 1] <= '9'))
	{
		*flag = -1;
		(*i)++;
	}
}

static void	help2(int flag, long long int n)
{
	if ((n * flag) > 2147483647 || (n * flag) < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

int			ft_atoi(const char *str)
{
	int				i;
	long long int	n;
	int				flag;

	i = 0;
	n = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	help(str, &i, &flag);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	help2(flag, n);
	if (str[i] != '\0')
	{
		write(2, "Error\nOnly one int per argument\n", 32);
		exit(0);
	}
	return ((int)(n * flag));
}
