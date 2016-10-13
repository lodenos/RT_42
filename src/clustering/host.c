/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 04:50:10 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/10 23:21:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void *slave_connection(int *fds)
{
    int     fd;
    char    *tmp;

    fd = *fds;
    tmp = ft_memalloc(sizeof(char) * 257);

    while (1)
    {
        read(fd, tmp, 256);
    //    write(fd, "Test server :)  -> \n", 20);
    }
    ft_putstr("Client quit\n");
    free(tmp);
    close(fd);
    return (NULL);
}

/* TODO close le socket proprement  */

void        *host(void *arg)
{
    int         fds;
    int         fds_slv;
    t_slv       slv;
    int         size;
    sockaddr_in sck;
    sockaddr_in sck_slv;
    pthread_t   pthr;

    (void)arg;
    if ((fds = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ft_putstr_err("ERROR: Socket fds", 1);
    sck.sin_addr.s_addr = htonl(INADDR_ANY);
    sck.sin_family = AF_INET;
    sck.sin_port = htons(4297);
    if (bind(fds, (sockaddr *)&sck, sizeof(sck)))
        ft_putstr_err("ERROR: bind", 1);
    if (listen(fds, 15))
        ft_putstr_err("ERROR: listen", 1);
    size = sizeof(sck_slv);
    while (1)
    {
        fds_slv = accept(fds, (sockaddr*)&slv.sck, (socklen_t *)&size);
        printf("FD = %d \n", fds_slv);
        pthread_create(&pthr, NULL, &slave_connection, (void *)&fds_slv);
    }
    close(fds);
    pthread_exit(NULL);
}
