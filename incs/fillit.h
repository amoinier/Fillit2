/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:31:43 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/18 16:02:40 by amoinier         ###   ########.fr       */
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
	int			pos;
}				t_tetr;

char			*ft_create_str(char **av);
int				ft_test_str(char *str);
char			**ft_create_dtab(char *str, int nbp);
int				ft_test_tetri(char **tab);
t_tetr			*tetrnew(char **tab);
void			ft_modif_tetri(char **tab);
char			**ft_clean_tetri2(char **tab);
char			**ft_clean_tetri3(char **tab);

char			**ft_init_tab(int nbp);
int				ft_ft(char **tc, t_tetr **tab, int nb, int nbp, int n);
void			ft_freetab(char **tab);
int				ft_test_tetrimo(t_tetr *tab);
#endif
