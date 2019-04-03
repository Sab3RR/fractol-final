/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:27:51 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/25 17:27:52 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = -1;
	while (*((unsigned char *)s1 + ++i))
		j = -1;
	j = -1;
	while (*((unsigned char *)s2 + ++j) && j < (int)n)
		*((unsigned char *)s1 + i++) = *((unsigned char *)s2 + j);
	*(s1 + i) = '\0';
	return (s1);
}
