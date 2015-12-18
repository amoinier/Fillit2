/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:47:42 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/18 17:05:11 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

char	**ft_init_tab(int nbp)
{
	char	**tab;
	int		size;
	int		i;
	int		j;

	i = 0;
	while ((size = ft_sqrt((nbp) * 4 + i)) == 0)
		i++;
	if ((tab = (char **)malloc(sizeof(tab) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		tab[i] = (char *)malloc(sizeof(char *) * (size + 1));
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
