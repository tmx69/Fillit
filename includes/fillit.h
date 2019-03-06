/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:29:44 by jritchie          #+#    #+#             */
/*   Updated: 2019/01/15 14:30:34 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_tetr
{
	char			**array;
	int				x[4];
	int				y[4];
	int				width;
	int				height;
	char			letter;
	int				map_size;
	struct s_tetr	*next;
	struct s_tetr	*prev;
}					t_tetr;

int					ft_checker(int hash, char *tet);
int					ft_validator(char *tet);
char				*ft_strjoinfree(char **data, char *buf);
t_tetr				*start_valid(int fd, t_tetr *tet);
int					get_min(int *arr);
int					get_max(int *arr);
void				ft_coordinate(t_tetr *head);
t_tetr				*ft_wid_hei_coord(t_tetr *head);
t_tetr				*ft_listnew();
t_tetr				*ft_listadd(t_tetr *trt);
t_tetr				*ft_list_tet(char *tet, int hash);
void				ft_place_tetr(t_tetr *tetra, char **map, int i, int j);
char				**ft_remove_tetr(t_tetr *tetra, char **map, int i, int j);
int					ft_tetris2(t_tetr *tetra, char	**map, int mapsize);
void				ft_tetris(t_tetr *tetra);
char				**ft_freemap(char **map, int size);
int					ft_count_size(char *str);
char				**ft_create_map(t_tetr *tetra, int size);
void				ft_error(void);
void				ft_print_tetris(char **map, int size);
#endif
