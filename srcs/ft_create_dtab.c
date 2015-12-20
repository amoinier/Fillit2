/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:40:47 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/20 17:07:18 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

static	int		ft_count_dieze(char **tab)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
				tmp++;
			j++;
		}
		i++;
	}
	if (tmp != 4)
		return (0);
	else
		return (1);
}

static	int		havedie(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

static	int		ft_count_point(char **tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (havedie(tab[i]) == 0)
		{
			if (i > 0 && i < 3)
			{
				if (havedie(tab[i - 1]) == 1 && havedie(tab[i + 1]) == 1)
					return (0);
			}
			if (i > 0 && i < 2)
			{
				if (havedie(tab[i - 1]) == 1 && havedie(tab[i + 2]) == 1)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

char			**ft_create_dtab(char *str, int nbp)
{
	char	*tmp;
	char	**tab;
	int		i;

	i = 0;
	nbp++;
	tmp = (char *)malloc(sizeof(*tmp) * (21 * nbp + 1));
	if (!tmp)
		return (NULL);
	while (i + (21 * (nbp - 1)) < (21 * nbp))
	{
		tmp[i] = str[i + 21 * (nbp - 1)];
		i++;
	}
	tab = ft_strsplit(tmp, '\n');
	if (!ft_count_dieze(tab) || !ft_count_point(tab))
		return (NULL);
	ft_modif_tetri(tab);
	return (tab);
}
