/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:25:40 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/16 20:31:51 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

void	ft_place(char **tc, t_tetr *tetri, int i, int j, int nb)
{
	int	i2;
	int	j2;

	i2 = 0;
	tetri->x = i;
	tetri->y = j;
	while (tetri->tab[i2])
	{
		j2 = 0;
		while (tetri->tab[i2][j2])
		{
			if (tetri->tab[i2][j2] == '#')
				tc[i + i2][j + j2] = 'A' + nb;
			j2++;
		}
		i2++;
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
	if (i + tab->sx > (int)ft_strlen(tc[i]) || j + tab->sy > (int)ft_strlen(tc[i]))
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
	if (nb == 0)
	{
		while (position > (int)ft_strlen(tc[0]))
		{
			position -= ft_strlen(tc[0]);
			i++;
		}
		k = position;
	}
	while (tc[i])
	{
		j = k;
		while (tc[i][j])
		{
			if (check_tetr(tc, tab, i, j) && check_size(tc, tab, i, j))
			{
				ft_place(tc, tab, i, j, nb);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_ft(t_tetr **tab, int nbp, int plus, int position)
{
	int		nb;
	char	**tc;
	char	**tmp;

	nb = 0;
	tc = ft_init_tab(nbp);
	while (nb < plus)
	{
		if (!ft_caniplace(tc, tab[nb], nb, position))
		{
			if (tc[tab[0]->x + tab[0]->sx][tab[0]->y + tab[0]->sy + 1] != '\0' )
			{
				ft_freetab(tc);
				position++;
				ft_ft(tab, nbp, plus, position);
			}
			else
			{
				ft_freetab(tc);
				position = 0;
				nbp++;
				ft_ft(tab, nbp, plus, position);
			}
		}
		nb++;
	}
	return (tc);
}
