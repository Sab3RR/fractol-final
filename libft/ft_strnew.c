/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:58:27 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/26 17:58:32 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	i = -1;
	while (++i < (int)size + 1)
		*(str + i) = '\0';
	return (str);
}
