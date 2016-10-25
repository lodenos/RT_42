/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 10:13:26 by glodenos          #+#    #+#             */
/*   Updated: 2016/02/28 11:07:26 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	str2[ft_strlen(str)];

	i = -1;
	j = -1;
	while (str[++i] != '\0')
		str2[i] = str[i];
	while (i-- > 0)
		str[++j] = str2[i];
	return (str);
}
