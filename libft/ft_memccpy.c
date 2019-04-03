/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:27:03 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/25 14:27:04 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *source, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = (size_t)-1;
	ptr = dst;
	while (++i < n)
	{
		*(ptr + i) = *((unsigned char *)source + i);
		if (*((unsigned char *)source + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
