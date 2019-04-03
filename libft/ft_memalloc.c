/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:12:52 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/26 16:12:54 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	i = -1;
	while (++i < size)
		*((char *)mem + i) = 0;
	return (mem);
}
