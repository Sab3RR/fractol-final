/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:04:14 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/28 18:04:15 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	if (j < 0)
		return ((char *)s);
	while (IS_SPACE(*((char *)s + i)) && i < j + 1)
		i++;
	while (IS_SPACE(*((char *)s + j)) && j >= 0)
		j--;
	if (j - i < 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		return (str);
	}
	if (!(str = ft_strnew(j - i + 1)))
		return (NULL);
	ft_strncpy(str, s + i, j - i + 1);
	return (str);
}
