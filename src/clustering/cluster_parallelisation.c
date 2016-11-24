/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_parallelisation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:16:18 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/24 11:47:12 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

char    *clustering_hash_contribution(size_t nbr_elem, size_t nbr_block)
{
    size_t  size;
    char    *tab_work;

    if ((nbr_block > nbr_elem) || (nbr_elem == 0) || (nbr_block == 0))
        return (NULL);
    size = nbr_elem / nbr_block;
    if (nbr_elem % nbr_block)
        ++size;
    if (!(tab_work = (char *)ft_memalloc((size + 1))))
        return (tab_work);
    tab_work[size] = -1;
    return (tab_work);
}

//------------------------------------------------------------------------------

void    cluster_finish_contribution(size_t id, char *tab_work, t_img img,
            unsigned int *img_work, t_mimg mimg)
{
    int     i;

    tab_work[id] = 2;
    i = 0;
    id = 0;
    while (tab_work[id] != -1)
    {
        if (tab_work[id] == 0)
            i = 1;
        ++id;
    }

    //  fusion des bout d'image dans l'image final

    if (i)
        ;   //  info d'arret
}

//------------------------------------------------------------------------------

size_t  cluster_get_contribution(char *tab_work)
{
    size_t  id;

    id = 0;
    while (tab_work[id] != -1)
    {
        if (tab_work[id] == 0)
            return (id);
        ++id;
    }
    ++id;
    return (id);
}

//------------------------------------------------------------------------------

void    cluster_abort_contribution(size_t id, char *tab_work)
{

}
