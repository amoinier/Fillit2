/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tetrimo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:07:45 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/17 14:09:54 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

int	ft_test_tetrimo(t_tetr *tab)
{
	int	i;
	int	j;
	int	point;

	i = 0;
	point = 0;
	ft_print_tab(tab->tab);
	while (i < tab->sx)
	{
		j = 0;
		while (j < tab->sy)
		{
			if (tab->tab[i][j] == '.')
				point++;
			j++;
		}
		i++;
	}
	if (point > 2)
		return (0);
	else
		return (1);
}
