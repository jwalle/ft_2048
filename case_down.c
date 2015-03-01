/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:06 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 23:12:08 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void		fonction_1(t_flag *titi, t_tab *toto, int i, int j)
{
	toto->tab[i + 1][j] *= 2;
	toto->tab[i][j] = 0;
	toto->empty++;
	titi->tmp++;
}

static int		fonction_2(t_flag *titi, t_tab *toto, int i)
{
	int j;
	int flag;

	titi->tmp = 0;
	j = 0;
	flag = 0;
	while (j < 4)
	{
		if (toto->tab[i][j] != 0)
		{
			if (toto->tab[i + 1][j] == 0)
			{
				toto->tab[i + 1][j] = toto->tab[i][j];
				toto->tab[i][j] = 0;
				flag++;
			}
			else if (toto->tab[i + 1][j] == toto->tab[i][j])
			{
				fonction_1(titi, toto, i, j);
				flag++;
			}
		}
		j++;
	}
	return (flag);
}

static int		fonction_3(t_tab *toto, int i)
{
	int j;
	int flag;

	j = 0;
	flag = 0;
	while (j < 4)
	{
		if (toto->tab[i][j] != 0)
		{
			if (toto->tab[i + 1][j] == 0)
			{
				toto->tab[i + 1][j] = toto->tab[i][j];
				toto->tab[i][j] = 0;
				flag++;
			}
		}
		j++;
	}
	return (flag);
}

void			case_down(t_tab *toto)
{
	t_flag	titi;

	set_flags(&titi);
	titi.flag1 = fonction_2(&titi, toto, 2);
	titi.flag_last1 = titi.tmp;
	titi.flag2 = fonction_2(&titi, toto, 1);
	titi.flag_last2 = titi.tmp;
	titi.tmp = 0;
	titi.flag3 = (titi.flag_last1 == 0 && titi.flag_last2 == 0
		? (fonction_2(&titi, toto, 2)) : (fonction_3(toto, 2)));
	titi.flag_last3 = titi.tmp;
	titi.flag4 = fonction_2(&titi, toto, 0);
	titi.flag_last4 = titi.tmp;
	titi.tmp = 0;
	titi.flag5 = ((titi.flag_last2 == 0 && titi.flag_last4 == 0)
		? (fonction_2(&titi, toto, 1)) : (fonction_3(toto, 1)));
	titi.flag_last5 = titi.tmp;
	titi.flag6 = ((titi.flag_last1 == 0 && titi.flag_last2 == 0
		&& titi.flag_last3 == 0 && titi.flag_last5 == 0) ?
		(fonction_2(&titi, toto, 2)) : (fonction_3(toto, 2)));
	if ((titi.flag1 + titi.flag2 + titi.flag3 + titi.flag4 +
		titi.flag5 + titi.flag6) > 0)
		add_random(toto);
}
