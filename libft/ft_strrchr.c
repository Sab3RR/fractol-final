/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:33:20 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/26 12:33:21 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*b;

	b = NULL;
	i = -1;
	while (++i <= (int)ft_strlen(s))
		if (*(s + i) == (unsigned char)c)
			b = (char *)s + i;
	return (b);
}
