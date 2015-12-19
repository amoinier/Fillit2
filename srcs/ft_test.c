/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:36:37 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 16:34:29 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

int			ft_ts(char *str)
{
	int	ijk[3];

	ijk[0] = 0;
	ijk[1] = 0;
	ijk[2] = 0;
	while (str[ijk[0]])
	{
		if (str[ijk[0]] != '.' && str[ijk[0]] != '#' &&
			str[ijk[0]] != '\n' && str[ijk[0]] != '\0')
			return (0);
		if (str[ijk[0]] == '\n')
		{
			ijk[2] = 0;
			if (str[ijk[0] - 1] != '\n')
				ijk[1]++;
		}
		if (str[ijk[0]] == '\n' && ijk[2] > 5)
			return (0);
		ijk[0]++;
		ijk[2] = ijk[0];
	}
	if ((ijk[0] - (ijk[1] / 4) + 1) % ijk[1] != 0)
		return (0);
	return (ijk[1] / 4);
}

static	int	ft_istest(int i, int j, char **tab)
{
	if (i == 0 && j == 0)
	{
		if (tab[i + 1][j] != '#' && tab[i][j + 1] != '#')
			return (0);
	}
	if (i == 0 && j < 3 && j > 0)
	{
		if (tab[i][j - 1] != '#' && tab[i][j + 1] != '#' &&
			tab[i + 1][j] != '#')
			return (0);
	}
	if (j == 0 && i < 3 && i > 0)
	{
		if (tab[i - 1][j] != '#' && tab[i + 1][j] != '#' &&
			tab[i][j + 1] != '#')
			return (0);
	}
	return (1);
}

static	int	ft_istest2(int i, int j, char **tab)
{
	if (j > 0 && i > 0 && i < 3 && j < 3)
	{
		if (tab[i - 1][j] != '#' && tab[i + 1][j] != '#' &&
			tab[i][j - 1] != '#' && tab[i][j + 1] != '#')
			return (0);
	}
	if (i == 3 && j > 0 && j < 3)
	{
		if (tab[i - 1][j] != '#' && tab[i][j - 1] != '#' &&
			tab[i][j + 1] != '#')
			return (0);
	}
	if (i == 3 && j == 0)
	{
		if (tab[i - 1][j] != '#' && tab[i][j + 1] != '#')
			return (0);
	}
	if (i == 3 && j == 3)
	{
		if (tab[i - 1][j] != '#' && tab[i][j - 1] != '#')
			return (0);
	}
	return (1);
}

int			ft_test_tetri(char **tab)
{
	int	i;
	int	j;
	int	nbdie;

	i = 0;
	nbdie = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				nbdie++;
				if (nbdie > 4 || !ft_istest2(i, j, tab))
					return (0);
				if (!ft_istest(i, j, tab))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
