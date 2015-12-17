/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:07:45 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/17 10:26:57 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_istest3(int i, int j, char **tab, int nbdie)
{
	if(nbdie == 2 || nbdie == 3)
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
	}
	return (1);
}

int	ft_istest4(int i, int j, char **tab, int nbdie)
{
	if (nbdie == 2 || nbdie == 3)
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
	}
	return (1);
}
