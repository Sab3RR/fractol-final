/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:10:15 by vsusol            #+#    #+#             */
/*   Updated: 2018/11/06 13:10:19 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	**ret_list(t_list ***list,
					t_list **fd_list, t_list *fd_lst, int fd)
{
	long	i;
	t_list	**lst;

	i = 0;
	while (fd_lst)
	{
		if ((int)fd_lst->content_size == fd)
			return ((*list) + (long)fd_lst->content);
		i++;
		fd_lst = fd_lst->next;
	}
	if (!(lst = malloc((i + 1) * sizeof(t_list*))))
		return (NULL);
	ft_memcpy(lst, *list, i * sizeof(t_list**));
	free(*list);
	*list = lst;
	lst[i] = NULL;
	if (!(fd_lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	fd_lst->content = (void *)i;
	fd_lst->content_size = (size_t)fd;
	fd_lst->next = NULL;
	ft_lstpushback(*fd_list, fd_lst);
	return (lst + i);
}

static t_list	**malloc_list(t_list ***list, t_list **fd_list, int fd)
{
	t_list	*fd_lst;

	if (!*list)
	{
		if (!(list[0] = (t_list **)malloc(sizeof(t_list*)))
			|| (list[0][0] = NULL))
			return (NULL);
	}
	if (!*fd_list)
	{
		if (!(*fd_list = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		(*fd_list)->content = (void *)0;
		(*fd_list)->content_size = (size_t)fd;
		(*fd_list)->next = NULL;
	}
	fd_lst = *fd_list;
	return (ret_list(list, fd_list, fd_lst, fd));
}

static int		create_list(int fd, t_list **list)
{
	char			*str;

	if (!(str = ft_strnew(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	if (((int)read(fd, str, BUFF_SIZE)))
	{
		if (!ft_fill_list(str, list))
			return (0);
	}
	else
	{
		free(str);
		return (0);
	}
	return (1);
}

static int		cheack_fd(int fd, char **line)
{
	if (!line)
		return (0);
	if (fd > 4863)
		return (0);
	if (read(fd, "", 0) == -1)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	***list;
	t_list			**array;

	if (!cheack_fd(fd, line))
		return (-1);
	if (!list)
	{
		if (!(list = (t_list ***)malloc(sizeof(t_list **) * 2)))
			return (0);
		list[0] = NULL;
		if (!(list[1] = (t_list **)malloc(sizeof(t_list *))))
			return (0);
		list[1][0] = NULL;
	}
	if (!(array = malloc_list(list, list[1], fd)))
		return (0);
	if (!*array)
		create_list(fd, array);
	*line = (char *)malloc(sizeof(char));
	**line = '\0';
	if (ft_read_list(line, array, fd, &create_list))
		return (1);
	if (**line)
		return (1);
	return (0);
}
