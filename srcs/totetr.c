/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totetr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhermoue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:13:29 by fhermoue          #+#    #+#             */
/*   Updated: 2015/12/10 11:02:10 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

int		getx(char **s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i][j])
	{
		if (s[i][j] == '.')
			j++;
		else if (!s[i][j])
		{
			i++;
			j = 0;
		}
		else
			return (j);
	}
	return (0);
}

int		gety(char **s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i][j])
	{
		if (s[i][j] == '.')
			j++;
		else if (!s[i][j])
		{
			i++;
			j = 0;
		}
		else
			return (i);
	}
	return (0);
}

t_tetr	*totetr(char **tetr)
{
	return (tetrnew(tetr));
}
