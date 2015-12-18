/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:12:38 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/18 17:03:37 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

t_tetr	**init_tetr_tab(int nb)
{
	int		i;
	t_tetr	**tab;

	i = 0;
	tab = (t_tetr **)malloc(sizeof(t_tetr *) * (nb + 1));
	while (i != nb)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

int		main(int ac, char **av)
{
	char	*tmp;
	t_tetr	**tab;
	int		nbp;
	int		i;
	char	**tc;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		tmp = ft_create_str(av);
		if (!tmp || tmp[0] == '\0')
		{
			ft_putstr("Error file");
			return (0);
		}
		if (((nbp = ft_test_str(tmp)) > 0) && (nbp < 27))
		{
			tab = init_tetr_tab(nbp);
			while (i < nbp)
			{				
				if (ft_test_tetri(ft_create_dtab(tmp, i)) > 0)
					tab[i] = tetrnew(ft_clean_tetri3(ft_clean_tetri2(ft_create_dtab(tmp, i))));
				else
				{
					ft_putstr("error\n");
					return (0);
				}
				if (!ft_test_tetrimo(tab[i]))
				{
					ft_putstr("error\n");
					return (0);
				}
				i++;
			}
			tc = ft_init_tab(nbp);
			ft_ft(tc, tab, 0, nbp, nbp);
			ft_print_tab(tc);
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}
