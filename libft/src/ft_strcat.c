/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/02 06:26:26 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, char const *src)
{
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = dest;
	tmp_src = (char*)src;
	while (*tmp_dest)
		tmp_dest++;
	while (*tmp_src)
		*tmp_dest++ = *tmp_src++;
	*tmp_dest = '\0';
	return (dest);
}
