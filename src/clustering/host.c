/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 04:50:10 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/08 06:39:03 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void *slave_connection(void *arg)
{
    int     i;
    char    *tmp;

    ft_putendl(inet_ntoa(((t_slv *)arg)->sck.sin_addr));

    i = 1;
    ++((t_slv *)arg)->e->nbr_slv;
    tmp = (char *)ft_memalloc(sizeof(char) * 1025);

    while (1)
    {
        if (read(((t_slv *)arg)->fds, tmp, 1024) < 0)
            break ;
        if (write(((t_slv *)arg)->fds, tmp, ft_strlen(tmp)) < 0)
            break ;
    }

    ft_putendl("Break slave");

    --((t_slv *)arg)->e->nbr_slv;
    free(tmp);
//    close(((t_slv *)arg)->fds);
    free(arg);

//    pthread_cancel(((t_slv *)arg)->pthr);

    ft_putendl("1111111111111");

//    pthread_exit(NULL);
}

/* TODO close le socket proprement  */

void        *host(void *arg)
{
    int         i;
    int         fds;
    int         size;
    sockaddr_in sck;
    t_slv       *slv;

    i = 1;
    ((t_env *)arg)->nbr_slv = 0;
    size = sizeof(sockaddr_in);
    if ((fds = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ft_putstr_err("ERROR: Socket fds", 1);
    sck.sin_addr.s_addr = htonl(INADDR_ANY);
    sck.sin_family = AF_INET;
    sck.sin_port = htons(4297);
    if (bind(fds, (sockaddr *)&sck, sizeof(sck)))
        ft_putstr_err("ERROR: bind", 1);
    if (listen(fds, 10))
        ft_putstr_err("ERROR: listen", 1);
    while (i)
    {
        if (!(slv = (t_slv *)ft_memalloc(sizeof(t_slv))))
            ft_putstr_err("ERROR: Host", 1);
        slv->fds = accept(fds, (sockaddr*)&slv->sck, (socklen_t *)&size);
        slv->e = (t_env *)arg;
        pthread_create(&slv->pthr, NULL, &slave_connection, (void *)slv);
    }
    close(fds);
    pthread_exit(NULL);
}
