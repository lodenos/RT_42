/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 11:42:13 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_of_words(char const *s, char c)
{
	int			i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			++i;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char		*ft_dup_word(char const *s, char c)
{
	char		*word;
	int			len;
	int			i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(word = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (word);
	i = -1;
	while (++i < len)
		word[i] = s[i];
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			nb_of_w;
	int			i;

	nb_of_w = ft_nb_of_words(s, c);
	if (!s || !(tab = (char **)ft_memalloc(sizeof(char *) * (nb_of_w + 1))))
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			tab[++i] = ft_dup_word(s, c);
		while (*s && *s != c)
			s++;
	}
	return (tab);
}
