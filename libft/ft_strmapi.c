/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:11:36 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/28 17:11:37 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*((char *)s + ++i))
		*(str + i) = f(i, *((char *)s + i));
	return (str);
}
