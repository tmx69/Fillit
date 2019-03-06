/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:13:21 by jritchie          #+#    #+#             */
/*   Updated: 2019/01/15 15:33:43 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

t_tetr	*ft_listnew(void)
{
	t_tetr *new;

	if (!(new = (t_tetr *)malloc(sizeof(t_tetr))))
		ft_error();
	if (!(new->array = (char **)malloc(sizeof(char *) * 5)))
		ft_error();
	if (!(new->array[0] = ft_strnew(0)))
		ft_error();
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_tetr	*ft_listadd(t_tetr *trt)
{
	t_tetr *buf;
	t_tetr *new;

	new = ft_listnew();
	buf = trt;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = new;
	new->next = NULL;
	new->prev = buf;
	return (new);
}
