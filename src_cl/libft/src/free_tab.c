/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:41:31 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 13:53:27 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    free_tab(void **tab)
{
    size_t  i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}
