/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_loser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu	  <jbrozzu@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 18:08:35 by jbrozzu           #+#    #+#             */
/*   Updated: 2014/08/17 20:23:25 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		check_loser(t_tab *toto)
{
	int i;
	int j;

	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 3)
		{
			if (toto->tab[i][j] == toto->tab[i][j + 1])
				return (1);
		}
	}
	j = 0;
	while (j++ < 4)
	{
		i = 0;
		while (i++ < 3)
		{
			if (toto->tab[i][j] == toto->tab[i + 1][j])
				return (1);
		}
	}
	return (0);
}