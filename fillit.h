/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:28:38 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/19 16:56:56 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_data
{
	char	**map;
	int		size;
}				t_data;

typedef struct	s_tlist
{
	char			**tab;
	struct s_tlist	*next;
	struct s_tlist	*prev;
	int				a;
	int				b;
	int				x;
	int				y;
	char			c;
}				t_tlist;

int				get_next_line(int const fd, char **line);
int				ft_check_file(int fd);
void			ft_print_map(t_data *map);
int				ft_print_error(void);
t_tlist			*ft_fill_list(int fd);
int				check_all_tetriminos(t_tlist *list);
int				check_right(char **tab, int i, int j);
int				check_left(char **tab, int i, int j);
int				check_under(char **tab, int i, int j);
t_tlist			*ft_parse_all_tetriminos(t_tlist *list);
void			upper_move(t_tlist **elem);
int				ft_solve(t_tlist **list, int nb_elem);
int				ft_get_square_size(char **tab);
void			ft_filler(t_tlist *elem, t_data *map);
void			ft_defiller(t_tlist *elem, t_data *map);
t_data			*ft_init_tab(int size);
char			ft_check_pos(t_tlist *elem, t_data *map);
void			get_xy(t_tlist *list);

#endif
