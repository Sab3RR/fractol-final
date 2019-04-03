/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:53:15 by vsusol            #+#    #+#             */
/*   Updated: 2018/10/25 16:53:16 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = -1;
	while (*((unsigned char *)s1 + ++i) != '\0')
		j = -1;
	j = -1;
	while (*((unsigned char *)s2 + ++j) != '\0')
		*((unsigned char *)s1 + i++) = *((unsigned char *)s2 + j);
	*(s1 + i) = '\0';
	return (s1);
}
