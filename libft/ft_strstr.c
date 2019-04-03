/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:54:24 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/26 12:54:25 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	i = -1;
	while (++i <= (int)ft_strlen((char *)big))
		if (ft_strncmp((char *)big + i,
			(char *)little, ft_strlen((char *)little)) == 0)
			return ((char *)big + i);
	return (0);
}
