/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:29:51 by vsusol            #+#    #+#             */
/*   Updated: 2018/11/16 15:29:54 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fill_list(char *str, t_list **list)
{
	long	end;
	long	start;
	t_list	*new;

	end = 0;
	while (str[end])
	{
		start = end;
		end = ft_findichar(str + start, '\n') + start + 1;
		if (!(new = ft_lstnew((str + start), (size_t)(end - start))))
			return (0);
		if (!list[0])
			list[0] = new;
		else
			ft_lstpushback(list[0], new);
	}
	free(str);
	return (1);
}
