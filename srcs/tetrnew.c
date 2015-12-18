/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhermoue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:36:58 by fhermoue          #+#    #+#             */
/*   Updated: 2015/12/18 10:52:39 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_tetr	*tetrnew(char **tab)
{
	t_tetr	*tetr;
	int		six;
	int		siy;

	tetr = (t_tetr *)malloc(sizeof(*tetr));
	if (tetr == NULL)
		return (NULL);
	six = 0;
	siy = 0;
	tetr->tab = tab;
	tetr->x = 0;
	tetr->y = 0;
	tetr->pos = 0;
	while (tab[six] && ((tab[six][0] == '.') || (tab[six][0] == '#')))
		six++;
	while (tab[six - 1][siy])
		siy++;
	tetr->sx = six;
	tetr->sy = siy;
	return (tetr);
}
