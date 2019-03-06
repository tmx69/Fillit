/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:12:29 by jritchie          #+#    #+#             */
/*   Updated: 2019/01/21 16:49:01 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validator(char *tet)
{
	int c;
	int i;
	int hash;
	int j;

	c = 0;
	i = 0;
	j = 0;
	hash = 0;
	while (i < 20)
	{
		if (!(tet[i] == '.' || tet[i] == '#'))
			return (0);
		(tet[i] == '#') && (tet[i + 1]) == '#' ? c++ : 0;
		(tet[i] == '#') && (tet[i + 5] == '#') ? c++ : 0;
		tet[i] == '#' ? hash++ : 0;
		j++;
		i++;
		j == 4 && tet[i] != '\n' ? ft_error() : 0;
		j == 4 ? j = 0 : 0;
		tet[i] == '\n' ? i++ : 0;
	}
	if (!(c == 3 || c == 4))
		ft_error();
	return (hash);
}

int		ft_hash(char *tet)
{
	int hash;

	hash = 0;
	hash = ft_validator(tet);
	if (!(tet[20] == '\0' || tet[20] == '\n'))
		return (0);
	if (hash == 0 || !((hash % 4) == 0))
		return (0);
	return (1);
}

t_tetr	*start_valid(int fd, t_tetr *tet)
{
	char	temp[22];
	int		ret;
	int		i;
	int		row;

	while ((ret = read(fd, temp, 21)) > 0)
	{
		tet->array[0][0] != 0 ? tet = ft_listadd(tet) : 0;
		i = 0;
		temp[ret] = '\0';
		if (!(ft_hash(temp)))
			return (0);
		row = -1;
		while (++row < 4)
		{
			tet->array[row] = ft_strsub(temp, i, 4);
			i = i + 5;
		}
	}
	if (tet->array[0][0] == 0 || temp[20] == '\n')
		ft_error();
	while (tet->prev != NULL)
		tet = tet->prev;
	return (ft_wid_hei_coord(tet));
}
