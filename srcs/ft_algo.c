/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:25:40 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/16 16:51:24 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

char	**ft_init_tab(int nbp)
{
	char	**tab;
	int		size;
	int		i;
	int		j;

	i = 0;
	while ((size = ft_sqrt((nbp) * 4 + i)) == 0)
		i++;
	tab = (char **)malloc(sizeof(tab) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		tab[i] = (char *)malloc(sizeof(char *) * (size + 1));
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_place(char **tc, t_tetr *tetri, int i, int j, int nb)
{
	int	i2;
	int	j2;

	i2 = 0;
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

int		check_line(char **tc, t_tetr *tab, int i, int j)
{
	int	j2;

	j2 = 0;
	while (j2 < tab->sy && j + j2 < (int)ft_strlen(tc[i]))
	{
		if (tc[i][j + j2] != '.')
			return (0);
		j2++;
	}
	return (1);
}

int		check_col(char **tc, t_tetr *tab, int i, int j)
{
	int	i2;

	i2 = 0;
	while (i2 < tab->sx && i + i2 < (int)ft_strlen(tc[i]))
	{
		if (tc[i + i2][j] != '.')
			return (0);
		i2++;
	}
	return (1);
}

int		check_check(char **tc, t_tetr *tab, int i, int j)
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
			if (check_line(tc, tab, i, j) && check_col(tc, tab, i, j) && check_check(tc, tab, i, j))
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

char	**ft_ft(t_tetr **tab, int nbp, int plus)
{
	int		nb;
	char	**tc;
	int		position;

	nb = 0;
	position = 0;
	tc = ft_init_tab(nbp);
	while (tc[ft_strlen(tc[0])][ft_strlen(tc[0])] != 'A')
	{
		while (nb < plus)
		{
			if (!ft_caniplace(tc, tab[nb], nb, position))
			{
				nbp++;
				if (tc[0][0] != 0)
					ft_freetab(tc);
				ft_ft(tab, nbp, plus);
			}
			nb++;
		}
		position++;
	}
	return (tc);
}
