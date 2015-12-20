/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:23:32 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/20 17:14:19 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

static	char	*ft_allo_mem(char *tab, int size, char buf)
{
	char	*tab2;
	int		x;

	x = 0;
	tab2 = (char*)malloc(sizeof(*tab2) * (size + 1));
	if (!tab2)
		return (NULL);
	while (x < size)
	{
		tab2[x] = tab[x];
		x++;
	}
	tab2[x] = buf;
	return (tab2);
}

char			*ft_create_str(char **av)
{
	int		fd;
	int		ret;
	int		i;
	char	buf;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(*tmp) * (1 + 1));
	if (!tmp)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, &buf, 1)) && ret != -1)
	{
		tmp = ft_allo_mem(tmp, i, buf);
		i++;
	}
	tmp[i] = '\0';
	close(fd);
	return (tmp);
}
