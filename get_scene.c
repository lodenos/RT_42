/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 07:43:57 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 16:24:24 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	file_reader(t_env *e, t_list *list)
{
	e->scn.obj = (t_obj*)malloc(sizeof(*e->scn.obj) * (e->scn.n_obj + 1));
	e->scn.spt = (t_spt*)malloc(sizeof(*e->scn.spt) * (e->scn.n_spt + 1));
	while (list)
	{
		if (ft_strstr(list->content, "scene"))
			get_scene(e, list);
		else if (ft_strstr(list->content, "content"))
			get_object(e, list, 0, 0);
		list = list->next;
	}
}

void	del(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list->next;
		ft_memdel(&list->content);
		free(list);
		list = tmp;
	}
}

int		get_file(t_env *e, char *filename)
{
	int		fd;
	char	*line;
	t_list	*list;

	e->scn.n_obj = 0;
	e->scn.n_spt = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	list = (t_list *)malloc(sizeof(t_list));
	list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strstr(line, "object"))
			e->scn.n_obj++;
		if (ft_strstr(line, "spot"))
			e->scn.n_spt++;
		ft_lstpushback(&list, line, ft_strlen(line) + 1);
		free(line);
	}
	if (!list)
		return (0);
	close(fd);
	file_reader(e, list);
	del(list);
	return (1);
}

t_env	*parser(t_env *e, int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("No parameter\n");
		exit(EXIT_FAILURE);
	}
	if (get_file(e, av[1]) == 0)
	{
		ft_putstr("Incorrect parameter\n");
		exit(EXIT_FAILURE);
	}
	return (e);
}
