/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:25:40 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/18 17:02:46 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

void	ft_erase_piece(char **tc, t_tetr *tetri, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->sx)
	{
		j = 0;
		while (j < tetri->sy)
		{
			if (tc[tetri->x + i][tetri->y + j] == 'A' + nb)
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
}

int		check_tetr(char **tc, t_tetr *tab, int i, int j)
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

int		check_size(char **tc, t_tetr *tab, int i, int j)
{
	if (i + tab->sx > (int)ft_strlen(tc[0]) || j + tab->sy > (int)ft_strlen(tc[0]))
		return (0);
	else
		return (1);
}

int		ft_caniplace(char **tc, t_tetr *tab, int i, int j)
{
	if (check_size(tc, tab, i, j) && check_tetr(tc, tab, i, j))
		return (1);
	else
		return (0);
}

int		ft_ft(char **tc, t_tetr **tab, int nb, int nbp, int n)
{
	int	i;
	int j;

	i = 0;
	if (nb == nbp)
		return (1);
	while (i < (int)ft_strlen(tc[0]))
	{
		j = 0;
		while (j < (int)ft_strlen(tc[0]))
		{
			if (ft_caniplace(tc, tab[nb], i, j))
			{
				ft_place(tc, tab[nb], i, j, nb);
				if (ft_ft(tc, tab, nb + 1, nbp, n))
					return (1);
			}
			j++;
		}
		i++;
	}
	if (nb == 0)
	{
		ft_freetab(tc);
		n++;
		tc = ft_init_tab(n);
		ft_ft(tc, tab, 0, nbp, n);
	}
	else
		ft_erase_piece(tc, tab[nb - 1], nb - 1);
	return (0);
}
