/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:22:59 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/29 18:23:11 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*((char *)s + i) != '\0')
	{
		while (*((char *)s + i) == c && *((char *)s + i) != '\0')
			i++;
		while (*((char *)s + i) != c && *((char *)s + i) != '\0')
		{
			i++;
		}
		count++;
	}
	return (count);
}

static void		ft_while(char const *s, char c, int *start, int *end)
{
	*start = *end;
	while (*((char *)s + *start) == c && *((char *)s + *start) != '\0')
		*start += 1;
	*end = *start;
	while (*((char *)s + *end) != c && *((char *)s + *end) != '\0')
		*end += 1;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		start;
	int		end;

	if (!s ||
		!(split = (char **)malloc(sizeof(*split) * ft_countwords(s, c) + 1)))
		return (NULL);
	end = 0;
	start = 0;
	i = 0;
	while (*((char *)s + start) != '\0' && *((char *)s + end) != '\0')
	{
		ft_while(s, c, &start, &end);
		if (*((char *)s + end) != '\0' || *((char *)s + start) != '\0')
		{
			split[i] = ft_strsub(s, start, end - start);
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
