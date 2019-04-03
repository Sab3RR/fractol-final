/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:07:26 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/24 15:07:27 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;

	dest = str1;
	src = (char *)str2;
	i = -1;
	while (++i < n)
		*(dest + i) = *(src + i);
	return (str1);
}
