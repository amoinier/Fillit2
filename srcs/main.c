/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:12:38 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 11:57:40 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int ac, char **av)
{
	char	*tmp;
	t_tetr	**tab;
	int		nbp[2];
	int		i;

	i = -1;
	if (ac == 2)
	{
		tmp = ft_create_str(av);
		if ((tmp && tmp[0] != '\0'
		&& (nbp[0] = ft_test_str(tmp)) > 0) && (nbp[0] < 27))
		{
			tab = init_tetr_tab(nbp[0]);
			while (++i < nbp[0])
				ft_check_tab(tmp, i, nbp, tab);
			ft_launch_algo(tab, nbp);
		}
		else
			return (ft_puterror("error\n"));
		return (0);
	}
	else
		return (ft_puterror("error\n"));
}
