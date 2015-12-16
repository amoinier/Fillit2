/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:31:43 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/16 16:16:01 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct	s_tetr
{
	int			x;
	int			y;
	int			sx;
	int			sy;
	char		**tab;
}				t_tetr;

char			*ft_create_str(char **av);
int				ft_test_str(char *str);
char			**ft_create_dtab(char *str, int nbp);
int				ft_test_tetri(char **tab);
t_tetr			*tetrnew(char **tab);
int				*deplace(t_tetr *t, int x, int y);
int				sq_valid(t_tetr **tab, int limit);
char			**init_tab(int x, int y);
int				place(char **sq, t_tetr *t, int n);
int				sq_size(t_tetr **tab, int limit);
void			place_all(t_tetr **tab);
char			**constr_tab(t_tetr **tab);
void			ft_modif_tetri(char **tab);
char			**ft_clean_tetri2(char **tab);
char			**ft_clean_tetri3(char **tab);
void			put_all(t_tetr **tab);
void			reorganise(t_tetr **tab, int n, int max);
int				organise(t_tetr **tab, int n, int l);

char			**ft_init_tab(int nbp);
char			**ft_ft(t_tetr **tab, int nbp, int plus);
void			ft_freetab(char **tab);

#endif
