/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:44:59 by vsusol            #+#    #+#             */
/*   Updated: 2018/11/16 15:45:00 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_read_list(char **line, t_list **array,
		int fd, int (*create_list)(int fd, t_list **array))
{
	while (*array)
	{
		*line = ft_strnjoin(*line,
				(char *)(*array)->content, (*array)->content_size);
		if (*(*line + ft_strlen(*line) - 1) == '\n' &&
			!(*(*line + ft_strlen(*line) - 1) = '\0'))
		{
			*array = ft_lstfree(*array);
			return (1);
		}
		*array = ft_lstfree(*array);
		if (create_list(fd, array))
		{
			*line = ft_strnjoin(*line,
					(char *)(*array)->content, (*array)->content_size);
			if (*(*line + ft_strlen(*line) - 1) == '\n' &&
				!(*(*line + ft_strlen(*line) - 1) = '\0'))
				return ((!(*array = ft_lstfree(*array)) || *array) ? 1 : 0);
			*array = ft_lstfree(*array);
			create_list(fd, array);
		}
	}
	return (0);
}
