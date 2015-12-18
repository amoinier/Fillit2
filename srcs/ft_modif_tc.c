/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_tc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:29:09 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/18 17:40:37 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

void	ft_erase_piece(char **tc, t_tetr *tetri, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->sx)
	{
		j = 0;
		while (j < tetri->sy)
		{
			if (tc[tetri->x + i][tetri->y + j] == 'A' + nb)
				tc[tetri->x + i][tetri->y + j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_place(char **tc, t_tetr *tetri, int ij[2], int nb)
{
	int	i2;
	int	j2;

	i2 = -1;
	tetri->x = ij[0];
	tetri->y = ij[1];
	while (tetri->tab[++i2])
	{
		j2 = -1;
		while (tetri->tab[i2][++j2])
		{
			if (tetri->tab[i2][j2] == '#')
				tc[ij[0] + i2][ij[1] + j2] = 'A' + nb;
		}
	}
}
