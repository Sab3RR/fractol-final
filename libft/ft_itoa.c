/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:40:06 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/31 14:40:08 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char *str, unsigned int *i, long n)
{
	if (n < 0)
	{
		str[*i] = '-';
		*i += 1;
		ft_fill(str, i, -n);
	}
	else if (n >= 10)
	{
		ft_fill(str, i, (n / 10));
		ft_fill(str, i, (n % 10));
	}
	else if (n < 10)
	{
		str[*i] = n + '0';
		*i += 1;
	}
}

char		*ft_itoa(int n)
{
	long			nb;
	unsigned int	i;
	char			*str;

	nb = (long)n;
	i = 1;
	while ((nb /= 10))
		i++;
	if (n < 0)
	{
		if (!(str = (char *)malloc(i + 2)))
			return (0);
	}
	else
	{
		if (!(str = (char *)malloc(i + 1)))
			return (0);
	}
	i = 0;
	ft_fill(str, &i, (long)n);
	str[i] = '\0';
	return (str);
}
