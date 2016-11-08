/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 14:25:17 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/08 06:06:53 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    *slave(void *arg)
{
    int         fds;
    sockaddr_in sck;
    char        *tmp;

    (void)arg;
    if ((fds = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ft_putstr_err("ERROR: Socket fds", 1);
    sck.sin_addr.s_addr = inet_addr("127.0.0.1");
    sck.sin_family = AF_INET;
    sck.sin_port = htons(4297);

    connect(fds, (sockaddr *)&sck, sizeof(sck));

    tmp = (char *)ft_memalloc(sizeof(char) * 1024);
    write(fds, "slave connection PD", 19);
    read(fds, tmp, 19);

    ft_putendl(tmp);

    close(fds);
    pthread_exit(NULL);
}
