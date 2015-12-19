/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 10:50:12 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 10:50:34 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_tetr	**init_tetr_tab(int nb)
{
	int		i;
	t_tetr	**tab;

	i = -1;
	if ((tab = (t_tetr **)malloc(sizeof(t_tetr *) * (nb + 1))) == NULL)
		return (NULL);
	while (++i != nb)
		tab[i] = NULL;
	return (tab);
}
