//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:12:38 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/03 15:05:53 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

static	void	ft_launch_algo(t_tetr **tab, int nbp[2])
{
	char	**tc;

	tc = ft_init_tab(nbp[0]);
	nbp[1] = nbp[0];
	ft_ft(tc, tab, 0, nbp);
}

static	char	**ft_tetri(char *tmp, int i)
{
	return (ft_clean_tetri3(ft_clean_tetri2(ft_create_dtab(tmp, i))));
}

static	int		ft_loop(int i, char *tmp, t_tetr **tab)
{
	if (ft_create_dtab(tmp, i) != NULL &&
		ft_test_tetri(ft_create_dtab(tmp, i)) > 0)
		tab[i] = tetrnew(ft_tetri(tmp, i));
	else
		return (ft_puterror("error\n"));
	if (!ft_test_tetrimo(tab[i]))
		return (ft_puterror("error\n"));
	return (1);
}

static	int		ft_algo(int i, int nbp[2], char *tmp, t_tetr **tab)
{
	tab = init_tetr_tab(nbp[0]);
	while (++i < nbp[0])
	{
		if (!ft_loop(i, tmp, tab))
			return (0);
	}
	ft_launch_algo(tab, nbp);
	return (1);
}

int				main(int ac, char **av)
{
	char	*tmp;
	t_tetr	**tab;
	int		nbp[2];
	int		i;

	i = -1;
	tab = NULL;
	if (ac != 2)
		return (ft_puterror("error\n"));
	else
	{
		tmp = ft_create_str(av);
		if (tmp && tmp[0] != '\0' && ((nbp[0] = ft_test_str(tmp)) > 0) &&
			ft_line(tmp) != 0 && (nbp[0] < 27))
		{
			if (!ft_algo(i, nbp, tmp, tab))
				return (0);
		}
		else
			return (ft_puterror("error\n"));
	}
	return (0);
}
