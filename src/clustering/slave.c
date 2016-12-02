/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 14:25:17 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/09 02:47:02 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT"

void    *slave(void *arg)
{
    int     fds;

    (void)arg;
    if ((fds = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ft_putstr_err("ERROR: Socket fds", 1);
    sck.sin_addr.s_addr = inet_addr(127.0.0.1);
    sck.sin_family = AF_INET;
    sck.sin_port = htons(4297);
    if (connect

    return (NULL);
}
