/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_ort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:47:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:26:18 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static inline void		filter_parser_sub(char *str, int *i, int *j, int *k)
{
	if ((*k == 0) && str[*i] == '\n')
		str[*i] = ' ';
	if (*j == 1 && str[*i] == '(')
		ft_putstr_err("ERROR: Corrupted File", 1);
	if (*j == 0 && str[*i] == ')')
		ft_putstr_err("ERROR: Corrupted File", 1);
	if (*j == 0 && str[*i] == '(')
		*j = 1;
	if (*j == 1 && str[*i] == ')')
		*j = 0;
	if (*j == 1 && (str[*i] == ' ' || str[*i] == '\t'))
		str[*i] = 126;
}

static inline char		**filter_parser(char *str)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = -1;
	while (str[++i])
	{
		if ((k == 0) && (str[i] == '#'))
		{
			k = 1;
			str[i] = ' ';
		}
		if ((k == 1 && str[i] != '\n') || str[i] == '\t')
			str[i] = ' ';
		if (k == 1 && str[i] == '\n')
		{
			k = 0;
			str[i] = ' ';
		}
		filter_parser_sub(str, &i, &j, &k);
	}
	return (ft_strsplit(str, ' '));
}

static inline void		convert_param_sub(char *str, char *tmp, int *j, int *k)
{
	if (str[*j] == '(' || str[*j] == ')')
		return ;
	if (str[*j] == ',')
	{
		tmp[++*k] = '/';
		return ;
	}
	if (str[*j] == '~')
		return ;
	tmp[++*k] = str[*j];
}

static inline void		convert_param(char **str)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == '(')
		{
			if (!(tmp = ft_memalloc(sizeof(char) * (ft_strlen(str[i]) + 1))))
				ft_putstr_err("ERROR: malloc", 1);
			j = -1;
			k = -1;
			while (str[i][++j])
				convert_param_sub(str[i], tmp, &j, &k);
			free(str[i]);
			str[i] = ft_strdup(tmp);
			free(tmp);
		}
	}
}

void					get_file_ort(t_env *e, char *file)
{
	int		i;
	int		fd;
	char	*tmp;
	char	**swp;

	i = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_putstr_err("The file can not be opened, or no", 1);
	if ((tmp = get_file_raw(fd)) == NULL)
		ft_putstr_err("ERROR File", 1);
	close(fd);
	swp = filter_parser(tmp);
	convert_param(swp);
	get_ort(e, swp);
	free(tmp);
	free_tab((void **)swp);
}
