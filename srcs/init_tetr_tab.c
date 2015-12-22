/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 22:50:27 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/22 23:12:48 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_tetr	**init_tetr_tab(int nb)
{
	int		i;
	t_tetr	**tab;

	i = 0;
	tab = (t_tetr **)malloc(sizeof(t_tetr *) * (nb + 1));
	if (tab == NULL)
		return (NULL);
	while (i != nb)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}
