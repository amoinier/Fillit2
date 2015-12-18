/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:55:30 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/18 17:53:46 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

static	void	ft_clean_tetri(char **tab, int tmp)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = tab[i][j + tmp];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
}

int				ft_count_lastpoint(char **tab)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	tmp = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] == '.')
			j++;
		while (tab[i][j] == '#')
			j++;
		if (tmp < j)
			tmp = j;
		i++;
	}
	return (tmp);
}

char			**ft_clean_tetri3(char **tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = ft_count_lastpoint(tab);
	while (tab[i])
	{
		tab[i][tmp] = '\0';
		i++;
	}
	return (tab);
}

char			**ft_clean_tetri2(char **tab)
{
	int		ij[2];
	int		k;
	int		tmp;

	ij[0] = -1;
	k = 0;
	while (++ij[0] < 4)
	{
		ij[1] = -1;
		tmp = 0;
		while (tab[ij[0]][++ij[1]])
		{
			(tab[ij[0]][ij[1]] == '#') ? tmp = 1 : tmp == 0;
		}
		ij[1] = -1;
		if (tmp == 1)
		{
			while (tab[ij[0]][++ij[1]])
				tab[k][ij[1]] = tab[ij[0]][ij[1]];
			tab[k][ij[1]] = '\0';
			k++;
		}
	}
	tab[k] = NULL;
	return (ft_clean_tetri3(tab));
}

void			ft_modif_tetri(char **tab)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	tmp = 4;
	while (i < 4)
	{
		j = 0;
		while (tab[i][j] != '#' && tab[i][j])
			j++;
		if (tmp >= j)
			tmp = j;
		i++;
	}
	ft_clean_tetri(tab, tmp);
}
