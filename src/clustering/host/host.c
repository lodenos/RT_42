/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 04:50:10 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:01 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static void	connect_slave_to_host(void *arg, int fds, int size)
{
	t_slv		*slv;

	if (!(slv = (t_slv *)ft_memalloc(sizeof(t_slv))))
		ft_putstr_err("ERROR: Host", 1);
	if ((slv->fds = accept(fds, (sockaddr*)&slv->sck, (int *)&size))
			== -1)
	{
		free(slv);
		return ;
	}
	slv->e = (t_env *)arg;
	pthread_create(&slv->pthr, NULL, &slave_connection, (void *)slv);
}

void		*host(void *arg)
{
	int			i;
	int			fds;
	int			size;
	sockaddr_in	sck;

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
	if (listen(fds, 512))
		ft_putstr_err("ERROR: listen", 1);
	while (i)
		connect_slave_to_host(arg, fds, size);
	close(fds);
	pthread_exit(NULL);
}
