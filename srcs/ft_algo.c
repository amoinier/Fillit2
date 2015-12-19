/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:25:40 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 18:24:41 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	int		check_tetr(char **tc, t_tetr *tab, int i, int j)
{
	int	i2;
	int	j2;

	i2 = 0;
	while (i2 < tab->sx)
	{
		j2 = 0;
		while (j2 < tab->sy)
		{
			if (tc[i + i2][j + j2] != '.' && tab->tab[i2][j2] != '.')
				return (0);
			j2++;
		}
		i2++;
	}
	return (1);
}

static	int		check_size(char **tc, t_tetr *tab, int i, int j)
{
	if (i + tab->sx > (int)ft_strlen(tc[0]) ||
		j + tab->sy > (int)ft_strlen(tc[0]))
		return (0);
	else
		return (1);
}

static	int		ft_caniplace(char **tc, t_tetr *tab, int i, int j)
{
	if (check_size(tc, tab, i, j) && check_tetr(tc, tab, i, j))
		return (1);
	else
		return (0);
}

static	void	newtab(char **tc, t_tetr **tab, int nbp[2])
{
	ft_freetab(tc);
	tc = ft_init_tab(++nbp[1]);
	ft_ft(tc, tab, 0, nbp);
}

static	int		count_point(char **tc)
{
	int	i;
	int	j;
	int	pts;

	i = 0;
	pts = 0;
	while (i < (int)ft_strlen(tc[0]))
	{
		j = 0;
		while (j < (int)ft_strlen(tc[0]))
		{
			if (tc[i][j] == '.')
				pts++;
			j++;
		}
		i++;
	}
	return (pts);
}

int				ft_ft(char **tc, t_tetr **tab, int nb, int nbp[2])
{
	int	ij[2];

	ij[0] = -1;
	if (nb == nbp[0])
		return (1);
	while (++ij[0] < (int)ft_strlen(tc[0]))
	{
		ij[1] = -1;
		while (++ij[1] < (int)ft_strlen(tc[0]))
		{
			if (ft_caniplace(tc, tab[nb], ij[0], ij[1]))
			{
				ft_place(tc, tab[nb], ij, nb);
				if (ft_ft(tc, tab, nb + 1, nbp))
					return (1);
			}
		}
	}
	if (nb == 0 || (count_point(tc) < ((nbp[0] - nb) * 4)))
		newtab(tc, tab, nbp);
	else
		ft_erase_piece(tc, tab[nb - 1], nb - 1);
	return (0);
}
