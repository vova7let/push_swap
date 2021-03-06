/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:14:38 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/12 10:17:47 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sort(int *tab, int lenght, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < lenght - 1)
	{
		if (f(tab[i], tab[i + 1] > 0))
			return (0);
		i++;
	}
	return (1);
}
