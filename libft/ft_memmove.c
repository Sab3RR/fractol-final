/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:51:56 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/24 17:51:57 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;

	dest = str1;
	src = (char *)str2;
	i = -1;
	if (src > dest)
		while (++i < n)
			*(dest + i) = *(src + i);
	else
		while ((int)(--n) >= 0)
			*(dest + n) = *(src + n);
	return (str1);
}
