/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 11:37:51 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 11:46:12 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ft_check_tab(char *tmp, int i, int nbp[2], t_tetr **tab)
{
	if (ft_test_tetri(ft_create_dtab(tmp, i)) > 0 &&
		ft_test_tetrimo(tab[i] = ft_init_tetr(tmp, i)))
	{
		nbp[1] = nbp[0];
		return (1);
	}
	else
		return (ft_puterror("error\n"));
}
