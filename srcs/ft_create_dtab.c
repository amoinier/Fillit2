/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:40:47 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/10 19:39:46 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

char	**ft_create_dtab(char *str, int nbp)
{
	char	*tmp;
	char	**tab;
	int		i;

	i = 0;
	nbp++;
	tmp = (char *)malloc(sizeof(*tmp) * (21 * nbp + 1));
	if (!tmp)
		return (NULL);
	while (i + (21 * (nbp - 1)) < (21 * nbp))
	{
		tmp[i] = str[i + 21 * (nbp - 1)];
		i++;
	}
	tab = ft_strsplit(tmp, '\n');
	ft_modif_tetri(tab);
	return (tab);
}
