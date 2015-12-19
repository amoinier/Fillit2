/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 11:11:18 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 11:13:44 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	ft_launch_algo(t_tetr **tab, int nbp[2])
{
	char	**tc;

	tc = ft_init_tab(nbp[0]);
	ft_ft(tc, tab, 0, nbp);
	ft_print_tab(tc);
}
