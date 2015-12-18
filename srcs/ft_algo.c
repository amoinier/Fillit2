/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:25:40 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/18 12:10:58 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

void	ft_erase_piece(char **tc, t_tetr *tetri)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->sx)
	{
		j = 0;
		while (j < tetri->sy)
		{
			tc[tetri->x + i][tetri->y + j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_place(char **tc, t_tetr *tetri, int i, int j, int nb)
{
	int	i2;
	int	j2;

	i2 = -1;
	tetri->x = i;
	tetri->y = j;
	while (tetri->tab[++i2])
	{
		j2 = -1;
		while (tetri->tab[i2][++j2])
		{
			if (tetri->tab[i2][j2] == '#')
				tc[i + i2][j + j2] = 'A' + nb;
		}
	}
 	ft_print_tab(tc);
	ft_putchar('\n');
}

int		check_tetr(char **tc, t_tetr *tab, int i, int j)
{
	int	i2;
	int	j2;

	i2 = 0;
	while (i2 < tab->sx && i + i2 < (int)ft_strlen(tc[0]))
	{
		j2 = 0;
		while (j2 < tab->sy && j + j2 < (int)ft_strlen(tc[0]))
		{
			if (tc[i + i2][j + j2] != '.' && tab->tab[i2][j2] != '.')
				return (0);
			j2++;
		}
		i2++;
	}
	return (1);
}

int		check_size(char **tc, t_tetr *tab, int i, int j)
{
	if (i + tab->sx > (int)ft_strlen(tc[0]) || j + tab->sy > (int)ft_strlen(tc[0]))
		return (0);
	else
		return (1);
}

int		ft_caniplace(char **tc, t_tetr *tab, int nb, int position)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	while (position > (int)ft_strlen(tc[0]))
	{
		position -= ft_strlen(tc[0]);
		i++;
	}
	k = (size_t)position;
	j = k;
	while (i < ft_strlen(tc[0]))
	{
		while (j < ft_strlen(tc[0]))
		{
			if (check_tetr(tc, tab, i, j) && check_size(tc, tab, i, j))
			{
				ft_place(tc, tab, i, j, nb);
				return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void	ft_pos0(t_tetr **tab, int nbp)
{
	int	i;

	i = 1;
	while (i < nbp)
	{
		tab[i]->pos = 0;
		i++;
	}
}

char	**ft_ft(char **tc, t_tetr **tab, int nbp, int nb, int plus)
{
	if (!ft_caniplace(tc, tab[nb], nb, tab[nb]->pos))
	{
		if (tab[nb - 1]->x + tab[nb - 1]->sx == (int)ft_strlen(tc[0]) && (int)ft_strlen(tc[0]) == tab[nb - 1]->y + tab[nb - 1]->sy)
		{
			ft_freetab(tc);
			tc = ft_init_tab(nbp);
			tab[0]->pos++;
			ft_pos0(tab, nbp);
			ft_ft(tc, tab, nbp, 0, plus);
		}
		if (tab[0]->x + tab[0]->sx != (int)ft_strlen(tc[0]) || (int)ft_strlen(tc[0]) != tab[0]->y + tab[0]->sy)
		{
			nb--;
			tab[nb]->pos++;
			ft_erase_piece(tc, tab[nb]);
			ft_caniplace(tc, tab[nb], nb, tab[nb]->pos);
		}
		else
		{
			ft_freetab(tc);
			nbp++;
			tc = ft_init_tab(nbp);
			tab[0]->pos = 0;
			ft_ft(tc, tab, nbp, 0, plus);
		}
	}
	//ft_ft(tc, tab, nbp, ++nb, plus);
	return (tc);
}
