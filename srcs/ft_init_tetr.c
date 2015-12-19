/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tetr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 11:08:05 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/19 11:10:05 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_tetr	*ft_init_tetr(char *tmp, int i)
{
	return (tetrnew(ft_clean_tetri2(ft_create_dtab(tmp, i))));
}
