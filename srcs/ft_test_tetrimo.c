/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tetrimo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:07:45 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 11:53:49 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

int	ft_test_tetrimo(t_tetr *tab)
{
	int	i;
	int	j;
	int	point;
	int	die;

	i = 0;
	point = 0;
	die = 0;
	while (i < tab->sx)
	{
		j = 0;
		while (j < tab->sy)
		{
			if (tab->tab[i][j] == '.')
				point++;
			if (tab->tab[i][j] == '#')
				die++;
			j++;
		}
		i++;
	}
	if (point > 2 || die != 4)
		return (0);
	else
		return (1);
}
